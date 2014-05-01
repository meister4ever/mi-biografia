#ifndef TP_ARCHIVO_ID_H
#define TP_ARCHIVO_ID_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "serializable.h"
#include "hashExt.h"
#include "registro.h"


class ArchivoId : public Serializable, public HashExt
{
private:
	HashExt hashExt;
	Registro registro;

public:
	void leerObjeto();
	void escribirObjeto();
};

#endif
