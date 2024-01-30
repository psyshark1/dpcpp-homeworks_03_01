cmake_minimum_required (VERSION 3.8)

project (01)
set (CMAKE_CXX_STANDARD 17)

add_executable (01 01.cpp)
target_compile_features(01 PRIVATE cxx_std_17)
