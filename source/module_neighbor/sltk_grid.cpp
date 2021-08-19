#include <boost/progress.hpp>

#include "sltk_grid.h"
#include "sltk_atom_input.h"
#include "../src_pw/tools.h"
#include <iostream>
//#include "../src_pw/global.h"
//#define ENABLE_TORCH
#ifdef ENABLE_TORCH
#include <torch/torch.h>
#endif

//=================
// Class AtomLink
//=================
AtomLink::AtomLink(const FAtom &atom, AtomLink* const pointNext)
		: fatom(atom), next_p(pointNext) {}

//==================
// Class CellSet
//==================
CellSet::CellSet()
		: address(NullPtr), length(0)
{
	in_grid[0] = 0;
	in_grid[1] = 0;
	in_grid[2] = 0;
}

//===================
// Class Grid
//===================

//=============
// Static Data
//=============
int Grid::Hash_one_hit = 0;
const double Grid::TOLERATE_ERROR = 1.0E-5;

const boost::hash<int> Grid::INT_HASHER = boost::hash<int>();

const char* const Grid::ERROR[3] =
{
	"Function Grid<Input>::buildCache: exception std::logic_error\n"
	"\tThe max length of input must be a positive number!",
	"Function Grid<Input>::buildCache: exception std::out_of_range\n"
	"\tLogic error! The atom amount is above the maxAmount of input!",
	"Function Grid<Input>::foldHashTable::AtomLinkPointStack::push: exception std::out_of_range\n"
	"\tLogic error! The atom amount in one grid must be less then the value of "
	"MAX_ATOM_IN_ONE_GRID!"
};

Grid::Grid(const int &test_grid_in):test_grid(test_grid_in)
{
//	TITLE("Grid","Grid");
//----------------------------------------------------------
// EXPLAIN : init_cell_flag (use this flag in case memory
// leak)
//----------------------------------------------------------
	init_cell_flag = false;
	this->atomlink = new AtomLink[1];
}

Grid::~Grid()
{
	delete[] atomlink;

}

void Grid::init(
	ofstream &ofs_in,
	const UnitCell &ucell, 
	const Atom_input &input)
{
	TITLE("SLTK_Grid", "init");

	this->setMemberVariables(ofs_in, input);
	this->setAtomLinkArray(ucell, input);
	this->setBoundaryAdjacent(ofs_in, input);

	return;
}

//==========================================================
// MEMBER FUNCTION :
// NAME : setMemberVariables(read in data from Atom_input)
//==========================================================
void Grid::setMemberVariables(
	ofstream &ofs_in, //  output data to ofs
	const Atom_input &input)
{
	TITLE("SLTK_Grid", "setMemberVariables");

	// mohan add 2010-09-05
	AdjacentSet::call_times = 0;

	this->natom = input.getAmount();
	if(test_grid)OUT(ofs_in, "natom", natom);

	this->pbc = input.getBoundary();
	if(test_grid)OUT(ofs_in, "PeriodicBoundary", this->pbc);

	this->sradius = input.getRadius();
	if(test_grid)OUT(ofs_in, "Radius(unit:lat0)", sradius);

	for (int i = 0;i < 3;i++)
	{
		this->vec1[i] = input.vec1[i];
		this->vec2[i] = input.vec2[i];
		this->vec3[i] = input.vec3[i];
	}

	this->lat_now = input.getLatNow();
	if(test_grid)OUT(ofs_in,"lat0(unit:Bohr)", lat_now);

	this->expand_flag = input.getExpandFlag();
	if(test_grid)OUT(ofs_in,"Expand_flag", expand_flag);
	
	// output vector
	if(test_grid)OUT(ofs_in,"Vec1",vec1[0],vec1[1],vec1[2]);
	if(test_grid)OUT(ofs_in,"Vec2",vec2[0],vec2[1],vec2[2]);
	if(test_grid)OUT(ofs_in,"Vec3",vec3[0],vec3[1],vec3[2]);

	// output grid length
	this->grid_length[0] = input.Clength0();
	this->grid_length[1] = input.Clength1();
	this->grid_length[2] = input.Clength2();

	if(test_grid)OUT(ofs_in,"Grid_length",grid_length[0],grid_length[1],grid_length[2]);
//----------------------------------------------------------
// EXPLAIN : (d_minX,d_minY,d_minZ)minimal value of
// x[] ,y[] , z[]
//----------------------------------------------------------
	this->d_minX = input.minX();
	this->d_minY = input.minY();
	this->d_minZ = input.minZ();
	if(test_grid)OUT(ofs_in,"MinCoordinate",d_minX,d_minY,d_minZ);
//----------------------------------------------------------
//layer: grid layer after expand
//----------------------------------------------------------
	this->cell_x_length = input.getCellXLength();
	this->cell_y_length = input.getCellYLength();
	this->cell_z_length = input.getCellZLength();
	if(test_grid)OUT(ofs_in,"CellLength(unit: lat0)",cell_x_length,cell_y_length,cell_z_length);
//----------------------------------------------------------
// set dx, dy, dz
//----------------------------------------------------------
	this->dx = input.getCellX();
	this->dy = input.getCellY();
	this->dz = input.getCellZ();
	if(test_grid)OUT(ofs_in,"CellNumber",dx,dy,dz);

	Cell = new CellSet**[dx];
	for (int i = 0;i < dx;i++)
	{
		Cell[i] = new CellSet*[dy];

		for (int j = 0;j < dy;j++)
		{
			Cell[i][j] = new CellSet[dz];

			for (int k = 0;k < dz;k++)
			{
				Cell[i][j][k].length = 0;
			}
		}
	}
	this->init_cell_flag = true;

	return;
}

