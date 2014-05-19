#ifndef INDICETITULO_H_INCLUDED
#define INDICETITULO_H_INCLUDED

#include <iostream>
#include "domain_TituloOcurrencia.h"
#include "logica_ArbolBmas.h"
#include "domain_TituloReferencias.h"
#include <list>



class IndiceTitulo{
    public:
        IndiceTitulo(std::string path);
        ~IndiceTitulo();
        int agregar(unsigned int posArch, std::string titulo);
        int recuperar(std::string titulo, std::list<unsigned int> *lista);
        int eliminarTodo();
        int pack();
        int packAppend();
    private:
        unsigned int obtenerId(std::string palabra);
        int buscarId(std::string titulo);
        int guardarOcurrencia(TituloOcurrencia* ocur);
        int printOcurrencias();
        unsigned int getRefLista();
        int guardarRefLista(std::list<unsigned int>* lista);
        ArbolBmas<TituloReferencias> *arbol;
        int copylist(unsigned int reflista,std::list<unsigned int>*lista);

        //UN ARBOL
        std::string temporalOcurrencias;
        std::string titulos;
        std::string listaRefs;
        std::string arbolName;


};



#endif // INDICETITULO_H_INCLUDED
