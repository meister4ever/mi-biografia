#ifndef LOGICA_COMPARABLE_H_INCLUDED
#define LOGICA_COMPARABLE_H_INCLUDED

/*
*   Clase abstracta que permite que dos objetos se comparen entre si
*/
class Comparacion{
    public:
    virtual int comparar(Comparacion* c) const = 0;
};

#endif // LOGICA_COMPARABLE_H_INCLUDED
