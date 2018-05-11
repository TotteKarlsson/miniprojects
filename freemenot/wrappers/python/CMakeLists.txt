cmake_minimum_required(VERSION 2.8)
project(dslFoundations)

find_package(SWIG REQUIRED)
include(UseSWIG)

if(SWIG_FOUND)
    add_subdirectory(dsl)
else(SWIG_FOUND)
    message("Could not find SWIG in your system")
endif(SWIG_FOUND)




