#ifndef DOMAIN_AUTORID_H_INCLUDED
#define DOMAIN_AUTORID_H_INCLUDED

#include "logica_Comparable.h"
#include <iostream>


class AutorId : public Comparacion {
    public:
        AutorId(const char* autor, int id);
        AutorId();
        virtual ~AutorId();
        virtual int comparar(Comparacion *c) const;
        int getId() const;
        void setId(int newId) ;
        const char* getAutor() const;
        friend std::istream& operator >> (std::istream &out, AutorId &ocur);
        friend std::ostream& operator << (std::ostream &out, AutorId &ocur);
    private:
        char autor[100];
        int id;
};

#endif // DOMAIN_AUTORID_H_INCLUDED
