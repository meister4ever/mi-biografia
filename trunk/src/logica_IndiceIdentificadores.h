#ifndef INDICEIDENTIFICADORES_H_INCLUDED
#define INDICEIDENTIFICADORES_H_INCLUDED

#include <iostream>
#include "domain_AutorOcurrencia.h"
#include "domain_IdentificadorReferencias.h"
#include <list>
#include "logica_BlockTable.h"




class IndiceIdentificadores{
    public:
        IndiceIdentificadores(std::string path);
        IndiceIdentificadores();
        ~IndiceIdentificadores();
        int agregar(unsigned int posArch, std::string titulo);
        int recuperar(std::string titulo, std::list<unsigned int> *lista);
        int recuperarPlus(std::string titulo, std::list<unsigned int> *lista);
        int eliminarTodo();
        int pack();
        int packAppend();
    private:
        unsigned int obtenerId(std::string palabra);
        int buscarId(std::string titulo);
        int guardarOcurrencia(AutorOcurrencia* ocur);
        int printOcurrencias();
        unsigned int getRefLista();
        int guardarRefLista(std::list<unsigned int>* lista);
        int copylist(unsigned int reflista,std::list<unsigned int>*lista);
        BlockTable<IdentificadorReferencias>* hash;

        std::string temporalOcurrencias;
        std::string identificadores;
        std::string listaRefs;
        std::string tableName;
        std::string blocksName;

};

#endif // INDICEIDENTIFICADORES_H_INCLUDED
