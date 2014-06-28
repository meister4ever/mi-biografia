#ifndef _LZ77_H
#define _LZ77_H

#include "tipos.h"

/**
 * \def DEFAULT_WINDOW
 * Tamaño de ventana por defecto de 16 bytes.
 */
#define DEFAULT_WINDOW 16

using namespace std;

/**
 * \class lz77
 *
 * Clase que implementa la compresiOn de ficheros por el metodo de
 * diccionario LZ77. Este metodo de compresion no se ha añadido
 * al programa principal, ya que falta implementar el metodo de
 * descompresion. Para realizar pruebas de compresion se
 * recomienda usar el programa de test: test_lz77.
 */

class lz77 {

 private:

  /**
   * \var m_vBuffer
   *
   * Buffer que contiene todo el fichero leido.
   */
  vector<byte> m_vBuffer;

  /**
   * \var m_iIni
   *
   * Indices inicial de la ventana de compresion.
   */
  int m_iIni;

  /**
   * \var m_iFin
   *
   * Indices final de la ventana de compresion.
   */
  int m_iFin;

  /**
   * \var m_nVentana
   *
   * Tamaño de la ventana
   */
  int m_nVentana;

  /**
   * \var m_vTablaCod
   *
   * Tabla donde se almacena cada una de las entradas de pares codificantes.
   */
  vector<cod77> m_vTablaCod;

  void readFile (string sFile);
  void writeCod77(ofstream &File, cod77 Codigo);

  void error(string msg);

 public:

  lz77(int nVentana = DEFAULT_WINDOW);

  void compress (string sFileIn, string sFileOut);
  void uncompress (string sFileIn, string sFileOut);

};

#endif


