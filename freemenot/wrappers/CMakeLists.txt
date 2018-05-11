find_package(SWIG REQUIRED)
include(UseSWIG)
include(${SWIG_USE_FILE})
find_package(PythonInterp)
find_package(PythonLibs)
get_filename_component(PYTHON_LIB_FOLDER ${PYTHON_LIBRARIES} DIRECTORY CACHE)
message("Python lib folder: " ${PYTHON_LIB_FOLDER})
message("Python include folder: " ${PYTHON_INCLUDE_DIRS})
message("Python libraries: " ${PYTHON_LIBRARIES})

include_directories(
    .
    ${PYTHON_INCLUDE_PATH}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${DSL_ROOT}/Common
)

link_directories(
${CMAKE_BINARY_DIR}/lib
${PYTHON_LIB_FOLDER}
)


message("Lib folder: " ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_MODULE_LINKER_FLAGS ${CMAKE_CURRENT_SOURCE_DIR}/dsl.def)

if(BORLAND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w-8105")
    set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}")
endif(BORLAND)

set_source_files_properties(dsl.i PROPERTIES CPLUSPLUS ON)
set_source_files_properties(dsl.i PROPERTIES SWIG_FLAGS "-threads")

SWIG_ADD_LIBRARY(dsl
    MODULE LANGUAGE python 
    SOURCES dsl.i freemenot.cpp)
    
SWIG_LINK_LIBRARIES (dsl
    ${PYTHON_LIB_FOLDER}/Python37_CG.lib    
    ${PYTHON_LIB_FOLDER}/Python3_CG.lib    
)

# INSTALL PYTHON BINDINGS
# Get the python site packages directory by invoking python
execute_process(COMMAND python -c "import site; print(site.getsitepackages()[0])" OUTPUT_VARIABLE PYTHON_SITE_PACKAGES OUTPUT_STRIP_TRAILING_WHITESPACE)
message("PYTHON_SITE_PACKAGES = ${PYTHON_SITE_PACKAGES}")

install(
    TARGETS _dsl
    DESTINATION ${PYTHON_SITE_PACKAGES})

install(
    FILES         ${CMAKE_CURRENT_BINARY_DIR}/dsl.py 
                  ${CMAKE_BINARY_DIR}/lib/_dsl.tds
    DESTINATION   ${PYTHON_SITE_PACKAGES}
)
