#include "domain_TituloId.h"
#include <string.h>

TituloId::TituloId(const char* titulo, unsigned int id){
    unsigned int cant = strlen(titulo);
    memcpy(this->titulo,titulo,cant>99 ? 100 : cant+1);
    this->id =id;
}

TituloId::TituloId(){
}

TituloId::~TituloId(){
}

int TituloId::comparar(Comparacion *obj) const{
    TituloId *aid = (TituloId*) obj;
    return strcmp(this->titulo,aid->getTitulo());
}

unsigned int TituloId::getId() const{
    return this->id;
}

const char* TituloId::getTitulo() const{
    return this->titulo;
}

std::ostream& operator << (std::ostream &out, TituloId &ocur){
    const char* c = ocur.getTitulo();
    out.write(c,100);
    unsigned int p = ocur.getId();
    out.write((char*) &p,sizeof(unsigned int));
    return out;
}

std::istream& operator >> (std::istream &out, TituloId &ocur){
    unsigned int p;
    char c[100];
    out.read((char*) c,100);
    memcpy(ocur.titulo,c,100);
    out.read((char*) &p,sizeof(unsigned int));
    ocur.id = p;
    return out;
}