void Grid::setAtomLinkArray(const UnitCell &ucell, const Atom_input &input)
{
//----------------------------------------------------------
// CALL MEMBER FUNCTION :
// NAME : Bulid_Cache
//----------------------------------------------------------
	AtomLink* const pointCache = this->Build_Cache(ucell, input);
//----------------------------------------------------------
// WARNING : Don't delete this testing code.
//----------------------------------------------------------
	/*
		if(natom<100)
		{
			ofs_running<<"\n Print Cache Atoms : "<<natom;
			ofs_running<<"\n"<<setw(12)<<"X"<<setw(12)<<"Y"<<setw(12)<<"Z";
			for(int i=0;i<natom;i++)
			{
				cout<<"\n"<<setw(6)<<i
				<<setw(12)<<pointCache[i].fatom.x()
				<<setw(12)<<pointCache[i].fatom.y()
				<<setw(12)<<pointCache[i].fatom.z()
				<<setw(12)<<pointCache[i].fatom.getType()
				<<setw(12)<<pointCache[i].fatom.getNatom();
			}
		}
	*/

//	if (test_grid) DONE(ofs_running, "Build_Cache");

//----------------------------------------------------------
// CALL MEMBER FUNCTION :
// NAME : Bulid_Cache
//----------------------------------------------------------
	this->Build_Cell();

//	if (test_grid) DONE(ofs_running, "Build_Cell");

	this->Build_Hash_Table(ucell, pointCache);

//	if (test_grid) DONE(ofs_running, "Build_Hash_Table");

//----------------------------------------------------------
// WARNING : Don't Deleete this testing code.
//----------------------------------------------------------
//	ofs_running<<"\n Before Fold : atomlink:";
//	int find_conflict = 0;
//    for(int i=0;i<natom;i++)
//    {
//        ofs_running<<"\n"<<setw(6)<<i
//        <<setw(12)<<atomlink[i].fatom.x()
//        <<setw(12)<<atomlink[i].fatom.y()
//        <<setw(12)<<atomlink[i].fatom.z();
//        if(atomlink[i].next_p != cordon_p && atomlink[i].next_p != NullPtr)
//        {
//      	ofs_running<<"\n Hash Link Array : ";
//            AtomLink* temp = &atomlink[i];
//            for(;temp->next_p != NullPtr; temp = temp->next_p)
//          {
//				find_conflict++;
//				ofs_running<<"\n"<<setw(12)<<temp->fatom.x()
//				<<setw(12)<<temp->fatom.y()
//				<<setw(12)<<temp->fatom.z();
//           }
//		}
//  }
//	ofs_running<<"\n find_conflict = "<<find_conflict;

	this->Fold_Hash_Table();

//	if (test_grid) DONE(ofs_running, "Fold_Hash_Table");

//----------------------------------------------------------
// EXPLAIN : Don't Deleete this testing code.
//----------------------------------------------------------
//    for(int i=0;i<natom;i++)
//  {
//        ofs_running<<"\n"<<setw(6)<<i
//        <<setw(12)<<atomlink[i].fatom.x()
//        <<setw(12)<<atomlink[i].fatom.y()
//        <<setw(12)<<atomlink[i].fatom.z();
//  }
	delete[] pointCache;

	return;
}

void Grid::setBoundaryAdjacent(
	ofstream &ofs_in,
	const Atom_input &input)
{
	if (test_grid) TITLE(ofs_in, "Grid", "setBoundaryAdjacent");

	if (expand_flag)
	{
		const int i = input.getGrid_layerX_minus();
		const int j = input.getGrid_layerY_minus();
		const int k = input.getGrid_layerZ_minus();
		this->Construct_Adjacent_expand(i, j, k);
	}
	else
	{
		this->Construct_Adjacent_begin();
	}

	if(test_grid)OUT(ofs_in,"Adjacent_set call times",AdjacentSet::call_times);

	if (!expand_flag)
	{
		//xiaohui add 'OUT_LEVEL' line, 2015-09-16
		//if(OUT_LEVEL != "m") OUT(ofs_in,"average adjacent (per atom)",

// mohan comment out 2021-06-22
//		if(OUT_LEVEL != "m") OUT(ofs_in,"average adjacent (per atom)",
//		static_cast<double>(AdjacentSet::call_times)
//		/ static_cast<double>(this->natom));
	}
	else
	{
//		if(OUT_LEVEL != "m") OUT(ofs_in,"average adjacent (per atom)",
//		static_cast<double>(AdjacentSet::call_times)
//		/ static_cast<double>(Cell[0][0][0].length));
	}

	Memory::record("AdjacentSet", "offset", AdjacentSet::call_times, "short");
	Memory::record("AdjacentSet", "box", AdjacentSet::call_times, "short");

	//if (test_grid)DONE(ofs_in, "Construct_Adjacent");

	return;
}

