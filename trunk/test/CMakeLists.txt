
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
add_executable(runUnitTests 
    arbolBTest 
    arbolBMasTest
    arbolBMasNodoTest
    archivoIdTest
    archivoBloquesTest
    bloqueTest
    bufferTest
    hashExtTest
    indiceAutorTest
    indiceFechaTest
    indiceTituloTest
    parserRSSTest
    parserTWTTest
    registroFijoTest
    registroRSSTest
    registroTWTTest
    registroVarTest)
    
target_link_libraries(runUnitTests gtest gtest_main)
#Enlaza el ejecutable con la librería ArbolB
target_link_libraries(runUnitTests 
    ArbolB 
    ArbolBMas
    ArbolBMasNodo
    ArchivoId
    ArchivoBloques
    Bloque
    Buffer
    HashExt
    Indice
    IndiceAutor
    IndiceFecha
    IndiceTitulo
    Parser
    ParserRSS
    ParserTWT
    Registro
    RegistroFijo
    RegistroRSS
    RegistroTWT
    RegistroVar
    Serializable)

add_test( runUnitTests 
    arbolBTest.cpp
    arbolBMasTest.cpp
    arbolBMasNodoTest.cpp
    archivoIdTest.cpp
    archivoBloquesTest.cpp
    bloqueTest.cpp
    bufferTest.cpp
    hashExtTest.cpp
    indiceAutorTest.cpp
    indiceFechaTest.cpp
    indiceTituloTest.cpp
    parserRSSTest.cpp
    parserTWTTest.cpp
    registroFijoTest.cpp
    registroRSSTest.cpp
    registroTWTTest.cpp
    registroVarTest.cpp)