
#Agrega el directorio de googletest para que se compile 
add_subdirectory(gtest)

#Asegurarse de que el compilador puede encontrar 
#los ficheros de nuestra librería ArbolB
include_directories(${PROJECT_SOURCE_DIR}/src)


enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


#Añade un binario llamado "runUnitTests" que es construido 
#del fichero fuente "arbolBTest.cpp"
#La extensión se encuentra automáticamente
add_executable(runUnitTests arbolBTest)
target_link_libraries(runUnitTests gtest gtest_main)
#Enlaza el ejecutable con la librería ArbolB
target_link_libraries(runUnitTests ArbolB)

add_test( runUnitTests arbolBTest.cpp )