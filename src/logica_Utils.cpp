#include <iostream>
#include <sstream>
#include <cstdio>
#include <fstream>
#include <stdio.h>
#include "runtimeConfig.h"
#include "logica_Utils.h"
#include "logica_ArbolBmas.h"
#include "domain_RegistroGenerico.h"
#include "domain_TituloReferencias.h"
#include "domain_FechaReferencias.h"
#include "domain_AutorReferencias.h"

using namespace std;

int Utils::splitString(string s, string del, list<string> *ptr){

std::string delimiter = del;

size_t pos = 0;
std::string token;
while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    ptr->push_back(token);
    s.erase(0, pos + delimiter.length());
}
    ptr->push_back(s);
    return 0;
}


string Utils::getClaveFromHeader(string header){
    list<string> *ptr = new list<string>;
    Utils::splitString(header,"╗",ptr);
    ostringstream s;
    s << Utils::uniformizarString(ptr->front()) << "╗";
    ptr->pop_front();
    ptr->pop_front();
    if(ptr->size() == 3){
        ptr->pop_front();
    }
    s << Utils::uniformizarString(ptr->front()) << "╗";
    ptr->pop_front();
    s << Utils::uniformizarString(ptr->front());
    delete ptr;
    return s.str();
}

int Utils::getAutoresFromHeader(string header, list<string>* lista){
    list<string> *ptr = new list<string>;
    Utils::splitString(header,"╗",ptr);
    ptr->pop_front();
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
    Utils::splitString(header,"╗",ptr);
    ptr->pop_front();
    ptr->pop_front();
    ptr->pop_front();
    string s = ptr->front();
    delete ptr;
    string s2;
    istringstream is(s);
    while (getline(is,s2,';')){
        lista->push_back(Utils::uniformizarString(s2));
    }
    return 0;
}

int Utils::getFechasFromHeader(string header, list<string>* lista){
    list<string> *ptr = new list<string>;
    Utils::splitString(header,"╗",ptr);
    ptr->pop_front();
    ptr->pop_front();
    string s = ptr->front();
    delete ptr;
    string s2;
    istringstream is(s);
    while (getline(is,s2,';')){
        lista->push_back(Utils::uniformizarString(s2));
    }
    return 0;
}

