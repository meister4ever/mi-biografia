#ifndef DOMAIN_TITULOID_H_INCLUDED
#define DOMAIN_TITULOID_H_INCLUDED

#include "logica_Comparable.h"
#include <iostream>


class TituloId : public Comparacion {
    public:
        TituloId(const char* titulo, unsigned int id);
        TituloId();
        virtual ~TituloId();
        virtual int comparar(Comparacion *c) const;
        unsigned int getId() const;
        const char* getTitulo() const;
        friend std::istream& operator >> (std::istream &out, TituloId &ocur);
        friend std::ostream& operator << (std::ostream &out, TituloId &ocur);
    private:
        char titulo[100];
        unsigned int id;
};

#endif // DOMAIN_TITULOID_H_INCLUDED
