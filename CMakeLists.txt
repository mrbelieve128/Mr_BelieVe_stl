cmake_minimum_required(VERSION 3.16)
project(Mr_BelieVe_stl)

set(CMAKE_CXX_STANDARD 11)

add_executable(Mr_BelieVe_stl main.cpp stl_alloc.h stl_config.h stl_iterator.h stl_iterator_base.h stl_iterator.h stl_uninitialized.h type_traits.h stl_construct.h stl_vector.h stl_algobase.h stl_list.h)
