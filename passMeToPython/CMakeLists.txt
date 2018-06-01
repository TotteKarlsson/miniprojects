cmake_minimum_required(VERSION 2.8)
project(passmetopython)
find_package(SWIG REQUIRED)
include(UseSWIG)
find_package(PythonInterp)
find_package(PythonLibs)
get_filename_component(PYTHON_LIB_FOLDER ${PYTHON_LIBRARIES} DIRECTORY CACHE)
message("Python lib folder: " ${PYTHON_LIB_FOLDER})
message("Python include folder: " ${PYTHON_INCLUDE_DIRS})
message("Python libraries: " ${PYTHON_LIBRARIES})

set(PyModule "passmetopython")
include_directories(
    ${PYTHON_INCLUDE_PATH}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

link_directories( ${PYTHON_LIB_FOLDER})

set(CMAKE_MODULE_LINKER_FLAGS ${CMAKE_CURRENT_SOURCE_DIR}/${PyModule}.def)

set_source_files_properties(${PyModule}.i PROPERTIES CPLUSPLUS ON)
set_source_files_properties(${PyModule}.i PROPERTIES SWIG_FLAGS "-threads")

SWIG_ADD_LIBRARY(${PyModule}
    MODULE LANGUAGE python
    SOURCES ${PyModule}.i MyClass.h)

SWIG_LINK_LIBRARIES (${PyModule} ${PYTHON_LIB_FOLDER}/Python37_CG.lib    )

# INSTALL PYTHON BINDINGS
# Get the python site packages directory by invoking python
execute_process(COMMAND python -c "import site; print(site.getsitepackages()[0])" OUTPUT_VARIABLE PYTHON_SITE_PACKAGES OUTPUT_STRIP_TRAILING_WHITESPACE)
message("PYTHON_SITE_PACKAGES = ${PYTHON_SITE_PACKAGES}")
execute_process(COMMAND swig -python -external-runtime ${PyModule}.h)

# Generate and install swig header file for C++

install(
    TARGETS _${PyModule}
    DESTINATION ${PYTHON_SITE_PACKAGES})

install(
    FILES         ${CMAKE_CURRENT_BINARY_DIR}/${PyModule}.py 
    DESTINATION   ${PYTHON_SITE_PACKAGES}
)

install(
    FILES         ${CMAKE_CURRENT_BINARY_DIR}/${PyModule}.h 
    DESTINATION   include
)
