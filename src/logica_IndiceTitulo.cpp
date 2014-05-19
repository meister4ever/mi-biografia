#include "logica_IndiceTitulo.h"
#include "logica_SortExterno.h"
#include "domain_TituloId.h"
#include "domain_TituloReferencias.h"
#include "logica_Utils.h"
#include <string.h>
#include <string>
#include <fstream>
#include <iostream>
#include <climits>

IndiceTitulo::IndiceTitulo(std::string path){
    this->temporalOcurrencias = path + ".ocurrenciasTitulo";
    this->titulos = path + ".titulos";
    this->listaRefs = path + ".titulosRef";
    this->arbolName = path + ".arboltitulos";
    this->arbol = new ArbolBmas<TituloReferencias>();

}

IndiceTitulo::~IndiceTitulo(){
    delete arbol;
}


int IndiceTitulo::agregar(unsigned int textPosition, std::string titulo){
    unsigned int tituloId = this->obtenerId(titulo);
    TituloOcurrencia* ocur = new TituloOcurrencia(tituloId, textPosition);
    this->guardarOcurrencia(ocur);
    delete ocur;
    return 0;
}

unsigned int IndiceTitulo::obtenerId(std::string titulo){
    std::ifstream file;
    std::string p;
    int found = 0;
    unsigned int id =0;
    file.open(this->titulos.c_str(), std::fstream::in | std::fstream::out);
    TituloId* aui = new TituloId();
    if(file.good()){
        file >> *aui;
        while(!file.eof() && !found){
            id = aui->getId();
            const char* c=aui->getTitulo();
            if(!strcmp(c,titulo.c_str())){
                found=1;
            }
            file >> *aui;
        }
    }
    file.close();
    delete aui;
    if(!found){
        std::ofstream file2(titulos.c_str(), std::fstream::app);
        id = file2.tellp();
        TituloId* aid = new TituloId(titulo.c_str(),id);
        file2 << *aid;
        delete aid;
        file2.close();
    }
    return id;
}

int IndiceTitulo::buscarId(std::string titulo){
    std::ifstream file;
    std::string p;
    int found = 0;
    unsigned int id =0;
    file.open(this->titulos.c_str());
    if(!file.good()){
        return -1;
    }
    TituloId* aui = new TituloId();
    if(file.good()){
        file >> *aui;
        while(!file.eof() && !found){
            id = aui->getId();
            const char* c=aui->getTitulo();
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

int IndiceTitulo::borrar(std::string titulo){
    std::ifstream file;
    std::ofstream file2;
    std::string p;
    int found = 0;
    unsigned int id =0;
    file.open(this->titulos.c_str());
    if(!file.good()){
        return -1;
    }
    TituloId* aui = new TituloId();
    if(file.good()){
        file >> *aui;
        while(!file.eof() && !found){
            id = aui->getId();
            const char* c=aui->getTitulo();
            if(!strcmp(c,titulo.c_str())){
                found=1;
                aui->setId(-1);
                int largo = sizeof(*aui);
                int posicion = file.tellg();
                file2.open(this->titulos.c_str());
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

/*unsigned int IndiceTitulo::obtenerIdBinary(std::string titulo){
return 0;
}*/

int IndiceTitulo::guardarOcurrencia(TituloOcurrencia* ocur){
    std::ofstream file;
    file.open(temporalOcurrencias.c_str(),std::fstream::app);
    file << *ocur;
    file.close();
    return 0;
}

int IndiceTitulo::pack(){
    if(Utils::existeArchivo(temporalOcurrencias)){
        std::cout << "Indexando titulos...";
        std::cout.flush();
        if(Utils::existeArchivo(temporalOcurrencias)){
            SortExterno<TituloOcurrencia>* sort = new SortExterno<TituloOcurrencia>(this->temporalOcurrencias,4096);
            SortExterno<TituloId>* sort2 = new SortExterno<TituloId>(this->titulos,4096);
            sort->ordenar();
            sort2->ordenar();
            delete sort;
            delete sort2;
            std::ifstream file;
            file.open(this->temporalOcurrencias.c_str());
            TituloOcurrencia aid;
            unsigned int titulo = 0;
            unsigned int cant = 0;
            unsigned int refLista = 0;
            std::list<unsigned int>* lista;
            arbol->abrir(this->arbolName.c_str());
            file >> aid;
            while(!file.eof()){
                titulo = aid.getTituloId();
                cant = 0;
                TituloReferencias* ar = new TituloReferencias(titulo);
                refLista = this->getRefLista();
                lista = new std::list<unsigned int>();
                while((aid.getTituloId() == titulo) && !file.eof()){
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

int IndiceTitulo::packAppend(){
    if(Utils::existeArchivo(temporalOcurrencias)){
        std::cout << "Indexando titulos...";
        std::cout.flush();
        SortExterno<TituloOcurrencia>* sort = new SortExterno<TituloOcurrencia>(this->temporalOcurrencias,4096);
        SortExterno<TituloId>* sort2 = new SortExterno<TituloId>(this->titulos,4096);
        sort->ordenar();
        sort2->ordenar();
        delete sort;
        delete sort2;
        std::ifstream file;
        file.open(this->temporalOcurrencias.c_str());
        TituloOcurrencia aid;
        unsigned int titulo=0;
        unsigned int cant = 0;
        unsigned int refLista=0;
        std::list<unsigned int>* lista;
        arbol->abrir(this->arbolName.c_str());
        file >> aid;
        while(!file.eof()){
            titulo = aid.getTituloId();
            cant = 0;
            TituloReferencias* ar = new TituloReferencias(titulo);
            refLista = this->getRefLista();
            lista = new std::list<unsigned int>();
            bool b =arbol->buscar(titulo,*ar);
            if(b){
                cant = ar->getCant();
                if(cant > 5){
                    copylist(ar->getRefLista(),lista);
                }
            }
            while((aid.getTituloId() == titulo) && !file.eof()){
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

int IndiceTitulo::copylist(unsigned int reflista,std::list<unsigned int>*lista){
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

unsigned int IndiceTitulo::getRefLista(){
    std::ofstream file;
    file.open(this->listaRefs.c_str(),std::fstream::app);
    unsigned int pos = file.tellp();
    file.close();
    return pos;
}

int IndiceTitulo::guardarRefLista(std::list<unsigned int>* lista){
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

int IndiceTitulo::printOcurrencias(){
    std::ifstream file;
    file.open(temporalOcurrencias.c_str(), std::fstream::binary);
    TituloOcurrencia* o = new TituloOcurrencia();
    file >> *o;
    while(!file.eof()){
        std::cout << "(" << o->getTituloId() << "," << o->getDocumentoId() << ")";
        file >> *o;
    }
    delete o;
    file.close();
    return 0;
}


int IndiceTitulo::recuperar(std::string titulo, std::list<unsigned int> *lista){
    int clave2 = this->buscarId(titulo);
    if(clave2 == -1){
        return 0;
    }
    unsigned int clave = (unsigned int) clave2;
    arbol->abrir(this->arbolName.c_str());
    TituloReferencias* ar = new TituloReferencias();
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

int IndiceTitulo::eliminarTodo(){
    arbol->abrir(arbolName.c_str());
    arbol->eliminar();
    remove(titulos.c_str());
    remove(listaRefs.c_str());
    return 0;
}