bool Grid::Push(const UnitCell &ucell, const FAtom &atom)
{
	//=======================================================
	// sradius is cell radius.
	// atom.x ,atom.y, atom.z  is atom position , respectly.
	// d_minX ,d_minY, d_minZ  is origin of cell_0.
	//=======================================================
	int a=0;
	int b=0;
	int c=0; //mohan update 2021-06-22
	this->In_Which_Cell(ucell, a, b, c, atom);

//	if(test_grid) ofs_running << setw(5) << a << setw(5) << b << setw(5) << c;
	
	//======================================================
	// dx, dy, dz is max cell in each direction ,respectly.
	//======================================================
	if (a < dx && a >= 0 && b < dy && b >= 0 && c < dz && c >= 0)
	{
		++ this->Cell[a][b][c].length;
//		if(test_grid) ofs_running << setw(10) << this->Cell[a][b][c].length << endl;
		return true;
	}
	else
	{
//		if(test_grid) ofs_running << setw(10) << " no cell in" << endl; 
		return false;
	}
}


AtomLink* Grid::Build_Cache(const UnitCell &ucell, const Atom_input &input)
{
//	if (test_grid)TITLE(ofs_running, "Grid", "Build_Cache");
	AtomLink* const start = new AtomLink[natom+1];
	Memory::record("grid", "AtomLink", natom, "AtomLink");

	// the pointer stay at the end of atom.
	//const AtomLink* const end = start + natom + 1;

	AtomLink* current = start;

//	if(test_grid) ofs_running << " total atom number is " << natom << endl;
	for (int i = 0;i < natom;i++)
	{
//----------------------------------------------------------
// CALL OTHER CLASS FUNCTION :
// NAME : set_FAtom
//
// CALL MEMBER FUNCTION :
// NAME : Push
//----------------------------------------------------------
		input.set_FAtom(ucell, current->fatom);	//caoyu modified 2021/5/24

		// input parameter: the Fatom class of AtomLink class.
		// use atom information to check which cell in.
		if (this->Push(ucell, current->fatom))
		{
			++current;
		}
	}
	return start;
}

void Grid::Build_Cell(void)
{
	TITLE("SLTK_Grid", "Build_Cell");

	delete[] this->atomlink;
	this->atomlink = new AtomLink[this->natom];

	// cordon_p : the pointer to the end of atom
	this->cordon_p = this->atomlink + this->natom;

	AtomLink* cellAddress = this->atomlink;

//	if (test_grid)ofs_running << " Cell_length(number of atoms) " << endl;

	for (int i = 0; i < this->dx; ++i)
	{
		for (int j = 0; j < this->dy; ++j)
		{
			for (int k = 0; k < this->dz; ++k)
			{
				//type of address is AtomLink
				Cell[i][j][k].address = cellAddress;
				cellAddress += Cell[i][j][k].length;

				if (test_grid)
				{
/*
					ofs_running << setw(6) << i 
					<< setw(6) << j 
					<< setw(6) << k
					<< setw(10) << Cell[i][j][k].length << endl;
*/
				}
			}
		}
	}

	return;
}

void Grid::In_Which_Cell(const UnitCell &ucell, int &a, int &b, int &c, const FAtom &atom)const
{
	if (expand_flag)
	{
//----------------------------------------------------------
// EXPLAIN : In expand grid case,
// the input cell is exactly the same as input file.
// So it's not a cubic, we must change each atom to
// direct coordinate to find which cell the atom in.
//
// we use vec1,vec2,vec3 to change the cartesian coordinate
// to direct coordinate,and use
// cell_x_length = |vec1|
// cell_y_length = |vec2|
// cell_z_length = |vec3|
// to calculate the atom in cell(a,b,c)
// A bug remain!
// d_minX, d_minY, d_minZ must be the cell origin
//----------------------------------------------------------
		double directx, directy, directz;
		Mathzone::Cartesian_to_Direct(
		    atom.x(), atom.y(), atom.z(),
		    vec1[0], vec1[1], vec1[2],
		    vec2[0], vec2[1], vec2[2],
		    vec3[0], vec3[1], vec3[2],
		    directx, directy, directz);
	
		// cell_x_length
		// mohan add the 'save_add' 2011-03-12
		// for example, if a is 2.999999999999999999, the int command
		// will make a = 2 (in fact we want 3)
		// if a is 3.00000000000000001, it's save.
		//static double save_add = 1.0e-15; // from -8 to -15, mohan add 2012-03-22
		//a = static_cast<int>( (directx - this->d_minX) + save_add );
		//b = static_cast<int>( (directy - this->d_minY) + save_add );
		//c = static_cast<int>( (directz - this->d_minZ) + save_add );
		int now_type = atom.getType();
		int now_number = atom.getNatom();
		double now_x_d = ucell.atoms[now_type].taud[now_number].x;
		double now_y_d = ucell.atoms[now_type].taud[now_number].y;
		double now_z_d = ucell.atoms[now_type].taud[now_number].z;
		a = static_cast<int>(directx - now_x_d - this->d_minX + 0.5 );
                b = static_cast<int>(directy - now_y_d - this->d_minY + 0.5 );
                c = static_cast<int>(directz - now_z_d - this->d_minZ + 0.5 );

		//ofs_running << setw(8) << atom.x() << setw(8) << atom.y() << setw(8) << atom.z()
		//<< setw(12) << directx << setw(12) << directy << setw(12) << directz
		//<< setw(6) << a << setw(6) << b << setw(6) << c << endl;
	
	/*	
		if(a==0 && b==4 && c==0)
		{
			cout << setprecision(25) << endl;
			cout << " save_add=" << save_add << endl;
			cout << atom.x() << " " << atom.y() << " " << atom.z() << endl;
			cout << " directy=" << directy << " d_minX=" << d_minY << " b=" << b << endl;
			cout << " (int)directy=" << (int)directy << " (int)d_minY=" << (int)d_minY << " static_cast<int>( (directx - this->d_minX) )=" << static_cast<int>( (directy - this->d_minY) ) << endl;
			cout << endl;
			int ok;
			cin >> ok;
		}
		*/
	}
	else
	{
//----------------------------------------------------------
// EXPLAIN : Not expand case , the cell is 'cubic',
// the three dimension length :
// cell_x_length = |radius|
// cell_y_length = |radius|
// cell_z_length = |radius|
//
// So we don't need crystal coordinate to locate the atom.
// We use cartesian coordinate directly.
//----------------------------------------------------------
		a = static_cast<int>(std::floor((atom.x() - this->d_minX) / this->cell_x_length));
		b = static_cast<int>(std::floor((atom.y() - this->d_minY) / this->cell_y_length));
		c = static_cast<int>(std::floor((atom.z() - this->d_minZ) / this->cell_z_length));

		/*
		cout<<"\n"<<setw(12)<<atom.x()
		<<setw(12)<<atom.y()
		<<setw(12)<<atom.z()
		<<setw(6)<<a
		<<setw(6)<<b
		<<setw(6)<<c
		<<setw(12)<<d_minX
		<<setw(12)<<d_minY
		<<setw(12)<<d_minZ;
		*/
	}

	return;
}

