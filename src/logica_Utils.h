#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <time.h>
#include "dirent.h"

using namespace std;

class Utils{
    private:
        static void dividirRss(string fileName, int contador, string fecha);
        static void dividirTwt(string fileName, int contador, string fecha);
    public:
        static int splitString(string s, char delimitador, list<string> *ptr);
        static string getClaveFromHeader(string header);
        static int getAutoresFromHeader(string s, list<string>*);
        static int getTitulosFromHeader(string s, list<string>*);
        static int getFechasFromHeader(string s, list<string>*);
        static string getTituloFromHeader(string header);
        static string uniformizarString(string source);
        static int existeArchivo(string archivo);
        static string IntToStr(int n);
        static string devolverFechaDeLinea(string linea, string fecha);
        static void dividirRssFiles(string fecha);
        static void dividirTwtFiles(string fecha);

        static string getFecha();

};

#endif // UTILS_H_INCLUDED
