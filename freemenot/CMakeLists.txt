cmake_minimum_required(VERSION 2.8)
project(freemenot)

set(DSL_ROOT 	${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY 	${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY 	${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY 	${PROJECT_BINARY_DIR}/bin)

find_package(PythonInterp)
find_package(PythonLibs)
message("Python include folder: " ${PYTHON_INCLUDE_DIRS})
include_directories(
${PYTHON_INCLUDE_DIRS}
)
 
include_directories(
${PYTHON_INCLUDE_DIRS}
${BOOST_ROOT}
${BOOST_ROOT}/boost/tr1/tr1
)

link_directories(
${THIRD_PARTY_INSTALL_PREFIX}/lib
)

#Source Code Folders
add_subdirectory(Common)
add_subdirectory(Wrappers)

