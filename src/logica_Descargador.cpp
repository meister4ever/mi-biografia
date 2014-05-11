#include <iostream>
#include "logica_Descargador.h"

using namespace std;

list<string> Descargador::getListaRss()
{
    string archivoListaRss = "listaRss.txt";
    list<string> listaRss;
    ifstream entradaRss;
    entradaRss.open(archivoListaRss.c_str());
    string line;

    while (!entradaRss.eof()) {
      getline(entradaRss,line);
      listaRss.push_front(line);
    }
    entradaRss.close();

    return listaRss;
}

void Descargador::menuRss()
{
    string op;
    string direccion;

    cout << "Ingrese dirección Rss o 0 para cargar lista predeterminada"<< endl;

    cin >> direccion;


    if (direccion.compare("0") == 0){
        descargarRss(getListaRss());
    }else{
        descargarRss(direccion);
    }

    cout<<endl;
    cout<<endl;
}


bool Descargador::descargarRss(string dirFuenteRss)
{
    cout << "Descargando RSS desde " + dirFuenteRss;
    cout << endl;


    string strHttp = "http://www.";
    string nombre(dirFuenteRss);
    if (nombre.find_first_of(strHttp) == string::npos)
        return false;
    else
        nombre.erase(0, strHttp.size());

    size_t posBarra1 = nombre.find_first_of("/");
    size_t posBarra2 = nombre.find_last_of("/", (nombre.size()-1) );
    if ((posBarra1 != string::npos) && (posBarra2 != string::npos) && (posBarra2>posBarra1))
    {
        nombre[posBarra2] = '.';
        nombre.erase(posBarra1, posBarra2-posBarra1);
    } else
        return false;

    string separador = "-";
    size_t posSep;
    //cambia el separador porque se usa para el parser
    posSep = nombre.find_first_of(separador);
    while (posSep!=string::npos)
    {
      nombre[posSep]='_';
      posSep=nombre.find_first_of(separador, posSep+1);
    }

    string comando =  "rsstail -1 -d -u " + dirFuenteRss + " > "
                        + sourcePath() + "/fuentesRss/" + nombre + ".rss";


    system(comando.c_str());
    return true;
}

void Descargador::descargarRss(list<string> listaDeFuentesRss)
{
    for (list<string>::iterator it=listaDeFuentesRss.begin();
            it!=listaDeFuentesRss.end(); ++it)
            descargarRss(*it);
}


void Descargador::descargarTwt()
{
    string dirBase = "cd " + sourcePath() + "/twtPorAutor ;";
    string dirTty = getHomeDir() + "/ttytter.datos";
    string dirLogger = " -exts=/" + getHomeDir() + "/tweeterLogger.exts";
    string comando = dirBase + dirTty + dirLogger + " -daemon > "
                        + "../fuentesTwt/tweeterLogger.biografia";

    system(comando.c_str());

    cout << endl << endl;

}

string Descargador::getHomeDir()
{
    struct passwd *pw = getpwuid(getuid());

    char *homedir = pw->pw_dir;

    string homeDir(homedir);


    return homeDir;
}
