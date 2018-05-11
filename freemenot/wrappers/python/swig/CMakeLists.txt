cmake_minimum_required(VERSION 2.8)
find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})
find_package(PythonInterp)
find_package(PythonLibs)
message("Python include folder: " ${PYTHON_INCLUDE_DIRS})
message("Python libraries: " ${PYTHON_LIBRARIES})

get_filename_component(PYTHON_LIB_FOLDER ${PYTHON_LIBRARIES} DIRECTORY CACHE)
message("Python lib folder: " ${PYTHON_LIB_FOLDER})

include_directories(
    .
    ./Common
    ${PYTHON_INCLUDE_PATH}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

link_directories(
${CMAKE_BINARY_DIR}/lib
${PYTHON_LIB_FOLDER}
)


message("Lib folder: " ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_MODULE_LINKER_FLAGS ${CMAKE_CURRENT_SOURCE_DIR}/freemenot.def)

if(BORLAND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w-8105")
    set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}")
endif(BORLAND)

set_source_files_properties(freeme_not.i PROPERTIES CPLUSPLUS ON)
set_source_files_properties(freeme_not.i PROPERTIES SWIG_FLAGS "-threads")

set(pModule "freemenot")
SWIG_ADD_LIBRARY(${pModule}
    MODULE LANGUAGE python 
    SOURCES ${pModule}.i )
    
SWIG_LINK_LIBRARIES (${pModule}
    ${PYTHON_LIB_FOLDER}/Python3_CG.lib
    ${PYTHON_LIB_FOLDER}/Python37_CG.lib    
)

# INSTALL PYTHON BINDINGS
# Get the python site packages directory by invoking python
execute_process(COMMAND python -c "import site; print(site.getsitepackages()[0])" OUTPUT_VARIABLE PYTHON_SITE_PACKAGES OUTPUT_STRIP_TRAILING_WHITESPACE)
message("PYTHON_SITE_PACKAGES = ${PYTHON_SITE_PACKAGES}")

install(
    TARGETS _${pModule}
    DESTINATION ${PYTHON_SITE_PACKAGES})

install(
    FILES         ${CMAKE_CURRENT_BINARY_DIR}/${pModule}.py 
                  ${CMAKE_BINARY_DIR}/lib/_${pModule}.tds
    DESTINATION   ${PYTHON_SITE_PACKAGES}
)
