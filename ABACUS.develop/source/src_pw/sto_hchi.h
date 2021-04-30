#ifndef INCLUDE_STO_HCHI_H
#define INCLUDE_STO_HCHI_H
#include "tools.h"

//-----------------------------------------------------
// h * chi
// chi: stochastic wave functions
//
// h: the normalized Hamiltonian matrix, which equals to (H - E\bar) / \DeltaE
// where H is decomposed into the electron kinetic, effective potential V(r),
// and the non-local pseudopotentials.
// The effective potential = Local pseudopotential +
// Hartree potential + Exchange-correlation potential
//------------------------------------------------------

class Stochastic_hchi
{

	public:

    // constructor and deconstructor
    Stochastic_hchi();
    ~Stochastic_hchi();
	static void init();
	static int nrxx;
	static int nx,ny,nz;
	static fftw_plan pf,pb;
	static double Emin, Emax;
	static bool initplan,ortho;
	static complex<double> *rp_chi,*rl_chi;

	static int * GRA_index;
	static void get_GRA_index();

	static void orthogonal_to_psi_real(complex<double>* wfin, complex<double> *wfout, int& ikk); //wfin & wfout are wavefunctions in real space
	static void hchi_real(complex<double> *wfin, complex<double> *wfout); //wfin & wfout are wavefunctions in real space
	
	static void orthogonal_to_psi_reciprocal(complex<double>* wfin, complex<double> *wfout, int& ikk); //wfin & wfout are wavefunctions in reciprocal space
	static void hchi_reciprocal(complex<double> *wfin, complex<double> *wfout); //wfin & wfout are wavefunctions in reciprocal space
	

	private:

	// chi should be orthogonal to psi (generated by diaganolization methods,
	// such as CG)
	


};

#endif// Eelectrons_hchi