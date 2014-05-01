#ifndef TP_ARCHIVO_H
#define TP_ARCHIVO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>


class Archivo
{
protected:
	int nombre;
	int ruta;

public:
	Archivo();
	void leer();
	void escribir();
	void borrar();
};

#endif
