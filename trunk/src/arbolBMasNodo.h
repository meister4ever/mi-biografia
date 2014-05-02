#ifndef TP_ARBOL_B_MAS_NODO_H
#define TP_ARBOL_B_MAS_NODO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include "registro.h"

class ArbolBMasNodo
{
private:
	std::list<Registro> registros;
	std::list<ArbolBMasNodo> hijos;
};

#endif
