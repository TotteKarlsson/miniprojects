cmake_minimum_required(VERSION 2.8)
set(target dslCommon)

include_directories(
    ./../
)

link_directories(
${CMAKE_BINARY_DIR}/lib
)

set(src
freemenot.cpp
)

#===== Shared library
add_library(${target} SHARED
${src}
)

set_property(TARGET ${target}  
    PROPERTY COMPILE_DEFINITIONS 
    EXPORT_COMMON
)

#link libraries
    install(    
    TARGETS ${target} 
    RUNTIME DESTINATION bin 
    LIBRARY DESTINATION lib 
    ARCHIVE DESTINATION lib 
    )            


FILE (GLOB headers *.h)
install (   
    FILES ${headers} 	 		 	
    DESTINATION include 
    COMPONENT cxx_headers
)

install(FILES
    ${PROJECT_BINARY_DIR}/bin/${target}.tds
    DESTINATION bin
    COMPONENT debug
)


