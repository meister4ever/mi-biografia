//  runtimeConfig.h

#ifndef _runtimeConfig_h
#define _runtimeConfig_h
#define ARCH_CONFIG "parametros.conf"

#include <string>
#include <iostream>
#include <fstream>

std::string sourcePath();

std::string destPath();

std::string testFile();

std::string testFileTable();

unsigned int maxDedupTimes();

unsigned int hashBlockSize();

unsigned int arbolBlockSize();

int estadistaMaximoAutoresMasBuscados();

int estadistaMaximoTitulosMasBuscados();

int estadistaMaximoFrasesMasBuscadas();

unsigned int PPMCOrder();

#endif
