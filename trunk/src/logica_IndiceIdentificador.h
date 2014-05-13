#ifndef INDICEIDENTIFICADOR_H_INCLUDED
#define INDICEIDENTIFICADOR_H_INCLUDED

#include <iostream>
#include "domain_IdentificadorOcurrencia.h"
#include "logica_ArbolBmas.h"
#include "domain_IdentificadorReferencias.h"
#include <list>



class IndiceIdentificador{
    public:
        IndiceIdentificador(std::string path);
        ~IndiceIdentificador();
        int agregar(unsigned int posArch, std::string titulo);
        int recuperar(std::string titulo, std::list<unsigned int> *lista);
        int eliminarTodo();
        int pack();
        int packAppend();
    private:
        unsigned int obtenerId(std::string palabra);
        int buscarId(std::string titulo);
        int guardarOcurrencia(IdentificadorOcurrencia* ocur);
        int printOcurrencias();
        unsigned int getRefLista();
        int guardarRefLista(std::list<unsigned int>* lista);
        ArbolBmas<IdentificadorReferencias> *arbol;
        int copylist(unsigned int reflista,std::list<unsigned int>*lista);

        //UN ARBOL
        std::string temporalOcurrencias;
        std::string identificadores;
        std::string listaRefs;
        std::string arbolName;


};



#endif // INDICEIDENTIFICADOR_H_INCLUDED
