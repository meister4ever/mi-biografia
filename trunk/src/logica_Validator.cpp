#include "logica_Validator.h"
#include <iostream>
#include <sstream>
#include "logica_Utils.h"


int Validator::validateOpcion(std::string op){
    std::stringstream s(op);
    int i;
    if ( (s >> i).fail() || (i<0 || i>15)){
        return 0;
    }else{
        return i;
    }

}

int Validator::validateHeader(std::string header){
    std::list<std::string> *lista = new std::list<std::string>;
    Utils::splitString(header,"╗",lista);
    lista->pop_back();
    int size = lista->size();
    if( size != 4){
        delete lista;
        return 0;
    }
    std::list<std::string>::iterator it;
    for(it = lista->begin(); it != lista->end(); it++){
        std::cout << *it << ' ';
    }
    delete lista;
    return size;
}
