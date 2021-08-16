#include "sltk_grid.cuh"

#include <cstdint>
#include <thrust/device_vector.h>
#include <thrust/copy.h>
#include <thrust/host_vector.h>
#include <vector>
#include <iostream>
#include <boost/progress.hpp>

#include "../src_pw/tools.h"
#include "sltk_atom_input.h"

__global__ void Construct_adjacent_expand_kernel(
    uint64_t const dx,
    uint64_t const dy,
    uint64_t const dz,
    uint64_t const* const cell_offset,
    double const* const atom_link_x,
    double const* const atom_link_y,
    double const* const atom_link_z,
    double const* const cell_b0,
    double const* const cell_b1,
    double const* const cell_b2,
    double const* const grid_vec3x3
) {

}

void Construct_Adjacent_expand_Cuda(Grid *grid, const int true_i,
                                    const int true_j, const int true_k) {

    if (!grid->pbc) {
        WARNING_QUIT("Construct_Adjacent_expand",
                     "\n Expand case, must use periodic boundary.");
        return;
    }
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
    AdjacentSet::setExpandFlag(grid->expand_flag);

    AdjacentSet::setDx(grid->dx);

    AdjacentSet::setDy(grid->dy);

    AdjacentSet::setDz(grid->dz);

    // mohan add 2009-10-20
    AdjacentSet::setTrueX(true_i);

    AdjacentSet::setTrueY(true_j);

    AdjacentSet::setTrueZ(true_k);

    AdjacentSet::setCenter(true_i * grid->dy * grid->dz + true_j * grid->dz +
                           true_k);

    //	if(test_grid)OUT(ofs_running,"GridCenter",true_i,true_j,true_k);
    //	if(test_grid)OUT(ofs_running,"GridDim",dx,dy,dz);

    //-----------------------------------------------------------
    // EXPLAIN : (true_i,true_j,true_k) is the cell we want
    // to found AdjacentSet.And other cell save the displacement
    // of center_grid in 'in_grid'
    //-----------------------------------------------------------
    for (int i = 0; i < grid->dx; i++) {
        for (int j = 0; j < grid->dy; j++) {
            for (int k = 0; k < grid->dz; k++) {
                grid->Cell[i][j][k].in_grid[0] = i - true_i;
                grid->Cell[i][j][k].in_grid[1] = j - true_j;
                grid->Cell[i][j][k].in_grid[2] = k - true_k;
            }
        }
    }

    //----------------------------------------------------------
    // EXPLAIN : Only construct AdjacentSet for 'true' cell.
    //----------------------------------------------------------
    // for (int ia = 0;ia < Cell[true_i][true_j][true_k].length;ia++)
    int true_ia_range = grid->Cell[true_i][true_j][true_k].length;
    for (int true_ia = 0; true_ia < true_ia_range; ++true_ia) {
        grid->Cell[true_i][true_j][true_k]
            .address[true_ia]
            .fatom.allocate_AdjacentSet();
    }

    uint64_t const cell_count{grid->dx * grid->dy * grid->dz};
    thrust::host_vector<uint64_t> cell_offset(cell_count + 1);
    thrust::host_vector<double> atom_link_x;
    thrust::host_vector<double> atom_link_y;
    thrust::host_vector<double> atom_link_z;

    thrust::host_vector<double> cell_b0(cell_count);
    thrust::host_vector<double> cell_b1(cell_count);
    thrust::host_vector<double> cell_b2(cell_count);
    {
        std::cout << "Preparing data..." << std::endl;
        boost::progress_display show_progress(cell_count);
        uint64_t current_offset{0U};
        uint64_t cell_idx{0U};
        for (int i{0}; i < grid->dx; i++) {
            for (int j{0}; j < grid->dy; j++) {
                for (int k{0}; k < grid->dz; k++) {
                    cell_offset[cell_idx] = current_offset;
                    cell_b0[cell_idx] = grid->Cell[i][j][k].in_grid[0];
                    cell_b1[cell_idx] = grid->Cell[i][j][k].in_grid[1];
                    cell_b2[cell_idx] = grid->Cell[i][j][k].in_grid[2];
                    ++cell_idx;
                    ++show_progress;
                    current_offset += grid->Cell[i][j][k].length;
                    for (int64_t ia{0}; ia < grid->Cell[i][j][k].length; ++ia) {
                        atom_link_x.push_back(grid->Cell[i][j][k].address[ia].fatom.x());
                        atom_link_y.push_back(grid->Cell[i][j][k].address[ia].fatom.y());
                        atom_link_z.push_back(grid->Cell[i][j][k].address[ia].fatom.z());
                    }
                }
            }
        }   
        cell_offset[cell_idx] = current_offset;
    }

    std::cout << "Copying data to GPU..." << std::endl;
    thrust::device_vector<uint64_t> cell_offset_device = cell_offset;
    thrust::device_vector<double> atom_link_x_device = atom_link_x;
    thrust::device_vector<double> atom_link_y_device = atom_link_y;
    thrust::device_vector<double> atom_link_z_device = atom_link_z;
    thrust::device_vector<double> cell_b0_device = cell_b0;
    thrust::device_vector<double> cell_b1_device = cell_b1;
    thrust::device_vector<double> cell_b2_device = cell_b2;
    thrust::device_vector<double> grid_vec(9);
    {
        auto raw_ptr = thrust::raw_pointer_cast(grid_vec.data());
        cudaMemcpy(raw_ptr, grid->vec1, sizeof(double) * 3, cudaMemcpyHostToDevice);
    }
    thrust::device_vector<double> grid_vec2(3);
    {
        auto raw_ptr = thrust::raw_pointer_cast(grid_vec.data()) + 3;
        cudaMemcpy(raw_ptr, grid->vec2, sizeof(double) * 3, cudaMemcpyHostToDevice);
    }
    thrust::device_vector<double> grid_vec3(3);
    {
        auto raw_ptr = thrust::raw_pointer_cast(grid_vec.data()) + 6;
        cudaMemcpy(raw_ptr, grid->vec3, sizeof(double) * 3, cudaMemcpyHostToDevice);
    }
    std::cout << "Start computing..." << std::endl;
    dim3 cuda_grid{true_ia_range, cell_count};
    dim3 cuda_block{1024};
    Construct_adjacent_expand_kernel<<<cuda_grid, cuda_block>>>(
        grid->dx,
        grid->dy,
        grid->dz,
        thrust::raw_pointer_cast(cell_offset.data()),
        thrust::raw_pointer_cast(atom_link_x.data()),
        thrust::raw_pointer_cast(atom_link_y.data()),
        thrust::raw_pointer_cast(atom_link_z.data()),
        thrust::raw_pointer_cast(cell_b0.data()),
        thrust::raw_pointer_cast(cell_b1.data()),
        thrust::raw_pointer_cast(cell_b2.data()),
        thrust::raw_pointer_cast(grid_vec.data())
    );
    // TODO: make it parallel in CUDA.
    auto& selected_cell = grid->Cell[true_i][true_j][true_k];
    for (int true_ia = 0; true_ia < true_ia_range; ++true_ia) {
        for (int i = 0; i < grid->dx; i++) {
            for (int j = 0; j < grid->dy; j++) {
                for (int k = 0; k < grid->dz; k++) {
                    for (int ia = 0; ia < grid->Cell[i][j][k].length;
                            ia++) {
                        const double x = selected_cell
                                                .address[true_ia]
                                                .fatom.x();
                        const double y = selected_cell
                                                .address[true_ia]
                                                .fatom.y();
                        const double z = selected_cell
                                                .address[true_ia]
                                                .fatom.z();

                        double x2 =
                            grid->Cell[i][j][k].address[ia].fatom.x();
                        double y2 =
                            grid->Cell[i][j][k].address[ia].fatom.y();
                        double z2 =
                            grid->Cell[i][j][k].address[ia].fatom.z();
                        const int b0 = grid->Cell[i][j][k].in_grid[0];
                        const int b1 = grid->Cell[i][j][k].in_grid[1];
                        const int b2 = grid->Cell[i][j][k].in_grid[2];

                        if (!grid->expand_flag) {
                            x2 = x2 + b0 * grid->vec1[0] +
                                    b1 * grid->vec2[0] + b2 * grid->vec3[0];
                            y2 = y2 + b0 * grid->vec1[1] +
                                    b1 * grid->vec2[1] + b2 * grid->vec3[1];
                            z2 = z2 + b0 * grid->vec1[2] +
                                    b1 * grid->vec2[2] + b2 * grid->vec3[2];
                        }
                        double delta_x = x - x2;
                        double delta_y = y - y2;
                        double delta_z = z - z2;

                        double dr =
                            sqrt(delta_x * delta_x + delta_y * delta_y +
                                    delta_z * delta_z);

                        if (dr != 0.0 && dr <= grid->sradius) {
                            int offset = grid->Cell[i][j][k].address -
                                            grid->atomlink;
                            offset += ia;
                            selected_cell
                                .address[true_ia]
                                .fatom.getAdjacentSet()
                                ->set(b0, b1, b2, offset, test_grid);
                        }
                    }
                }
            }
        }
    }

    return;
}
