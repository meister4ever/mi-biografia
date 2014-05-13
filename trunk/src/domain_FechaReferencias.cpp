#include "domain_FechaReferencias.h"

FechaReferencias::FechaReferencias(){
}

FechaReferencias::FechaReferencias(unsigned int clave){
    this->setClave(clave);
}

FechaReferencias::~FechaReferencias(){
}

unsigned int FechaReferencias::getCant(){
    return this->cant;
}

unsigned int FechaReferencias::getRef1(){
    return this->refs[0];
}

unsigned int FechaReferencias::getRef2(){
    return this->refs[1];
}

unsigned int FechaReferencias::getRef3(){
    return this->refs[2];
}

unsigned int FechaReferencias::getRef4(){
    return this->refs[3];
}

unsigned int FechaReferencias::getRef5(){
    return this->refs[4];
}

unsigned int FechaReferencias::getRefLista(){
    return this->refLista;
}

void FechaReferencias::setCant(unsigned int cant){
    this->cant= cant;
}

void FechaReferencias::setRef1(unsigned int ref){
    this->refs[0] = ref;
}

void FechaReferencias::setRef2(unsigned int ref){
    this->refs[1] = ref;
}

void FechaReferencias::setRef3(unsigned int ref){
    this->refs[2] = ref;
}

void FechaReferencias::setRef4(unsigned int ref){
    this->refs[3] = ref;
}

void FechaReferencias::setRef5(unsigned int ref){
    this->refs[4]= ref;
}

void FechaReferencias::setRefLista(unsigned int ref){
    this->refLista = ref;
}

unsigned int* FechaReferencias::getRefs(){
    return this->refs;
}

int FechaReferencias::serializar(SerialBuffer *buffer){
    RegistroGenerico::serializar(buffer);
    if(buffer->pack(&cant,sizeof(cant)))
		return 0;
    if(buffer->pack(refs,sizeof(unsigned int)*5))
		return 0;
    if(buffer->pack(&refLista,sizeof(refLista)))
		return 0;

	return 1;
}

void FechaReferencias::deserializar(SerialBuffer *buffer){
    RegistroGenerico::deserializar(buffer);
    buffer->unpack(&cant);
    buffer->unpack(&refs);
    buffer->unpack(&refLista);
}

// Devuelve el tamanio en bytes que ocuparia persistir la clase.
size_t FechaReferencias::getTamanioEnBytes()
{
    size_t bytes = 0;

    // Contamos el tamanio de la clase padre
    bytes += RegistroGenerico::getTamanioEnBytes();

    // Agregamos el tamanio de los atributos de esta clase
    bytes += sizeof(unsigned int)*7 + sizeof(unsigned short int)*3;

    return bytes;
}
