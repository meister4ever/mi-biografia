#ifndef _LZ78_H
#define _LZ78_H

#include "tipos.h"

using namespace std;

/**
 * \class lz78
 *
 * Clase que implementa la compresion de ficheros por el metodo de
 * dicionario LZ78.
 *
 * Se usan los metodos:
 * - compress
 * - uncompress
 *
 * Para comprimir y descomprimir, respectivamente.
 */

class lz78 {
 private:

  /**
   * \var vBuffer
   * Buffer que contiene todo el fichero leido
   */
  vector<byte> vBuffer;

  /**
   * \var iComp
   * Indice de compresion
   */
  int iComp;

  /**
   * \var cuentaIndi
   * Cuenta de Indices necesaria para la actualizacion dinamica de bits.
   */
  int cuentaIndi;

  bool readChar(byte &c);

  /**
   * \var vTablaCod
   * Tabla donde se almacena cada una de las entradas de pares codificantes.
   */
  vector<cod78> vTablaCod;

  /**
   * \var mTablaCod
   * Mapa donde se almacena una relacion lista de chars - indice.
   * El indice se utilizara; para acceder al vector vTablaCod sin recorrerlo.
   */
  map<list<byte>,int> mTablaCod;

  /**
   * \var iIndice
   * Indice del mapa y del vector
   */
  int iIndice;

  void error(string msg);

 public:
  lz78();
  void readFile (string sFile);
  void compress (string sFile);
  void readCom (string sFile);
  void uncompress (string sFile);

  string int2bin(int iData);
  int bin2int(string sSecuencia);

  void obtainElem(list<byte> &cadena, int &i);

};

#endif


