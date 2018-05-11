cmake_minimum_required(VERSION 2.8)
project(freemenot)

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
)

link_directories(
)

#Source Code Folders
add_subdirectory(Wrappers)