int Utils::getIdentificadorFromHeader(string header, list<string>* lista){
    list<string> *ptr = new list<string>;
    Utils::splitString(header,"╗",ptr);
    string s = ptr->front();
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
    Utils::splitString(header,"╗",ptr);
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


void Utils::dividirRss(string fileName, int contador, string fecha) {
    string line = "";
    ifstream inFile;
    string filePathName = sourcePath() + "/fuentesRss/" + fileName;
    inFile.open(filePathName.c_str());
    string marcador1 = "Title:";
    string marcador2 = "Description:";
    string separador = "╗";
    string salidaStr;

    ofstream salida;

    int i=0;
    getline(inFile,line);
    string tempStr;
    while (!inFile.eof()) {
      salidaStr = sourcePath() + "/rss_" +  IntToStr(contador) + "_" + IntToStr(i) +".txt";
      salida.open(salidaStr.c_str(), ios::trunc);
      salida << "N" + IntToStr(contador) + IntToStr(i) + separador + fileName + separador + fecha + separador;
      tempStr = line.substr(line.size()>marcador1.size() ?
			      marcador1.size() : 0) + separador;
      salida << tempStr;

      getline(inFile,line);
      tempStr = line.substr(line.size()>marcador2.size() ?
			      marcador2.size() : 0);
      salida << tempStr;

      salida.close();
      getline(inFile,line);

      i++;
    }
    inFile.close();
}


void Utils::dividirRssFiles (string fecha) {
  DIR *dir;
  struct dirent *ent;
  string dirFull = sourcePath() + "/fuentesRss";
  if ((dir = opendir (dirFull.c_str())) != NULL) {
    string comp;
    int contador = 0;
    while ((ent = readdir (dir)) != NULL) {
        comp = ent->d_name;
      if (comp.compare("..")!=0 && comp.compare(".")!=0) {
            dividirRss(ent->d_name, contador, fecha);
            contador++;
        }
    }
    closedir (dir);
  } else {
  }
}


void Utils::dividirTwt(string fileName, int contador, string fecha) {
    string line = "";

    string filePathName = sourcePath() + "/fuentesTwt/" + fileName;

    ifstream inFile(filePathName.c_str());
    if (inFile.is_open())
        inFile.close();

    inFile.open(filePathName.c_str(), ifstream::in);
    string marcador = "TP_DATOS";
    string separador = "╗";

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
	  salida << "T" + IntToStr(contador) + IntToStr(i) + separador
                + line.substr(pos1+1, pos_fin-pos1-1) + separador + fecha + separador;

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

void Utils::dividirTwtFiles (string fecha) {
  DIR *dir;
  struct dirent *ent;
  string dirFull = sourcePath() + "/fuentesTwt";
  if ((dir = opendir (dirFull.c_str())) != NULL) {
    int contador = 0;
    string comp;
    while ((ent = readdir (dir)) != NULL) {
      comp = ent->d_name;
      if (comp.compare("..")!=0 && comp.compare(".")!=0) {
        dividirTwt(ent->d_name, contador, fecha);
        contador++;
      }
    }
    closedir (dir);
  } else {
  }
}

string Utils::getFecha()
{
    string separador = "/";
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    string fecha = IntToStr(aTime->tm_mday) + separador + IntToStr(aTime->tm_mon) + separador + IntToStr(aTime->tm_year + 1900); // da anio desde 1900

    return fecha;
}

void Utils::imprimir(std::string ArbolName)
{
    string filePathName = destPath() + ArbolName;
    ArbolBmas<TituloReferencias>* arbol= new ArbolBmas<TituloReferencias>();
    arbol->abrir(filePathName.c_str());
    arbol->imprimir();
    arbol->cerrar();
}

void Utils::imprimir1(std::string ArbolName)
{
    string filePathName = destPath() + ArbolName;
    ArbolBmas<AutorReferencias>* arbol= new ArbolBmas<AutorReferencias>();
    arbol->abrir(filePathName.c_str());
    arbol->imprimir();
    arbol->cerrar();
}

void Utils::imprimir2(std::string ArbolName)
{
    string filePathName = destPath() + ArbolName;
    ArbolBmas<FechaReferencias>* arbol= new ArbolBmas<FechaReferencias>();
    arbol->abrir(filePathName.c_str());
    arbol->imprimir();
    arbol->cerrar();
}

/**
 * Convierte de un binario, repersentado por una cadena de caracteres 0 y 1,
 * a un unsigned char, con la codificacion correspondiente en binario real.
 * La secuencia tiene que ser exactamente de 8 caracteres.
 *
 * \author Iv&aacute;n Rodr&iacute;guez Sastre
 * \author Marcos Gabarda Inat
 * \param sSecuencia string
 * \return unsigned char
 */
byte bin2char(string sSecuencia) {

  if (sSecuencia.size() != 8) return '\0';

  int nLongitud = static_cast<int>(sSecuencia.size());
  byte nSum = 0;
  for (int i = 0; i < nLongitud; i++) {
    unsigned char c = sSecuencia[i];
    int n = 0;
    if (c == '0') {
      n = 0;
    } else if (c == '1'){
      n = 1;
    }
    nSum += static_cast<unsigned int>(n*pow(2.0, (nLongitud - 1) - i));
  }
  byte cOcteto;
  cOcteto = static_cast<byte>(nSum);
  return cOcteto;
}

/**
 * Convierte de un unsigned char a un binario, representado por una
 * cadena de 0's y 1's, con la codificacion correspondiente en binario real.
 * \author Iv&aacute;n Rodr&iacute;guez Sastre
 * \author Marcos Gabarda Inat
 * \param[in] cData unsigned char
 * \return string
 */
string char2bin(byte cData) {
  string sBuffer;
  string sBufferFinal;
  if(cData==0){
    for (int i = 0; i < 8; i++ )
      sBufferFinal.push_back('0');
    return sBufferFinal;
  }
  else{
    for (byte i = cData; i > 1; i/=2) {
      byte nResto = i%2;
      if (nResto == 0) {
	sBuffer.push_back('0');
      } else {
			  sBuffer.push_back('1');
      }
    }
    sBuffer.push_back('1');
    int nLongitud = static_cast<int>(sBuffer.size());
    for (int i = 0; i < (8 - nLongitud); i++ ) sBufferFinal.push_back('0');
    for(int i = nLongitud - 1; i >= 0; i-- ) sBufferFinal.push_back(sBuffer[i]);
    return sBufferFinal;
  }
}

