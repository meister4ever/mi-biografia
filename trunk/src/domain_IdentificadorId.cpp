#include "domain_IdentificadorId.h"
#include <string.h>

IdentificadorId::IdentificadorId(const char* identificador, unsigned int id){
    unsigned int cant = strlen(identificador);
    memcpy(this->identificador,identificador,cant>99 ? 100 : cant+1);
    this->id =id;
}

IdentificadorId::IdentificadorId(){
}

IdentificadorId::~IdentificadorId(){
}

int IdentificadorId::comparar(Comparacion *obj) const{
    IdentificadorId *aid = (IdentificadorId*) obj;
    return strcmp(this->identificador,aid->getIdentificador());
}

unsigned int IdentificadorId::getId() const{
    return this->id;
}

const char* IdentificadorId::getIdentificador() const{
    return this->identificador;
}

std::ostream& operator << (std::ostream &out, IdentificadorId &ocur){
    const char* c = ocur.getIdentificador();
    out.write(c,100);
    unsigned int p = ocur.getId();
    out.write((char*) &p,sizeof(unsigned int));
    return out;
}

std::istream& operator >> (std::istream &out, IdentificadorId &ocur){
    unsigned int p;
    char c[100];
    out.read((char*) c,100);
    memcpy(ocur.identificador,c,100);
    out.read((char*) &p,sizeof(unsigned int));
    ocur.id = p;
    return out;
}
