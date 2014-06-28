#include "lz77.h"

/**
 * Constructor de la clase lz77. Si no se le especifica el tamaño
 * de ventana, se tomara una ventana de 16 bytes.
 *
 * \param[in] nVentana Tamaño de la ventana.
 */
lz77::lz77(int nVentana) {
  if (nVentana > 256) error(string("El tamaño máximo de ventana es de 256."));
  m_nVentana = nVentana;
  m_iIni = 0;
  m_iFin = nVentana - 1;
}

/**
 * Metodo para mostrar mensajes de error, y terminar la ejecución
 * del programa.
 *
 * \param[in] msg Mensaje de error para mostrar.
 */
void lz77::error(string msg) {
  cerr << "[Error] "<< msg << endl;
  //exit(-1);
}

/**
 * Leer un fichero de fuente y almacena el contenido en memoria.
 *
 * \param[in] sFile Direccion del fichero fuente que va a leer.
 */
void lz77::readFile(string sFile) {

  ifstream file(sFile.c_str(), ifstream::binary);
  if (!file.is_open()) error (string("No se pudo abrir el archivo de origen: ") + sFile);

  byte cCaracter;
  char buffer[1];

  while (!file.read(buffer, 1).eof()) {
    cCaracter = static_cast<byte>(buffer[0]);
    m_vBuffer.push_back(cCaracter);
  }

  file.close();

}

/**
 * Metodo que accede al fichero File, y escribe en este el
 * codigo que se le pasa por parametro.
 *
 * \param[in, out] File Referencia del fichero de escritura.
 * \param[in] Codigo cod77
 */
void lz77::writeCod77(ofstream &File, cod77 Codigo) {
  char buffer[3];
  buffer[0] = static_cast<char>(Codigo.first.first);
  buffer[1] = static_cast<char>(Codigo.first.second);
  buffer[2] = static_cast<char>(Codigo.second);
  File.write(buffer, 3);
}

/**
 * Metodo que implementa el algoritmo de compresion.
 *
 * \param[in] sFileIn Direccion del fichero fuente.
 * \param[in] sFileOut Direccion del fichero destino.
 *
 */
void lz77::compress (string sFileIn, string sFileOut) {

  ofstream file(sFileOut.c_str(), ofstream::binary);
  if (!file.is_open()) error (string("No se pudo abrir el archivo de destino: ") + sFileOut);

  readFile(sFileIn);

  unsigned int nBuffer = static_cast<unsigned int>(m_vBuffer.size());

  char tmp = static_cast<char>(nBuffer);
  char buffer[1];
  buffer[0] = tmp;
  file.write(buffer, 1);

  /**
   * - Primera fase. Creacion de la ventana inicial de
   *   busqueda.
   */
  unsigned int i;
  for (i = m_iIni; i < static_cast<unsigned int>(m_nVentana) && i < nBuffer; i++) {
    char tmp = static_cast<char>(m_vBuffer[i]);
    char buffer[1];
    buffer[0] = tmp;
    file.write(buffer, 1);
  }
  if ( i == nBuffer) return;

  /**
   * - Segunda parte. Generar las tuplas de la compresion por
   *   lz77.
   */
  for ( i = m_iFin + 1; i < nBuffer; i++) {
    byte c = m_vBuffer[i];
    byte c_tmp = c;
    byte c_mejor = c;

    unsigned int iIndex = m_iIni;
    unsigned int iIndex_tmp = m_iIni;

    unsigned int d = 0;
    unsigned int tam = 0;

    unsigned i_mejor = i;

    while (iIndex_tmp <= static_cast<unsigned int>(m_iFin)) {

      /**
       * En primer lugar se busca la primera coincidencia del siguiente caracter a comprimir
       * dentro del buffer de busqueda.
       */
      for (iIndex = iIndex_tmp ; iIndex < static_cast<unsigned int>(m_iFin); iIndex++) {
	if (m_vBuffer[iIndex] == c) {
	  break;
	}
      }
      if (iIndex == static_cast<unsigned int>(m_iFin)) {
	break;
      }

      unsigned int d_tmp = iIndex - m_iIni;

      /**
       * Luego se busca la primera diferencia, que indicara el final del prefijo
       * mas largo encontrado.
       */
      unsigned int i_tmp = i;
      for (iIndex = m_iIni + d_tmp + 1; iIndex < nBuffer; iIndex++, i_tmp++) {
	c_tmp = m_vBuffer[i_tmp + 1];
	if (m_vBuffer[iIndex] != c_tmp) {
	  break;
	}
      }

      /**
       * Nos guardamos el indice por donde nos hemos quedado.
       */
      iIndex_tmp = iIndex;

      unsigned int tam_tmp = iIndex - (m_iIni + d_tmp);

      /**
       * Y nos quedamos con el prefijo de maximo tamaño.
       */
      if (tam_tmp > tam) {
	tam = tam_tmp;
	d = d_tmp;
	i_mejor = i_tmp + 1;
	c_mejor = c_tmp;
      }
    }

    i = i_mejor;
    c = c_mejor;

    cod77 aux = pair<pair<unsigned int, unsigned int>, byte>(pair<unsigned int, unsigned int>(d, tam),c);

    /**
     * Escribir la tupla del lz77 en el fichero de salida.
     */
    writeCod77(file, aux);

    /**
     * Actualizamos la posicion de la ventana.
     */
    m_iFin = i;
    m_iIni = m_iFin - (m_nVentana - 1);
  }

  file.close();
}

/**
 * Metodo que implementa el algoritmo de descompresion.
 *
 * \param[in] sFileIn Direccion del fichero que se quiere descomprimir.
 * \param[in] sFileOut Direccion donde se dejara el fichero descomprimido.
 * \todo Implementar.
 */
void lz77::uncompress (string sFileIn, string sFileOut) {
  return;
}