AtomLink* Grid::getHashCode(const UnitCell &ucell, const FAtom& atom)const
{
	int a, b, c;
	this->In_Which_Cell(ucell, a, b, c, atom);
	return this->Cell[a][b][c].address +
	       (INT_HASHER(  static_cast<int>(atom.x() / TOLERATE_ERROR)
	                   + static_cast<int>(atom.y() / TOLERATE_ERROR)
	                   - static_cast<int>(atom.z() / TOLERATE_ERROR))
	        % this->Cell[a][b][c].length);
}


void Grid::Build_Hash_Table(const UnitCell &ucell, AtomLink* const pointCache)
{
	TITLE("SLTK_Grid", "Build_Hash_Table");

	AtomLink* current = pointCache;

	const AtomLink* const end = pointCache + this->natom;

	Hash_one_hit = 0; // mohan add 2010-06-25
	for (; current < end; ++ current)
	{
		AtomLink* const hashTarget = this->getHashCode(ucell, current->fatom);

		//================================================
		// Find a new position
		//================================================
		if (hashTarget->next_p == NullPtr)
		{
			Hash_one_hit++;
			hashTarget->fatom = current->fatom;
			hashTarget->next_p = this->cordon_p;
		}

		//=================================================
		// already has a atom at this harshTarget position
		//=================================================
		else if (hashTarget->next_p == this->cordon_p)
		{
			hashTarget->next_p = current;
		}

		//=================================================
		// already has more than one atom at this position,
		// it's a 'chain' now , then searching to the end
		//=================================================
		else
		{
			//===========================
			// a new 'moving' Link
			//===========================
			AtomLink* ptr = hashTarget->next_p;

			while (ptr->next_p != NullPtr)
			{
				ptr = ptr->next_p;
			}

			ptr->next_p = current;
		}
	}

//	if(test_grid)OUT(ofs_running,"Hash one hit number",Hash_one_hit);
//	if(test_grid)OUT(ofs_running,"One hit on target percentage(%)",static_cast<double>(Hash_one_hit) / static_cast<double>(natom)*100);
	return;
}

void Grid::Fold_Hash_Table()
{
	TITLE("SLTK_Grid", "Fold_Hash_Table");

	struct AtomLinkPointStack
	{
		//=======
		// Data
		//=======
		AtomLink** tmp;
		int top;
		//=============================
		// Constructors and destructor
		//=============================
		AtomLinkPointStack(const int Natom): top(-1)
		{
			tmp = new AtomLink*[Natom];
		}

		~AtomLinkPointStack()
		{
			delete[] tmp;
		}

		//===============
		// Manipulators
		//===============
		void push(AtomLink* const ptr)
		{
			tmp[++top] = ptr;
		}

		AtomLink* pop()		// Peize Lin delete const 2019-05-01
		{
			assert(top > -1);
			return tmp[top--];
		}
	}availableSpace(this->natom);


	for (int i = 0; i < dx; ++i)
	{
		for (int j = 0; j < dy; ++j)
		{
			for (int k = 0; k < dz; ++k)
			{
				AtomLink* current = this->Cell[i][j][k].address;
				//			ofs_running<<"\n i = "<<i<<" j = "<<j<<" k = "<<k
				//			<<"\n length = "<<this->Cell[i][j][k].length<<endl;
				const AtomLink* const end = current + this->Cell[i][j][k].length;

				bool *push_i = new bool[Cell[i][j][k].length] ;
				int count_i = 0;

				for (; current < end; ++ current)
				{
					if (current->next_p == NullPtr)
					{
						availableSpace.push(current);
						push_i[count_i] = true;
					}
					else
					{
						push_i[count_i] = false;
					}
					count_i++;
				}

				//================
				// reset current!
				//================
				current = this->Cell[i][j][k].address;

				count_i = 0;

				for (; current < end; ++ current)
				{
					if (push_i[count_i] == true)
					{
						//============================
						// The push_i position didn't
						// need to check
						// this->cordon_p or null
						//============================
						// do nothing
					}
					else
					{
						//=====================================
						// deal with the position has confilct
						//=====================================
						if ((current->next_p != this->cordon_p && current->next_p != NullPtr))
						{
							AtomLink* cur = current;
							AtomLink* aux = current;

							while (aux->next_p != NullPtr)
							{
								AtomLink* const space = availableSpace.pop();

								//=============================
								// change aux
								// searching for the next_p atom
								//=============================
								aux = aux->next_p;

								//================================
								// Copy atom information to space
								//================================
								space->fatom = aux->fatom;

								const int pos0 = cur - atomlink;
								atomlink[pos0].next_p = space;

								//=======================================
								// Change cur(Only need address in fact)
								//=======================================
								cur = space;

							}

							//============================================================
							// cur : the last one has conflict.
							// Calculate the distance from cur and the start position of
							// Cell ==> atomlink
							//============================================================
							const int pos = cur - atomlink;

							//=====================================================
							// Then change the pointer of
							// array atomlink (The last one has conflict)
							//=====================================================
							atomlink[pos].next_p = this->cordon_p;

						}//end conflict
					}//end push_i

					count_i++;
				}//end searching in this cell

				delete[] push_i;
			}//k
		}//j
	}//i

	return;
}

