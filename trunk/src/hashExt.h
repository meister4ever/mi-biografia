#ifndef TP_HASH_EXT_H
#define TP_HASH_EXT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>


#include "bloque.h"


class HashExt
{
private:
	int tabla;
	int bloques;
	std::list<Bloque> bloquesLibres;
	Bloque bloque;

private:
	void fhash();
public:
	HashExt();
	void insertar();
	void quitar();
	void buscar();
};

#endif
