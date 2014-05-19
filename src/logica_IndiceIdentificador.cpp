#include "logica_IndiceIdentificador.h"
#include "logica_SortExterno.h"
#include "domain_IdentificadorId.h"
#include "domain_IdentificadorReferencias.h"
#include "logica_Utils.h"
#include <string.h>
#include <string>
#include <fstream>
#include <iostream>
#include <climits>

IndiceIdentificador::IndiceIdentificador(std::string path){
    this->temporalOcurrencias = path + ".ocurrenciasIdentificador";
    this->identificadores = path + ".identificadores";
    this->listaRefs = path + ".identificadoresRef";
    this->arbolName = path + ".arbolidentificadores";
    this->arbol = new ArbolBmas<IdentificadorReferencias>();

}

IndiceIdentificador::~IndiceIdentificador(){
    delete arbol;
}


int IndiceIdentificador::agregar(unsigned int textPosition, std::string titulo){
    unsigned int tituloId = this->obtenerId(titulo);
    IdentificadorOcurrencia* ocur = new IdentificadorOcurrencia(tituloId, textPosition);
    this->guardarOcurrencia(ocur);
    delete ocur;
    return 0;
}

unsigned int IndiceIdentificador::obtenerId(std::string titulo){
    std::ifstream file;
    std::string p;
    int found = 0;
    unsigned int id =0;
    file.open(this->identificadores.c_str(), std::fstream::in | std::fstream::out);
    IdentificadorId* aui = new IdentificadorId();
    if(file.good()){
        file >> *aui;
        while(!file.eof() && !found){
            id = aui->getId();
            const char* c=aui->getIdentificador();
            if(!strcmp(c,titulo.c_str())){
                found=1;
            }
            file >> *aui;
        }
    }
    file.close();
    delete aui;
    if(!found){
        std::ofstream file2(identificadores.c_str(), std::fstream::app);
        id = file2.tellp();
        IdentificadorId* aid = new IdentificadorId(titulo.c_str(),id);
        file2 << *aid;
        delete aid;
        file2.close();
    }
    return id;
}

int IndiceIdentificador::buscarId(std::string titulo){
    std::ifstream file;
    std::string p;
    int found = 0;
    unsigned int id =0;
    file.open(this->identificadores.c_str());
    if(!file.good()){
        return -1;
    }
    IdentificadorId* aui = new IdentificadorId();
    if(file.good()){
        file >> *aui;
        while(!file.eof() && !found){
            id = aui->getId();
            const char* c=aui->getIdentificador();
            if(!strcmp(c,titulo.c_str())){
                found=1;
            }
            file >> *aui;
        }
    }
    file.close();
    delete aui;
    if(!found){
        return -1;
    }
    return id;
}

int IndiceIdentificador::borrar(std::string identificador){
    std::ifstream file;
    std::ofstream file2;
    std::string p;
    int found = 0;
    unsigned int id =0;
    file.open(this->identificadores.c_str());
    if(!file.good()){
        return -1;
    }
    IdentificadorId* aui = new IdentificadorId();
    if(file.good()){
        file >> *aui;
        while(!file.eof() && !found){
            id = aui->getId();
            const char* c=aui->getIdentificador();
            if(!strcmp(c,identificador.c_str())){
                found=1;
                aui->setId(-1);
                int largo = sizeof(*aui);
                int posicion = file.tellg();
                file2.open(this->identificadores.c_str());
                file2.seekp(posicion-largo);
                file2 << *aui;
                file2.close();
            }
            file >> *aui;
        }
    }
    file.close();
    delete aui;
    if(!found){
        return -1;
    }
    return id;
}

/*unsigned int IndiceIdentificador::obtenerIdBinary(std::string titulo){
return 0;
}*/

int IndiceIdentificador::guardarOcurrencia(IdentificadorOcurrencia* ocur){
    std::ofstream file;
    file.open(temporalOcurrencias.c_str(),std::fstream::app);
    file << *ocur;
    file.close();
    return 0;
}

