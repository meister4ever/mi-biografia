#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "dirent.h"

using namespace std;

class Utils{
    private:
        static void dividirRss(string fileName, int contador, int fecha);
        static void dividirTwt(string fileName, int contador, int fecha);
    public:
        static int splitString(string s, char delimitador, list<string> *ptr);
        static string getClaveFromHeader(string header);
        static int getAutoresFromHeader(string s, list<string>*);
        static int getTitulosFromHeader(string s, list<string>*);
        static string getTituloFromHeader(string header);
        static string uniformizarString(string source);
        static int existeArchivo(string archivo);
        static string IntToStr(int n);
        static void dividirRssFiles(int fecha);
        static void dividirTwtFiles(int fecha);

};

#endif // UTILS_H_INCLUDED
