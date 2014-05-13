//  runtimeConfig.h

#ifndef _runtimeConfig_h
#define _runtimeConfig_h
#define ARCH_CONFIG "parametros.conf"

#include <string>
#include <iostream>
#include <fstream>

std::string sourcePath();

std::string destPath();

unsigned int maxDedupTimes();

unsigned int hashBlockSize();

unsigned int arbolBlockSize();

#endif
