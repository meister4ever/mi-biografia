#ifndef TP_REGISTRO_FIJO_H
#define TP_REGISTRO_FIJO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "registro.h"


class RegistroFijo : public Registro
{
private:
	std::string identificador;
	bool ocupado;

protected:
	int longitud;

public:
    RegistroFijo(std::string id, bool ocupado, int longitud);
    ~RegistroFijo();
	bool escribir();

	std::string getIdentificador();
    bool estaOcupado();
    int getLongitud();

};


#endif
