#ifndef DOMAIN_IDENTIFICADORID_H_INCLUDED
#define DOMAIN_IDENTIFICADORID_H_INCLUDED

#include "logica_Comparable.h"
#include <iostream>


class IdentificadorId : public Comparacion {
    public:
        IdentificadorId(const char* identificador, int id);
        IdentificadorId();
        virtual ~IdentificadorId();
        virtual int comparar(Comparacion *c) const;
        int getId() const;
        void setId(int newId) ;
        const char* getIdentificador() const;
        friend std::istream& operator >> (std::istream &out, IdentificadorId &ocur);
        friend std::ostream& operator << (std::ostream &out, IdentificadorId &ocur);
    private:
        char identificador[100];
        int id;
};

#endif // DOMAIN_IDENTIFICADORID_H_INCLUDED
