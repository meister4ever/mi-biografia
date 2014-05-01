#ifndef TP_REGISTRO_VAR_H
#define TP_REGISTRO_VAR_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "registro.h"
#include "buffer.h"


class RegistroVar : public Registro
{
private:
	int identificador;
	bool ocupado;
	Buffer buffer;

protected:
	int longitud;
	int longitudMax;

public:
	void escribir();
};


#endif
