#include "domain_TituloOcurrencia.h"
#include <iostream>

// contiene el par (TituloId, DocumentoId)
TituloOcurrencia::TituloOcurrencia(unsigned int tituloId, unsigned int documentoId){
    this->tituloId = tituloId;
    this->documentoId=documentoId;
}

TituloOcurrencia::TituloOcurrencia(){
}

TituloOcurrencia::~TituloOcurrencia(){
}

int TituloOcurrencia::comparar(Comparacion *c) const{
    TituloOcurrencia *ocur = (TituloOcurrencia*) c;
    if(this->tituloId > ocur->tituloId) return 1;
    if(this->tituloId < ocur->tituloId) return -1;
    if(this->documentoId > ocur->documentoId) return 1;
    if(this->documentoId < ocur->documentoId) return -1;
    return 0;
}

unsigned int TituloOcurrencia::getDocumentoId() const{
    return documentoId;
}

unsigned int TituloOcurrencia::getTituloId() const{
    return tituloId;
}


std::ostream& operator << (std::ostream &out, TituloOcurrencia &ocur){
    unsigned int p = ocur.getTituloId();
    out.write((char*) &p,sizeof(unsigned int));
    p = ocur.getDocumentoId();
    out.write((char*) &p,sizeof(unsigned int));
    return out;
}

std::istream& operator >> (std::istream &out, TituloOcurrencia &ocur){
    unsigned int p=0;
    out.read((char*) &p,sizeof(unsigned int));
    ocur.tituloId = p;
    out.read((char*) &p,sizeof(unsigned int));
    ocur.documentoId = p;
    return out;
}
