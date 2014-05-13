#ifndef DOMAIN_OCURRENCIAFECHA_H_INCLUDED
#define DOMAIN_OCURRENCIAFECHA_H_INCLUDED
#include "logica_Comparable.h"
#include <iostream>


// contiene el par (FechaId, DocumentoId)
class FechaOcurrencia : public Comparacion{
    public:
        FechaOcurrencia(unsigned int fechaId, unsigned int documentoId);
        FechaOcurrencia();
        virtual ~FechaOcurrencia();
        virtual int comparar(Comparacion *c) const;
        unsigned int getFechaId() const;
        unsigned int getDocumentoId() const;
        friend std::istream& operator >> (std::istream &out, FechaOcurrencia &ocur);
        friend std::ostream& operator << (std::ostream &out, FechaOcurrencia &ocur);
    private:
        unsigned int documentoId;
        unsigned int fechaId;

};

#endif // DOMAIN_OCURRENCIAFECHA_H_INCLUDED
