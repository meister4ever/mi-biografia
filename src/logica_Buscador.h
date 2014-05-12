#ifndef BUSCADOR_H_INCLUDED
#define BUSCADOR_H_INCLUDED

#include "logica_IndiceAutor.h"
#include "logica_IndiceTitulo.h"
#include "logica_IndiceFecha.h"

class Buscador{
    public:
        Buscador();
        ~Buscador();
        int buscarPorAutor(std::string autor);
        int buscarPorTitulo(std::string titulo);
        int buscarPorFecha(std::string fecha);
        int listarTodo();
    private:
        int imprimirFuente(unsigned int ref);
        IndiceAutor *autores;
        IndiceTitulo *titulos;
        IndiceFecha *fechas;
        std::string dest;
        std::string outName;
};


#endif // BUSCADOR_H_INCLUDED