int IndiceIdentificador::pack(){
    if(Utils::existeArchivo(temporalOcurrencias)){
        std::cout << "Indexando identificadores...";
        std::cout.flush();
        if(Utils::existeArchivo(temporalOcurrencias)){
            SortExterno<IdentificadorOcurrencia>* sort = new SortExterno<IdentificadorOcurrencia>(this->temporalOcurrencias,4096);
            SortExterno<IdentificadorId>* sort2 = new SortExterno<IdentificadorId>(this->identificadores,4096);
            sort->ordenar();
            sort2->ordenar();
            delete sort;
            delete sort2;
            std::ifstream file;
            file.open(this->temporalOcurrencias.c_str());
            IdentificadorOcurrencia aid;
            unsigned int titulo = 0;
            unsigned int cant = 0;
            unsigned int refLista = 0;
            std::list<unsigned int>* lista;
            arbol->abrir(this->arbolName.c_str());
            file >> aid;
            while(!file.eof()){
                titulo = aid.getIdentificadorId();
                cant = 0;
                IdentificadorReferencias* ar = new IdentificadorReferencias(titulo);
                refLista = this->getRefLista();
                lista = new std::list<unsigned int>();
                while((aid.getIdentificadorId() == titulo) && !file.eof()){
                    switch(cant){
                        case 0: ar->setRef1(aid.getDocumentoId());
                                break;
                        case 1:
                                ar->setRef2(aid.getDocumentoId());
                                break;
                        case 2:
                                ar->setRef3(aid.getDocumentoId());
                                break;
                        case 3:
                                ar->setRef4(aid.getDocumentoId());
                                break;
                        case 4:
                                ar->setRef5(aid.getDocumentoId());
                                break;
                        case 5: ar->setRefLista(refLista);
                        default: lista->push_back(aid.getDocumentoId());
                    }
                    cant++;
                    file >> aid;
                }
                ar->setCant(cant);
                if(cant > 5){
                    this->guardarRefLista(lista);
                }else{
                    ar->setRefLista(UINT_MAX);
                }
                arbol->insertar(ar->getClave(),*ar);
                delete ar;
                delete lista;
            }
            arbol->cerrar();
            remove(this->temporalOcurrencias.c_str());
            std::cout << "OK"<< std::endl;
        }
    }
    return  0;
}

int IndiceIdentificador::packAppend(){
    if(Utils::existeArchivo(temporalOcurrencias)){
        std::cout << "Indexando identificadores...";
        std::cout.flush();
        SortExterno<IdentificadorOcurrencia>* sort = new SortExterno<IdentificadorOcurrencia>(this->temporalOcurrencias,4096);
        SortExterno<IdentificadorId>* sort2 = new SortExterno<IdentificadorId>(this->identificadores,4096);
        sort->ordenar();
        sort2->ordenar();
        delete sort;
        delete sort2;
        std::ifstream file;
        file.open(this->temporalOcurrencias.c_str());
        IdentificadorOcurrencia aid;
        unsigned int titulo=0;
        unsigned int cant = 0;
        unsigned int refLista=0;
        std::list<unsigned int>* lista;
        arbol->abrir(this->arbolName.c_str());
        file >> aid;
        while(!file.eof()){
            titulo = aid.getIdentificadorId();
            cant = 0;
            IdentificadorReferencias* ar = new IdentificadorReferencias(titulo);
            refLista = this->getRefLista();
            lista = new std::list<unsigned int>();
            bool b =arbol->buscar(titulo,*ar);
            if(b){
                cant = ar->getCant();
                if(cant > 5){
                    copylist(ar->getRefLista(),lista);
                }
            }
            while((aid.getIdentificadorId() == titulo) && !file.eof()){
                switch(cant){
                    case 0: ar->setRef1(aid.getDocumentoId());
                            break;
                    case 1:
                            ar->setRef2(aid.getDocumentoId());
                            break;
                    case 2:
                            ar->setRef3(aid.getDocumentoId());
                            break;
                    case 3:
                            ar->setRef4(aid.getDocumentoId());
                            break;
                    case 4:
                            ar->setRef5(aid.getDocumentoId());
                            break;
                    case 5: ar->setRefLista(refLista);
                    default: lista->push_back(aid.getDocumentoId());
                }
                cant++;
                file >> aid;
            }
            ar->setCant(cant);
            if(cant > 5){
                this->guardarRefLista(lista);
            }else{
                ar->setRefLista(UINT_MAX);
            }
            if(b){
                arbol->actualizar(ar->getClave(),*ar);
            }else{
                arbol->insertar(ar->getClave(),*ar);
            }
            delete ar;
            delete lista;
        }
        arbol->cerrar();
        remove(this->temporalOcurrencias.c_str());
        std::cout << "OK"<< std::endl;
    }
    return  0;
}

