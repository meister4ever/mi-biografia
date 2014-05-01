#ifndef TP_REGISTRO_FIJO_H
#define TP_REGISTRO_FIJO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "registro.h"
#include "buffer.h"


class RegistroFijo : public Registro
{
private:
	int identificador;
	bool ocupado;
	Buffer buffer;

protected:
	int longitud;

public:
	bool escribir();
};


#endif
