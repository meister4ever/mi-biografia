#ifndef INDEXER_H_INCLUDED
#define INDEXER_H_INCLUDED

#include <iostream>
#include "logica_IndiceAutor.h"
#include "logica_IndiceTitulo.h"
#include "logica_IndiceFecha.h"
#include "logica_IndiceIdentificadores.h"

class Indexer{
    public:
        Indexer();
        ~Indexer();
        int indexarFuentesDesde(int mode); //0 scratch ; 1 append
        int eliminarTodo();
    private:
        int estaIndexado(std::string);
        int copyToMaster(std::string from, std::string to);
        int indexarAutores(std::string header, unsigned int textPosition);
        int indexarTitulo(std::string header, unsigned int textPosition);
        int indexarFecha(std::string header, unsigned int textPosition);
        int indexarIdentificador(std::string header, unsigned int textPosition);
        IndiceAutor *autores;
        IndiceTitulo *titulos;
        IndiceFecha *fechas;
        IndiceIdentificadores *identificadores;
        std::string fromPath;
        std::string dest;
        std::string masterName;
};



#endif // INDEXER_H_INCLUDED
