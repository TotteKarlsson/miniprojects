cmake_minimum_required(VERSION 2.8)
set(target freeMeNotShared)

include_directories(
)

link_directories(${CMAKE_BINARY_DIR}/lib)

set(src
freemenot
BaseProperty
Constants
MyObject
Properties
)

#===== Shared library
add_library(${target} SHARED
${src}
)

set_property(TARGET ${target}  
    PROPERTY COMPILE_DEFINITIONS 
    EXPORT_DLL
)

#link libraries
target_link_libraries(${target} 
)

install(    
TARGETS ${target} 
RUNTIME DESTINATION bin COMPONENT core
LIBRARY DESTINATION lib COMPONENT core
ARCHIVE DESTINATION lib COMPONENT core
)            

#===== General Installs
FILE (GLOB headers *.h)
install (   
    FILES ${headers} 	 		 	
    DESTINATION include/${target} 
    COMPONENT cxx_headers
)

install(FILES
    ${PROJECT_BINARY_DIR}/${target}.tds
    DESTINATION bin
    COMPONENT debug
)

# Create wrapper
add_subdirectory(wrapper)

