#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "registroFijo.h"

RegistroFijo::RegistroFijo(std::string id, bool ocupado, int longitud)
{
    this->identificador = id;
    this->ocupado = ocupado;
    this->longitud = longitud;

}

RegistroFijo::~RegistroFijo()
{

}

bool RegistroFijo::escribir()
{
}

std::string RegistroFijo::getIdentificador()
{
    return this->identificador;
}

bool RegistroFijo::estaOcupado()
{
    return this->ocupado;
}

int RegistroFijo::getLongitud()
{
    return this->longitud;
}
