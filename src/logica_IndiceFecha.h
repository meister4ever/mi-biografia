#ifndef INDICEFECHA_H_INCLUDED
#define INDICEFECHA_H_INCLUDED

#include <iostream>
#include "domain_FechaOcurrencia.h"
#include "logica_ArbolBmas.h"
#include "domain_FechaReferencias.h"
#include <list>



class IndiceFecha{
    public:
        IndiceFecha(std::string path);
        ~IndiceFecha();
        int agregar(unsigned int posArch, std::string fecha);
        int recuperar(std::string fecha, std::list<unsigned int> *lista);
        int eliminarTodo();
        int pack();
        int packAppend();
    private:
        unsigned int obtenerId(std::string palabra);
        int buscarId(std::string fecha);
        int guardarOcurrencia(FechaOcurrencia* ocur);
        int printOcurrencias();
        unsigned int getRefLista();
        int guardarRefLista(std::list<unsigned int>* lista);
        ArbolBmas<FechaReferencias> *arbol;
        int copylist(unsigned int reflista,std::list<unsigned int>*lista);

        //UN ARBOL
        std::string temporalOcurrencias;
        std::string fechas;
        std::string listaRefs;
        std::string arbolName;


};



#endif // INDICEFECHA_H_INCLUDED