void Grid::Construct_Adjacent_expand(
	const int true_i, 
	const int true_j, 
	const int true_k)
{
//	if (test_grid)TITLE(ofs_running, "Grid", "Construct_Adjacent_expand");

//----------------------------------------------------------
// EXPlAIN : In expand grid case, use
// AdjacentSet::index_expand() to record the grid number,
// We use formula (i*dy*dz + j*dz + k) to store the
// displacement of cell.
// Of course , an alternative operatiion is to store the
// (i,j,k),but we want to use memory as small as possible
// for this storage.
//----------------------------------------------------------
	AdjacentSet::setExpandFlag(this->expand_flag);

	AdjacentSet::setDx(this->dx);

	AdjacentSet::setDy(this->dy);

	AdjacentSet::setDz(this->dz);

	// mohan add 2009-10-20
	AdjacentSet::setTrueX(true_i);
	
	AdjacentSet::setTrueY(true_j);
	
	AdjacentSet::setTrueZ(true_k);
	

	AdjacentSet::setCenter(true_i * dy * dz + true_j * dz + true_k);
	

//	if(test_grid)OUT(ofs_running,"GridCenter",true_i,true_j,true_k);
//	if(test_grid)OUT(ofs_running,"GridDim",dx,dy,dz);

//-----------------------------------------------------------
// EXPLAIN : (true_i,true_j,true_k) is the cell we want
// to found AdjacentSet.And other cell save the displacement
// of center_grid in 'in_grid'
//-----------------------------------------------------------
	for (int i = 0;i < this->dx;i++)
	{
		for (int j = 0;j < this->dy;j++)
		{
			for (int k = 0;k < this->dz;k++)
			{
				this->Cell[i][j][k].in_grid[0] = i - true_i;
				this->Cell[i][j][k].in_grid[1] = j - true_j;
				this->Cell[i][j][k].in_grid[2] = k - true_k;
			}
		}
	}

//----------------------------------------------------------
// EXPLAIN : Only construct AdjacentSet for 'true' cell.
//----------------------------------------------------------
	//for (int ia = 0;ia < Cell[true_i][true_j][true_k].length;ia++)
#ifdef ENABLE_TORCH
	Construct_Adjacent_expand_periodic_by_torch(true_i, true_j, true_k);
#else
	int ia_range = Cell[true_i][true_j][true_k].length;
	boost::progress_display show_progress(ia_range);
	for (int ia = 0; ia < ia_range; ++ia)
	{
		Cell[true_i][true_j][true_k].address[ia].fatom.allocate_AdjacentSet();

		std::cout << Cell[true_i][true_j][true_k].address[ia].fatom.getAdjacentSet()->idx << "\n";

		if (this->pbc)
		{
			Construct_Adjacent_expand_periodic(true_i, true_j, true_k, ia);
		}
		else
		{
			WARNING_QUIT("Construct_Adjacent_expand", "\n Expand case, must use periodic boundary.");
		}
		++show_progress;
	}
#endif
	return;
}

