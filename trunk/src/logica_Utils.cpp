#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include "runtimeConfig.h"
#include "logica_Utils.h"
using namespace std;

int Utils::splitString(string s, char del, list<string> *ptr){
    string s2;
    istringstream is(s);
    while (getline(is,s2,del)){
        ptr->push_back(s2);
    }
    return 0;
}


string Utils::getClaveFromHeader(string header){
    list<string> *ptr = new list<string>;
    Utils::splitString(header,'-',ptr);
    ostringstream s;
    s << Utils::uniformizarString(ptr->front()) << "-";
    ptr->pop_front();
    if(ptr->size() == 3){
        ptr->pop_front();
    }
    s << Utils::uniformizarString(ptr->front()) << "-";
    ptr->pop_front();
    s << Utils::uniformizarString(ptr->front());
    delete ptr;
    return s.str();
}

int Utils::getAutoresFromHeader(string header, list<string>* lista){
    list<string> *ptr = new list<string>;
    Utils::splitString(header,'-',ptr);
    string s = ptr->front();
    delete ptr;
    string s2;
    istringstream is(s);
    while (getline(is,s2,';')){
        lista->push_back(Utils::uniformizarString(s2));
    }
    return 0;
}

int Utils::getTitulosFromHeader(string header, list<string>* lista){
    list<string> *ptr = new list<string>;
    Utils::splitString(header,'-',ptr);
    ptr->pop_back();
    string s = ptr->back();
    delete ptr;
    string s2;
    istringstream is(s);
    while (getline(is,s2,';')){
        lista->push_back(Utils::uniformizarString(s2));
    }
    return 0;
}


string Utils::getTituloFromHeader(string header){
    list<string> *ptr = new list<string>;
    Utils::splitString(header,'-',ptr);
    ptr->pop_front();
    if(ptr->size() == 3){
        ptr->pop_front();
    }
    string titulo = Utils::uniformizarString(ptr->front());
    delete ptr;
    return titulo;
}


string Utils::uniformizarString(string source){
    ostringstream dest;
    char c;
    for(unsigned int i=0; i < source.size();i++){
        c = source.at(i);
        if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
            dest << c;
        }else if(c >= 'A' && c <= 'Z'){
            dest << (char)tolower(c);
        }else{
            if (c == '\xc3') {
                i++;
                c = source.at(i);
                switch (c) {
                    case '\xa1':
                        dest << 'a';
                        break;

                    case '\x81':
                        dest << 'a';
                        break;

                    case '\xa9':
                        dest << 'e';
                        break;

                    case '\x89':
                        dest << 'e';
                        break;

                    case '\xad':
                        dest << 'i';
                        break;

                    case '\x8d':
                        dest << 'i';
                        break;

                    case '\xb3':
                        dest << 'o';
                        break;

                    case '\x93':
                        dest << 'o';
                        break;

                    case '\xba':
                        dest << 'u';
                        break;

                    case '\x9a':
                        dest << 'u';
                        break;

                    case '\xb1':
                        dest << 'n';
                        dest << 'i';
                        break;

                    case '\x91':
                        dest << 'n';
                        dest << 'i';
                        break;

                    default:
                        break;
                }
            }
        }
    }
    return dest.str();
}

int Utils::existeArchivo(string archivo){
    ifstream file;
    file.open(archivo.c_str());
    bool existe = file.good();
    file.close();
    return existe;
}

string Utils::IntToStr(int n)
{
    stringstream result;
    result << n;
    return result.str();
}


void Utils::dividirRss(string fileName, int contador, int fecha) {
    string line = "";
    ifstream inFile;
    string filePathName = sourcePath() + "/fuentesRss/" + fileName;
    inFile.open(filePathName.c_str());
    string marcador1 = "Title:";
    string marcador2 = "Description:";
    string separador = "-";
    string salidaStr;

    ofstream salida;

    int i=0;
    getline(inFile,line);
    string tempStr;
    while (!inFile.eof()) {

      salidaStr = sourcePath() + "/rss_" +  IntToStr(contador) + "_" + IntToStr(i) +".txt";
      salida.open(salidaStr.c_str(), ios::trunc);
      salida << fileName + separador + IntToStr(fecha) + separador;
      tempStr = line.substr(line.size()>marcador1.size() ?
			      marcador1.size() : 0) + separador;
      salida << tempStr;

      getline(inFile,line);
      tempStr = line.substr(line.size()>marcador2.size() ?
			      marcador2.size() : 0) + separador;
      salida << tempStr;

      salida.close();
      getline(inFile,line);

      i++;
    }
    inFile.close();
}


void Utils::dividirRssFiles (int fecha) {
  DIR *dir;
  struct dirent *ent;
  string dirFull = sourcePath() + "/fuentesRss";
  if ((dir = opendir (dirFull.c_str())) != NULL) {
    readdir (dir);
    readdir (dir);
    string comp;
    int contador = 0;
    while ((ent = readdir (dir)) != NULL) {
        comp = ent->d_name;
        if (comp.compare("..")!=0) {
            dividirRss(ent->d_name, contador, fecha);
            contador++;
        }
    }
    closedir (dir);
  } else {
  }
}


void Utils::dividirTwt(string fileName, int contador, int fecha) {
    string line = "";

    string filePathName = sourcePath() + "/fuentesTwt/" + fileName;

    ifstream inFile(filePathName.c_str());
    if (inFile.is_open())
        inFile.close();

    inFile.open(filePathName.c_str(), ifstream::in);
    string marcador = "TP_DATOS";
    string separador = "-";

    while (!inFile.eof() && line.compare(marcador)!=0)
      getline(inFile,line);

    string salidaStr;

    ofstream salida;

    int i=0;
    getline(inFile,line);
    while (!inFile.eof() && line.compare(marcador)!=0) {
      salidaStr = sourcePath() + "/twt_" +  IntToStr(contador) + "_" + IntToStr(i) +".txt";
      salida.open(salidaStr.c_str(), ios::trunc);


      size_t pos1 = line.find_first_of("<");
      size_t pos_fin = line.find_first_of(">", pos1+1);


      if ((pos1!=string::npos) && (pos_fin!=string::npos)){
	  salida << line.substr(pos1+1, pos_fin-pos1-1) + separador + IntToStr(fecha) + separador;

	  pos1 = line.find_first_of("@#");

	  size_t pos2 = line.find_first_of(": ",pos1+1);

	if ((pos1!=string::npos) && (pos2!=string::npos))
	  salida << line.substr(pos1+1, pos2-pos1-1) + separador;

	salida << line.substr(pos_fin+1) << endl;
      }
      salida.close();
      getline(inFile,line);
      i++;
    }
    inFile.close();
}

void Utils::dividirTwtFiles (int fecha) {
  DIR *dir;
  struct dirent *ent;
  string dirFull = sourcePath() + "/fuentesTwt";
  if ((dir = opendir (dirFull.c_str())) != NULL) {
    readdir (dir);
    int contador = 0;
    string comp;
    while ((ent = readdir (dir)) != NULL) {
      comp = ent->d_name;
      if (comp.compare("..")!=0) {
        dividirTwt(ent->d_name, contador, fecha);
        contador++;
      }
    }
    closedir (dir);
  } else {
  }
}

int Utils::getFecha()
{
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    int fecha = aTime->tm_year + 1900; // da anio desde 1900

    return fecha;
}

