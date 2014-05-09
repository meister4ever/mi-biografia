#ifndef DOMAIN_OCURRENCIATITULO_H_INCLUDED
#define DOMAIN_OCURRENCIATITULO_H_INCLUDED
#include "logica_Comparable.h"
#include <iostream>


// contiene el par (TituloId, DocumentoId)
class TituloOcurrencia : public Comparacion{
    public:
        TituloOcurrencia(unsigned int tituloId, unsigned int documentoId);
        TituloOcurrencia();
        virtual ~TituloOcurrencia();
        virtual int comparar(Comparacion *c) const;
        unsigned int getTituloId() const;
        unsigned int getDocumentoId() const;
        friend std::istream& operator >> (std::istream &out, TituloOcurrencia &ocur);
        friend std::ostream& operator << (std::ostream &out, TituloOcurrencia &ocur);
    private:
        unsigned int documentoId;
        unsigned int tituloId;

};

#endif // DOMAIN_OCURRENCIATITULO_H_INCLUDED