#ifdef ENABLE_TORCH
	void Grid::Construct_Adjacent_expand_periodic_by_torch(const int true_i, const int true_j, const int true_k) {
		uint64_t const cell_count{this->dx * this->dy * this->dz};

		int true_ia_range = this->Cell[true_i][true_j][true_k].length;
		for (int true_ia = 0; true_ia < true_ia_range; ++true_ia) {
			this->Cell[true_i][true_j][true_k]
				.address[true_ia]
				.fatom.allocate_AdjacentSet();
		}

		std::cout << "Preparing data..." << std::endl;
		auto x = torch::empty({true_ia_range}, at::kDouble);
		auto y = torch::empty({true_ia_range}, at::kDouble);
		auto z = torch::empty({true_ia_range}, at::kDouble);
		{
			for (int64_t ia{0}; ia < true_ia_range; ++ia) {
				x[ia] = this->Cell[true_i][true_j][true_k].address[ia].fatom.x();
				y[ia] = this->Cell[true_i][true_j][true_k].address[ia].fatom.y();
				z[ia] = this->Cell[true_i][true_j][true_k].address[ia].fatom.z();
			}
		}
		auto cell_offset = torch::empty({cell_count + 1}, at::kLong);
				{
			int64_t current_offset{0U};
			int64_t cell_idx{0U};
			for (int i{0}; i < this->dx; i++) {
				for (int j{0}; j < this->dy; j++) {
					for (int k{0}; k < this->dz; k++) {
						cell_offset[cell_idx] = current_offset;
						++cell_idx;
						current_offset += this->Cell[i][j][k].length;

					}
				}
			}   
			cell_offset[cell_idx] = current_offset;
		}
		int64_t total_ia_range{cell_offset[-1].item<int64_t>()};
		auto x2 = torch::empty({total_ia_range}, at::kDouble);
		auto y2 = torch::empty({total_ia_range}, at::kDouble);
		auto z2 = torch::empty({total_ia_range}, at::kDouble);

		{
			uint32_t idx{0};
			for (int i{0}; i < this->dx; i++) {
				for (int j{0}; j < this->dy; j++) {
					for (int k{0}; k < this->dz; k++) {
						for (int64_t ia{0}; ia < this->Cell[i][j][k].length; ++ia) {
							x2[idx] = this->Cell[i][j][k].address[ia].fatom.x();
							y2[idx] = this->Cell[i][j][k].address[ia].fatom.y();
							z2[idx] = this->Cell[i][j][k].address[ia].fatom.z();
							if (!this->expand_flag){
								const int b0 = this->Cell[i][j][k].in_grid[0];
								const int b1 = this->Cell[i][j][k].in_grid[1];
								const int b2 = this->Cell[i][j][k].in_grid[2];
								x2[idx] += b0 * this->vec1[0] + b1 * this->vec2[0] + b2 * this->vec3[0];
								y2[idx] += b0 * this->vec1[1] + b1 * this->vec2[1] + b2 * this->vec3[1];
								z2[idx] += b0 * this->vec1[2] + b1 * this->vec2[2] + b2 * this->vec3[2];
							}
							idx++;
						}
					}
				}
			}   
		}

		std::cout << "Moving data to GPU..." << std::endl;
		x = x.to(torch::kCUDA);
		y = y.to(torch::kCUDA);
		z = z.to(torch::kCUDA);
				
		std::cout << "Start computing..." << std::endl;

		/* we can't do this because true_ia_range x total_ia_range matrix is too large.
		// true_ia_range x total_ia_range matrix
		auto dr_square = at::outer(x, x2) * (-2.0) + at::square(x).unsqueeze(-1).repeat({1, total_ia_range}) + at::square(x2).unsqueeze(0).repeat({true_ia_range, 1}) +
			at::outer(y, y2) * (-2.0) + at::square(y).unsqueeze(-1).repeat({1, total_ia_range}) + at::square(y2).unsqueeze(0).repeat({true_ia_range, 1}) +
			at::outer(z, z2) * (-2.0) + at::square(z).unsqueeze(-1).repeat({1, total_ia_range}) + at::square(z2).unsqueeze(0).repeat({true_ia_range, 1});

		auto indices = (dr_square != 0.0 & dr_square <= this->sradius * this->sradius).nonzero_numpy();
		*/
		// Instead, we use a loop to do so.
		{
			const int64_t batch_size = 512;
			int32_t cell_offset_idx = 0;
			boost::progress_display show_progress(total_ia_range / batch_size + 1);
			for (int64_t start_col{0}; start_col < total_ia_range; start_col += batch_size)
			{
				int64_t end_col = (start_col + batch_size <= total_ia_range) ? (start_col + batch_size) : total_ia_range;
				auto sub_x2 = x2.slice(0, start_col, end_col);
				auto sub_y2 = y2.slice(0, start_col, end_col);
				auto sub_z2 = z2.slice(0, start_col, end_col);
				sub_x2 = sub_x2.to(torch::kCUDA);
				sub_y2 = sub_y2.to(torch::kCUDA);
				sub_z2 = sub_z2.to(torch::kCUDA);
				auto dr_square = at::outer(x, sub_x2) * (-2.0);
				dr_square += at::square(x).unsqueeze(-1);
				dr_square += at::square(sub_x2).unsqueeze(0);
				dr_square += at::outer(y, sub_y2) * (-2.0);
				dr_square += at::square(y).unsqueeze(-1);
				dr_square += at::square(sub_y2).unsqueeze(0);
				dr_square += at::outer(z, sub_z2) * (-2.0);
				dr_square += at::square(z).unsqueeze(-1);
				dr_square += at::square(sub_z2).unsqueeze(0);

				auto indices = at::logical_and(dr_square != 0.0, dr_square <= this->sradius * this->sradius).nonzero().to(torch::kCPU);
				std::cout << "sradius:" << this->sradius <<std::endl;
				std::cout << indices << std::endl;
				if (indices.size(0) != 0)
				{
					std::cout << dr_square <<std::endl;
					indices.slice(1, 1, -1) += start_col;
					for (int32_t idx = 0; idx < indices.size(0); ++idx)
					{
						int32_t true_ia = indices[idx][0].item<int32_t>();
						int32_t ia_offset = indices[idx][1].item<int32_t>();
						while (cell_offset_idx < cell_offset.size(0) && cell_offset[cell_offset_idx].item<int32_t>() > ia_offset)
						{
							cell_offset_idx++;
						}
						int32_t i2 = cell_offset_idx / this->dz /this->dy;
						int32_t j2 = (cell_offset_idx / this->dz) % this->dy;
						int32_t k2 = cell_offset_idx % this->dz;
						int32_t ia2 = ia_offset - cell_offset[cell_offset_idx].item<int32_t>();
						const int b0 = this->Cell[i2][j2][k2].in_grid[0];
						const int b1 = this->Cell[i2][j2][k2].in_grid[1];
						const int b2 = this->Cell[i2][j2][k2].in_grid[2];
						int offset = Cell[i2][j2][k2].address - this->atomlink;
						offset += ia2;
						Cell[true_i][true_j][true_k].address[true_ia].fatom.getAdjacentSet()->set(b0, b1, b2, offset, test_grid);
					}
				}
				++show_progress;
			}
		}

	}
