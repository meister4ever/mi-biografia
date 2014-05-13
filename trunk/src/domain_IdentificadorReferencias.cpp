#include "domain_IdentificadorReferencias.h"

IdentificadorReferencias::IdentificadorReferencias(){
}

IdentificadorReferencias::IdentificadorReferencias(unsigned int clave){
    this->setClave(clave);
}

IdentificadorReferencias::~IdentificadorReferencias(){
}

unsigned int IdentificadorReferencias::getCant(){
    return this->cant;
}

unsigned int IdentificadorReferencias::getRef1(){
    return this->refs[0];
}

unsigned int IdentificadorReferencias::getRef2(){
    return this->refs[1];
}

unsigned int IdentificadorReferencias::getRef3(){
    return this->refs[2];
}

unsigned int IdentificadorReferencias::getRef4(){
    return this->refs[3];
}

unsigned int IdentificadorReferencias::getRef5(){
    return this->refs[4];
}

unsigned int IdentificadorReferencias::getRefLista(){
    return this->refLista;
}

void IdentificadorReferencias::setCant(unsigned int cant){
    this->cant= cant;
}

void IdentificadorReferencias::setRef1(unsigned int ref){
    this->refs[0] = ref;
}

void IdentificadorReferencias::setRef2(unsigned int ref){
    this->refs[1] = ref;
}

void IdentificadorReferencias::setRef3(unsigned int ref){
    this->refs[2] = ref;
}

void IdentificadorReferencias::setRef4(unsigned int ref){
    this->refs[3] = ref;
}

void IdentificadorReferencias::setRef5(unsigned int ref){
    this->refs[4]= ref;
}

void IdentificadorReferencias::setRefLista(unsigned int ref){
    this->refLista = ref;
}

unsigned int* IdentificadorReferencias::getRefs(){
    return this->refs;
}

int IdentificadorReferencias::serializar(SerialBuffer *buffer){
    RegistroGenerico::serializar(buffer);
    if(buffer->pack(&cant,sizeof(cant)))
		return 0;
    if(buffer->pack(refs,sizeof(unsigned int)*5))
		return 0;
    if(buffer->pack(&refLista,sizeof(refLista)))
		return 0;

	return 1;
}

void IdentificadorReferencias::deserializar(SerialBuffer *buffer){
    RegistroGenerico::deserializar(buffer);
    buffer->unpack(&cant);
    buffer->unpack(&refs);
    buffer->unpack(&refLista);
}

// Devuelve el tamanio en bytes que ocuparia persistir la clase.
size_t IdentificadorReferencias::getTamanioEnBytes()
{
    size_t bytes = 0;

    // Contamos el tamanio de la clase padre
    bytes += RegistroGenerico::getTamanioEnBytes();

    // Agregamos el tamanio de los atributos de esta clase
    bytes += sizeof(unsigned int)*7 + sizeof(unsigned short int)*3;

    return bytes;
}
