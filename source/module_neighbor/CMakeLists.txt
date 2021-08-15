add_library(
    neighbor
    OBJECT
    sltk_adjacent_set.cpp
    sltk_atom.cpp
    sltk_atom_arrange.cpp
    sltk_atom_input.cpp
    sltk_grid.cpp
    sltk_grid_driver.cpp
)

set_target_properties(${neighbor}
    PROPERTIES CUDA_SEPARABLE_COMPILATION ON
)

target_link_libraries(neighbor PRIVATE OpenMP::OpenMP_CXX)