#endif

void Grid::Construct_Adjacent_expand_periodic(
    const int true_i, 
	const int true_j, 
	const int true_k, 
	const int true_ia)
{
//	if (test_grid)TITLE(ofs_running, "Grid", "Construct_Adjacent_expand_periodic");
	for (int i = 0;i < this->dx;i++)
	{
		for (int j = 0;j < this->dy;j++)
		{
			for (int k = 0;k < this->dz;k++)
			{
				for (int ia = 0;ia < Cell[i][j][k].length;ia++)
				{
					Construct_Adjacent_final(true_i, true_j, true_k, true_ia, i, j, k, ia);
				}
			}
		}
	}
	return;
}

void Grid::Construct_Adjacent_begin(void)
{
//	if (test_grid)TITLE(ofs_running, "Grid", "Construct_Adjacent_begin");

//----------------------------------------------------------
// EXPLAIN : Searching in all cells in this grid
//----------------------------------------------------------

	for (int i = 0;i < this->dx;i++)
	{
		for (int j = 0;j < this->dy;j++)
		{
			for (int k = 0;k < this->dz;k++)
			{
//----------------------------------------------------------
// EXPLAIN : Cell length == Number of atoms in this cell
//----------------------------------------------------------
				for (int ia = 0;ia < Cell[i][j][k].length;ia++)
				{
					if (test_grid > 2)
					{
/*
						ofs_running << "\n" << setw(15) << "Atom"
						<< setw(15) << Cell[i][j][k].address[ia].fatom.x()
						<< setw(15) << Cell[i][j][k].address[ia].fatom.y()
						<< setw(15) << Cell[i][j][k].address[ia].fatom.z()
						<< setw(10) << Cell[i][j][k].address[ia].fatom.getType();
*/
					}

					// the new allocate space is needed.
					// and is deleted in the deconstructor of Fatom class.
					// mohan confused with the beow new,
					// so write another function: allocate_AdjacentSet 
					// to replace it. 2009-05-28
//					AdjacentSet* p = new AdjacentSet; 
//					this->Cell[i][j][k].address[ia].fatom.setAdjacentSet( p );
					this->Cell[i][j][k].address[ia].fatom.allocate_AdjacentSet();

					//pbc: periodic boundary condition
					if (this->pbc)
					{
						Construct_Adjacent_periodic(i, j, k, ia);
					}
					else
					{
						Construct_Adjacent_nature(i, j, k, ia);
					}
					
				}//ia
			}//k
		}//j
	}//i

	return;
}

void Grid::Construct_Adjacent_nature
(
    const int i,
    const int j,
    const int k,
    const int ia
)
{
//	if(test_grid)TITLE(ofs_running,"Grid","Construct_Adjacent_nature");
	for (int i2 = i - 1;i2 <= i + 1;i2++)
	{
		if (i2<dx && i2 >= 0)
		{
			for (int j2 = j - 1;j2 <= j + 1;j2++)
			{
				if (j2<dy && j2 >= 0)
				{
					for (int k2 = k - 1;k2 <= k + 1;k2++)
					{
						if (k2<dz && k2 >= 0)
						{
							for (int ia2 = 0;ia2 < Cell[i2][j2][k2].length;ia2++)
							{
								Construct_Adjacent_final(i, j, k, ia, i2, j2, k2, ia2);
							}//ia2
						}
					}//k2
				}
			}//j2
		}
	}//2

	return;
}

