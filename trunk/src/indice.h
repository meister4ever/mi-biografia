#ifndef TP_INDICE_H
#define TP_INDICE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "serializable.h"
#include "arbolBMas.h"
#include "parser.h"
#include "registro.h"


class Indice : public Serializable, public ArbolBMas
{
private:
	ArbolBMas arbolBMas;
	Registro registro;

public:
	virtual void crearIndice()=0;
	void leerObjeto();
	void escribirObjeto();
};


#endif
