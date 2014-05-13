#include "domain_IdentificadorOcurrencia.h"
#include <iostream>

// contiene el par (IdentificadorId, DocumentoId)
IdentificadorOcurrencia::IdentificadorOcurrencia(unsigned int tituloId, unsigned int documentoId){
    this->tituloId = tituloId;
    this->documentoId=documentoId;
}

IdentificadorOcurrencia::IdentificadorOcurrencia(){
}

IdentificadorOcurrencia::~IdentificadorOcurrencia(){
}

int IdentificadorOcurrencia::comparar(Comparacion *c) const{
    IdentificadorOcurrencia *ocur = (IdentificadorOcurrencia*) c;
    if(this->tituloId > ocur->tituloId) return 1;
    if(this->tituloId < ocur->tituloId) return -1;
    if(this->documentoId > ocur->documentoId) return 1;
    if(this->documentoId < ocur->documentoId) return -1;
    return 0;
}

unsigned int IdentificadorOcurrencia::getDocumentoId() const{
    return documentoId;
}

unsigned int IdentificadorOcurrencia::getIdentificadorId() const{
    return tituloId;
}


std::ostream& operator << (std::ostream &out, IdentificadorOcurrencia &ocur){
    unsigned int p = ocur.getIdentificadorId();
    out.write((char*) &p,sizeof(unsigned int));
    p = ocur.getDocumentoId();
    out.write((char*) &p,sizeof(unsigned int));
    return out;
}

std::istream& operator >> (std::istream &out, IdentificadorOcurrencia &ocur){
    unsigned int p=0;
    out.read((char*) &p,sizeof(unsigned int));
    ocur.tituloId = p;
    out.read((char*) &p,sizeof(unsigned int));
    ocur.documentoId = p;
    return out;
}
