#ifndef TP_ARCHIVO_BLOQUES_H
#define TP_ARCHIVO_BLOQUES_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "archivo.h"
#include "bloque.h"



class ArchivoBloques : public Archivo
{
private:
	int tamanioBloque;
	int posPrimerReg;
	std::list<Bloque> bloquesLibres;

public:
    ArchivoBloques();
};

#endif
