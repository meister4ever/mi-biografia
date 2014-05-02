#ifndef TP_ARBOL_B_MAS_H
#define TP_ARBOL_B_MAS_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "arbolBMasNodo.h"

class ArbolBMas
{
private:
	ArbolBMasNodo raiz;
	int altura;
	int cantidadNodos;
	ArbolBMasNodo arbolBMasNodo;

public:
	bool insertar();
	bool quitar();
	bool modificar();
	int buscar(std::string c);
};

#endif
