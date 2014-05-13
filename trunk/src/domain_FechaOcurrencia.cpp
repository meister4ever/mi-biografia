#include "domain_FechaOcurrencia.h"
#include <iostream>

// contiene el par (FechaId, DocumentoId)
FechaOcurrencia::FechaOcurrencia(unsigned int fechaId, unsigned int documentoId){
    this->fechaId = fechaId;
    this->documentoId=documentoId;
}

FechaOcurrencia::FechaOcurrencia(){
}

FechaOcurrencia::~FechaOcurrencia(){
}

int FechaOcurrencia::comparar(Comparacion *c) const{
    FechaOcurrencia *ocur = (FechaOcurrencia*) c;
    if(this->fechaId > ocur->fechaId) return 1;
    if(this->fechaId < ocur->fechaId) return -1;
    if(this->documentoId > ocur->documentoId) return 1;
    if(this->documentoId < ocur->documentoId) return -1;
    return 0;
}

unsigned int FechaOcurrencia::getDocumentoId() const{
    return documentoId;
}

unsigned int FechaOcurrencia::getFechaId() const{
    return fechaId;
}


std::ostream& operator << (std::ostream &out, FechaOcurrencia &ocur){
    unsigned int p = ocur.getFechaId();
    out.write((char*) &p,sizeof(unsigned int));
    p = ocur.getDocumentoId();
    out.write((char*) &p,sizeof(unsigned int));
    return out;
}

std::istream& operator >> (std::istream &out, FechaOcurrencia &ocur){
    unsigned int p=0;
    out.read((char*) &p,sizeof(unsigned int));
    ocur.fechaId = p;
    out.read((char*) &p,sizeof(unsigned int));
    ocur.documentoId = p;
    return out;
}
