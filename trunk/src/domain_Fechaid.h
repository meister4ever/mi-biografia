#ifndef DOMAIN_FECHAID_H_INCLUDED
#define DOMAIN_FECHAID_H_INCLUDED

#include "logica_Comparable.h"
#include <iostream>


class FechaId : public Comparacion {
    public:
        FechaId(const char* fecha, int id);
        FechaId();
        virtual ~FechaId();
        virtual int comparar(Comparacion *c) const;
        int getId() const;
        void setId(int newId) ;
        const char* getFecha() const;
        friend std::istream& operator >> (std::istream &out, FechaId &ocur);
        friend std::ostream& operator << (std::ostream &out, FechaId &ocur);
    private:
        char fecha[100];
        int id;
};

#endif // DOMAIN_FECHAID_H_INCLUDED
