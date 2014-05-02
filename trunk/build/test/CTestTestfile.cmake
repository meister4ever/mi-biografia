# CMake generated Testfile for 
# Source directory: /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/test
# Build directory: /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/test
# 
# This file includes the relevent testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(runUnitTests "arbolBTest.cpp" "arbolBMasTest.cpp" "arbolBMasNodoTest.cpp" "archivoIdTest.cpp" "archivoBloquesTest.cpp" "bloqueTest.cpp" "bufferTest.cpp" "hashExtTest.cpp" "indiceAutorTest.cpp" "indiceFechaTest.cpp" "indiceTituloTest.cpp" "parserRSSTest.cpp" "parserTWTTest.cpp" "registroFijoTest.cpp" "registroRSSTest.cpp" "registroTWTTest.cpp" "registroVarTest.cpp")
SUBDIRS(gtest)