int IndiceIdentificador::copylist(unsigned int reflista,std::list<unsigned int>*lista){
    std::ifstream file;
    file.open(this->listaRefs.c_str());
    file.seekg(reflista);
    unsigned int cant;
    file.read((char*)&cant,sizeof(unsigned int));
    for(unsigned int i=0;i<cant;i++){
        unsigned int ref;
        file.read((char*)&ref,sizeof(unsigned int));
        lista->push_back(ref);
    }
    return 0;
}

unsigned int IndiceIdentificador::getRefLista(){
    std::ofstream file;
    file.open(this->listaRefs.c_str(),std::fstream::app);
    unsigned int pos = file.tellp();
    file.close();
    return pos;
}

int IndiceIdentificador::guardarRefLista(std::list<unsigned int>* lista){
    unsigned int cant = lista->size();
    std::ofstream file;
    file.open(this->listaRefs.c_str(),std::fstream::app);
    file.write((char*)&cant,sizeof(cant));
    for(std::list<unsigned int>::iterator it = lista->begin();it != lista->end();it++){
        file.write((char*)&*it,sizeof(unsigned int));
    }
    file.close();
    return 0;
}

int IndiceIdentificador::printOcurrencias(){
    std::ifstream file;
    file.open(temporalOcurrencias.c_str(), std::fstream::binary);
    IdentificadorOcurrencia* o = new IdentificadorOcurrencia();
    file >> *o;
    while(!file.eof()){
        std::cout << "(" << o->getIdentificadorId() << "," << o->getDocumentoId() << ")";
        file >> *o;
    }
    delete o;
    file.close();
    return 0;
}


int IndiceIdentificador::recuperar(std::string titulo, std::list<unsigned int> *lista){
    int clave2 = this->buscarId(titulo);
    if(clave2 == -1){
        return 0;
    }
    unsigned int clave = (unsigned int) clave2;
    arbol->abrir(this->arbolName.c_str());
    IdentificadorReferencias* ar = new IdentificadorReferencias();
    bool b = arbol->buscar(clave, *ar);
    if(b){
        unsigned int* refs = ar->getRefs();
        unsigned int stop = ar->getCant() > 5 ? 5: ar->getCant();
        for(unsigned int i=0;i<stop;i++){
            lista->push_back(refs[i]);
        }
        if(ar->getCant() > 5){
            std::ifstream file;
            file.open(this->listaRefs.c_str());
            file.seekg(ar->getRefLista());
            unsigned int cant;
            file.read((char*)&cant,sizeof(unsigned int));
            for(unsigned int i=0;i < cant;i++){
                unsigned int ref;
                file.read((char*)&ref,sizeof(unsigned int));
                lista->push_back(ref);
            }
            file.close();
        }
    }
    delete ar;
    arbol->cerrar();
    return 0;
}

int IndiceIdentificador::eliminarTodo(){
    arbol->abrir(arbolName.c_str());
    arbol->eliminar();
    remove(identificadores.c_str());
    remove(listaRefs.c_str());
    return 0;
}
