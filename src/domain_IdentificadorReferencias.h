#ifndef DOMAIN_IDENTIFICADORREFERENCIAS_H_INCLUDED
#define DOMAIN_IDENTIFICADORREFERENCIAS_H_INCLUDED
#include "domain_RegistroGenerico.h"

class IdentificadorReferencias : public RegistroGenerico {
    public:
        IdentificadorReferencias(unsigned int clave);
        IdentificadorReferencias();
        ~IdentificadorReferencias();
        virtual int serializar(SerialBuffer *buffer);
        virtual void deserializar(SerialBuffer *buffer);
        unsigned int getRef1();
        unsigned int getRef2();
        unsigned int getRef3();
        unsigned int getRefLista();
        unsigned int getCant();
        unsigned int* getRefs();
        void setRef1(unsigned int ref);
        void setRef2(unsigned int ref);
        void setRef3(unsigned int ref);
        void setRefLista(unsigned int ref);
        void setCant(unsigned int cant);

        // Devuelve el tamanio en bytes que ocuparia persistir la clase.
        static size_t getTamanioEnBytes();

    private:
        unsigned int refs[3];
        unsigned int refLista;
        unsigned int cant;

};

#endif // DOMAIN_IDENTIFICADORREFERENCIAS_H_INCLUDED