void Grid::Construct_Adjacent_periodic
(
    const int i,
    const int j,
    const int k,
    const int ia
)
{
//	if(test_grid)TITLE(ofs_running,"Grid","Construct_Adjacent_periodic");
	bool first_i = true;

	for (int i2 = i - 1;i2 <= i + 1;i2++)
	{
		bool first_j = true;

		for (int j2 = j - 1;j2 <= j + 1;j2++)
		{
			bool first_k = true;

			for (int k2 = k - 1;k2 <= k + 1;k2++)
			{
				int temp_i = i2;
				int temp_j = j2;
				int temp_k = k2;

				int g0 = 0;
				int g1 = 0;
				int g2 = 0;

				if (i2 < 0)
				{
					g0 = -1;

					if (first_i)
					{
						if (dx >= 2)
						{
							i2--;
							temp_i--;
						}

						first_i = false;
					}

					i2 += dx;
				}
				else if (i2 >= dx)
				{
					g0 = 1;
					i2 -= dx;
				}

				if (j2 < 0)
				{
					g1 = -1;

					if (first_j)
					{
						if (dy >= 2)
						{
							j2--;
							temp_j--;
						}

						first_j = false;
					}

					j2 += dy;
				}
				else if (j2 >= dy)
				{
					g1 = 1;
					j2 -= dy;
				}

				if (k2 < 0)
				{
					g2 = -1;

					if (first_k)
					{
						if (dz >= 2)
						{
							k2--;
							temp_k--;
						}

						first_k = false;
					}

					k2 += dz;
				}
				else if (k2 >= dz)
				{
					g2 = 1;
					k2 -= dz;
				}

				Cell[i2][j2][k2].in_grid[0] = g0;

				Cell[i2][j2][k2].in_grid[1] = g1;
				Cell[i2][j2][k2].in_grid[2] = g2;

				for (int ia2 = 0;ia2 < Cell[i2][j2][k2].length;ia2++)
				{
					Construct_Adjacent_final(i, j, k, ia, i2, j2, k2, ia2);
				}//ia2

				i2 = temp_i;

				j2 = temp_j;

				k2 = temp_k;//resume i2 j2 k2
			}//k2
		}//j2
	}//i2

	return;
}

void Grid::Construct_Adjacent_final
(const int i, const int j, const int k, const int ia,
 const int i2, const int j2, const int k2, const int ia2
)
{
//----------------------------------------------------------
// EXPLAIN : 		expand_case				not_expand_case
// (i,j,k,ia) 		only the 'true' cell	only the 'true' grid
// (i2,j2,k2,ia2) 	all atoms in grid		all atoms in 27*cell
//----------------------------------------------------------
// (suitable for small cell periodic condition)
// Expand_Case : many 'pseudo' cells, only one true cell,
// one grid(true grid).
// Advantage : only the atoms in 'true' cell need to construct
// AdjacentSet.
// Disadvantage : must search all atoms in true grid to construct
// AdjacentSet.
//
// (suitable for large cell periodic/nature condition,here
// we discuss periodic case,once you known this case, nature
// boundary is easy to understand)
// Not_Expand_Case : 27 'pseudo' grid,only one true grid,
// many true cells.
// Advantage : (the disadvantage above is the advantage now)
// only need to search 27*cells to construct AdjacentSet
// for each cell.
// Disadvantage : (the advantave mentioned above)
// need to construct adjacent for each cell.
//----------------------------------------------------------
	const double x  = Cell[i ][j ][k ].address[ia ].fatom.x();
	const double y  = Cell[i ][j ][k ].address[ia ].fatom.y();
	const double z  = Cell[i ][j ][k ].address[ia ].fatom.z();
	double x2 = Cell[i2][j2][k2].address[ia2].fatom.x();
	double y2 = Cell[i2][j2][k2].address[ia2].fatom.y();
	double z2 = Cell[i2][j2][k2].address[ia2].fatom.z();
//----------------------------------------------------------
// EXPLAIN : in different case 'in_grid' has different
// meaning.
//----------------------------------------------------------
// NAME : 			expand_case		 |  not_expand_case
// in_which_grid	'not available'	 |  one of 27 adjacent grid
// in_which_cell	one of all cells |  'not available'
//----------------------------------------------------------
// The solution here is we save these datas in one structrue
// named : 'in_grid'
//----------------------------------------------------------
	const int b0 = Cell[i2][j2][k2].in_grid[0];
	const int b1 = Cell[i2][j2][k2].in_grid[1];
	const int b2 = Cell[i2][j2][k2].in_grid[2];

	if (!expand_flag)
	{
		x2 = x2 + b0 * vec1[0] + b1 * vec2[0] + b2 * vec3[0];
		y2 = y2 + b0 * vec1[1] + b1 * vec2[1] + b2 * vec3[1];
		z2 = z2 + b0 * vec1[2] + b1 * vec2[2] + b2 * vec3[2];
	}

//----------------------------------------------------------
// EXPlAIN : Calculate distance between two atoms.
//----------------------------------------------------------
	double delta_x = x - x2;
	double delta_y = y - y2;
	double delta_z = z - z2;

	double dr = sqrt(delta_x * delta_x + delta_y * delta_y + delta_z * delta_z);

	if (dr != 0.0 && dr <= this->sradius)
	{
		int offset = Cell[i2][j2][k2].address - this->atomlink;
		offset += ia2;
		Cell[i][j][k].address[ia].fatom.getAdjacentSet()->set(b0, b1, b2, offset, test_grid);

		if (test_grid > 2)
		{
/*
			ofs_running << "\n"
			<< setw(15) << x2 << setw(15) << y2 << setw(15) << z2
			<< setw(10) << Cell[i2][j2][k2].address[ia2].fatom.getType()
			<< setw(10) << dr;
*/
		}
	}

	return;
}
//2015-05-07
void Grid::delete_vector(const Atom_input &input)
{
	if (expand_flag)
	{
		const int i = input.getGrid_layerX_minus();
		const int j = input.getGrid_layerY_minus();
		const int k = input.getGrid_layerZ_minus();
		for (int ia = 0;ia < Cell[i][j][k].length;ia++)
		{
			if (this->pbc)
			{
				Cell[i][j][k].address[ia].fatom.delete_vector();
			}
		}
	}
}
