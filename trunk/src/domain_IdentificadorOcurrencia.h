#ifndef DOMAIN_OCURRENCIAIDENTIFICADOR_H_INCLUDED
#define DOMAIN_OCURRENCIAIDENTIFICADOR_H_INCLUDED
#include "logica_Comparable.h"
#include <iostream>


// contiene el par (IdentificadorId, DocumentoId)
class IdentificadorOcurrencia : public Comparacion{
    public:
        IdentificadorOcurrencia(unsigned int tituloId, unsigned int documentoId);
        IdentificadorOcurrencia();
        virtual ~IdentificadorOcurrencia();
        virtual int comparar(Comparacion *c) const;
        unsigned int getIdentificadorId() const;
        unsigned int getDocumentoId() const;
        friend std::istream& operator >> (std::istream &out, IdentificadorOcurrencia &ocur);
        friend std::ostream& operator << (std::ostream &out, IdentificadorOcurrencia &ocur);
    private:
        unsigned int documentoId;
        unsigned int tituloId;

};

#endif // DOMAIN_OCURRENCIAIDENTIFICADOR_H_INCLUDED
