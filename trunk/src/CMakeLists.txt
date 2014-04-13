# The version number.
set (MiBiografia_VERSION_MAJOR 1)
set (MiBiografia_VERSION_MINOR 0)
# add the binary tree to the search path for include files
# so that we will find BioConfig.h
include_directories("${PROJECT_BINARY_DIR}/src")
include_directories("${PROJECT_SOURCE_DIR}/src")

configure_file (
  "${PROJECT_SOURCE_DIR}/src/BioConfig.h.in"
  "${PROJECT_BINARY_DIR}/src/BioConfig.h"
  )

#Añade una librería llamada ArbolB a partir del fichero fuente arbolB.cpp
add_library(ArbolB arbolB) 
add_executable(MiBiografia bio.cpp)