#ifndef DESCARGADOR_H_INCLUDED
#define DESCARGADOR_H_INCLUDED


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <list>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include "dirent.h"
#include "runtimeConfig.h"

using namespace std;


class Descargador {
    public:
        static void descargarTwt();
        static void menuRss();

    private:
        static list<string> getListaRss();
        static bool descargarRss(string dirFuenteRss);
        static void descargarRss(list<string> listaDeFuentesRss);
        static string getHomeDir();

};


#endif // DESCARGADOR_H_INCLUDEDc
