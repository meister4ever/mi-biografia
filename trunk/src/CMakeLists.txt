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
  add_library(ArbolBMas arbolBMas)
  add_library(ArbolBMasNodo arbolBMasNodo)
  add_library(Archivo archivo)
  add_library(ArchivoId archivoId)
  add_library(ArchivoBloques archivoBloques)
  add_library(Bloque bloque)
  add_library(Buffer buffer)
  add_library(HashExt hashExt)
  add_library(Indice indice)
  add_library(IndiceAutor indiceAutor)
  add_library(IndiceFecha indiceFecha)
  add_library(IndiceTitulo indiceTitulo)
  add_library(Parser parser)
  add_library(ParserRSS parserRSS)
  add_library(ParserTWT parserTWT)
  add_library(Registro registro)
  add_library(RegistroFijo registroFijo)
  add_library(RegistroRSS registroRSS)
  add_library(RegistroTWT registroTWT)
  add_library(RegistroVar registroVar)
  add_library(Serializable serializable)

  target_link_libraries(Registro HashExt)
  target_link_libraries(RegistroFijo Registro)
  target_link_libraries(ArbolBMasNodo Registro)
  target_link_libraries(ArchivoBloques Archivo Bloque)
  target_link_libraries(ArchivoId HashExt Registro Serializable)
  target_link_libraries(HashExt Bloque)
  target_link_libraries(Indice ArbolBMas Parser Registro Serializable)
  target_link_libraries(IndiceTitulo Indice)
  target_link_libraries(IndiceAutor Indice)
  target_link_libraries(IndiceFecha Indice)
  target_link_libraries(IndiceTitulo Indice)
  target_link_libraries(ParserRSS Parser)
  target_link_libraries(ParserTWT Parser)
  target_link_libraries(RegistroRSS RegistroVar)
  target_link_libraries(RegistroTWT RegistroFijo)
  target_link_libraries(RegistroVar Registro)
  target_link_libraries(Serializable Buffer)
  

add_executable(MiBiografia bio.cpp)