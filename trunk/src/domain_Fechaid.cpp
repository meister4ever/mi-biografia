#include "domain_Fechaid.h"
#include <string.h>

FechaId::FechaId(const char* fecha,  int id){
    unsigned int cant = strlen(fecha);
    memcpy(this->fecha,fecha,cant>99 ? 100 : cant+1);
    this->id =id;
}

FechaId::FechaId(){
}

FechaId::~FechaId(){
}

int FechaId::comparar(Comparacion *obj) const{
    FechaId *aid = (FechaId*) obj;
    return strcmp(this->fecha,aid->getFecha());
}

int FechaId::getId() const{
    return this->id;
}

void FechaId::setId(int newId) {
    this->id =newId;
}

const char* FechaId::getFecha() const{
    return this->fecha;
}

std::ostream& operator << (std::ostream &out, FechaId &ocur){
    const char* c = ocur.getFecha();
    out.write(c,100);
    unsigned int p = ocur.getId();
    out.write((char*) &p,sizeof(unsigned int));
    return out;
}

std::istream& operator >> (std::istream &out, FechaId &ocur){
    unsigned int p;
    char c[100];
    out.read((char*) c,100);
    memcpy(ocur.fecha,c,100);
    out.read((char*) &p,sizeof(unsigned int));
    ocur.id = p;
    return out;
}

