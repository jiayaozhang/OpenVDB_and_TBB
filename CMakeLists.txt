cmake_minimum_required(VERSION 3.0.0)
project(OpenVDB_Cookbook VERSION 0.1.0)

find_package(OpenVDB REQUIRED)
find_package(blosc  REQUIRED)
find_package(TBB  REQUIRED)

set(CHAPTERS
    01_Hello_World_for_OpenVDB
    02_Creating_and_writing_a_grid
    03_Reading_and_modifying_a_grid
    04_Stream_I_O
    05_Handling_metadata
    06_Iteration
    07_Interpolation_of_grid_values
    08_Transforming_grids
    09_Combining_grids
    10_Generic_programming
    11_Hello_World_for_OpenVDB_Points
    12_Converting_Point_Attributes
    13_Random_Point_Generation
    14_Point_Iteration_Groups_and_Filtering
    15_Strided_Point_Attributes
    16_Moving_Points_in_Space
)

set(01_Hello_World_for_OpenVDB
    01_01_Hello_World_for_OpenVDB
)

set(02_Creating_and_writing_a_grid
    02_01_Creating_and_writing_a_grid
    02_02_Populating_a_grid_with_values
)

set(03_Reading_and_modifying_a_grid
    03_01_Reading_and_modifying_a_grid
)

set(04_Stream_I_O
    04_01_Stream_I_O
)

set(05_Handling_metadata
    05_01_Adding_metadata
    05_02_Retrieving_metadata
    05_03_Removing_metadata
)

set(06_Iteration
    06_01_Node_Iterator
    06_02_Leaf_Node_Iterator
    06_03_Value_Iterator
    06_04_Iterator_Range
)

set(07_Interpolation_of_grid_values
    07_01_Index-space_samplers
    07_02_Grid_Sampler
    07_03_Dual_Grid_Sampler
)

set(08_Transforming_grids
    08_01_Geometric_transformation
    08_02_Value_transformation
    08_03_Value_transformation
    08_04_Value_transformation
)

set(09_Combining_grids
    09_01_Level_set_CSG_operations
    09_02_Compositing_operations
    09_03_Generic_combination
    09_04_Generic_combination
    09_05_Generic_combination
    09_06_Generic_combination
)

set(10_Generic_programming
    # 10_01_Calling_Grid_methods
)
    
set(11_Hello_World_for_OpenVDB_Points
    11_01_Hello_World_for_OpenVDB_Points
)

set(12_Converting_Point_Attributes
    12_01_Converting_Point_Attributes
)

set(13_Random_Point_Generation
    13_01_Random_Point_Generation
)
    
set(14_Point_Iteration_Groups_and_Filtering
    14_01_Point_Iteration
    14_02_Point_Iteration
    14_03_Point_Iteration
    # 14_04_Creating_and_Assigning_Point_Groups
    14_05_Point_Filtering_using_Groups
    # 14_06_Point_Filtering_using_Groups
    # 14_07_Point_Filtering_using_Custom_Filters
)
    
set(15_Strided_Point_Attributes
    15_01_Constant_Stride_Attributes
)
    
set(16_Moving_Points_in_Space
    16_01_Advecting_Points
    16_02_Moving_Points_with_a_Custom_Deformer
)

foreach(CHAPTER ${CHAPTERS})
    foreach(EXAMPLE ${${CHAPTER}})
        add_executable(${EXAMPLE} "src/${CHAPTER}/${EXAMPLE}.cpp")
        target_link_libraries(${EXAMPLE} PRIVATE
            OpenVDB::openvdb
            blosc
            TBB::tbb
        )
    endforeach(EXAMPLE)
endforeach(CHAPTER)