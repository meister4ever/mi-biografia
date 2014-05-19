#include "logica_IndiceFecha.h"
#include "logica_SortExterno.h"
#include "domain_Fechaid.h"
#include "domain_FechaReferencias.h"
#include "logica_Utils.h"
#include <string.h>
#include <string>
#include <fstream>
#include <iostream>
#include <climits>

IndiceFecha::IndiceFecha(std::string path){
    this->temporalOcurrencias = path + ".ocurrenciasFecha";
    this->fechas = path + ".fechas";
    this->listaRefs = path + ".fechasRef";
    this->arbolName = path + ".arbolFechas";
    this->arbol = new ArbolBmas<FechaReferencias>();
}

IndiceFecha::~IndiceFecha(){
    delete arbol;
}


int IndiceFecha::agregar(unsigned int textPosition, std::string fecha){
    unsigned int fechaId = this->obtenerId(fecha);
    FechaOcurrencia* ocur = new FechaOcurrencia(fechaId, textPosition);
    this->guardarOcurrencia(ocur);
    delete ocur;
    return 0;
}

unsigned int IndiceFecha::obtenerId(std::string fecha){
    std::ifstream file;
    std::string p;
    int found = 0;
    unsigned int id =0;
    file.open(this->fechas.c_str(), std::fstream::in | std::fstream::out);
    FechaId* aui = new FechaId();
    if(file.good()){
        file >> *aui;
        while(!file.eof() && !found){
            id = aui->getId();
            const char* c=aui->getFecha();
            if(!strcmp(c,fecha.c_str())){
                found=1;
            }
            file >> *aui;
        }
    }
    file.close();
    delete aui;
    if(!found){
        std::ofstream file2(fechas.c_str(), std::fstream::app);
        id = file2.tellp();
        FechaId* aid = new FechaId(fecha.c_str(),id);
        file2 << *aid;
        delete aid;
        file2.close();
    }
    return id;
}

int IndiceFecha::buscarId(std::string fecha){
    std::ifstream file;
    std::string p;
    int found = 0;
    unsigned int id =0;
    file.open(this->fechas.c_str());
    if(!file.good()){
        return -1;
    }
    FechaId* aui = new FechaId();
    if(file.good()){
        file >> *aui;
        while(!file.eof() && !found){
            id = aui->getId();
            const char* c=aui->getFecha();
            if(!strcmp(c,fecha.c_str())){
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

/*unsigned int IndiceFecha::obtenerIdBinary(std::string fecha){
return 0;
}*/

int IndiceFecha::guardarOcurrencia(FechaOcurrencia* ocur){
    std::ofstream file;
    file.open(temporalOcurrencias.c_str(),std::fstream::app);
    file << *ocur;
    file.close();
    return 0;
}

int IndiceFecha::pack(){
    if(Utils::existeArchivo(temporalOcurrencias)){
        std::cout << "Indexando fechas...";
        std::cout.flush();
        if(Utils::existeArchivo(temporalOcurrencias)){
            SortExterno<FechaOcurrencia>* sort = new SortExterno<FechaOcurrencia>(this->temporalOcurrencias,4096);
            SortExterno<FechaId>* sort2 = new SortExterno<FechaId>(this->fechas,4096);
            sort->ordenar();
            sort2->ordenar();
            delete sort;
            delete sort2;
            std::ifstream file;
            file.open(this->temporalOcurrencias.c_str());
            FechaOcurrencia aid;
            unsigned int fecha = 0;
            unsigned int cant = 0;
            unsigned int refLista = 0;
            std::list<unsigned int>* lista;
            arbol->abrir(this->arbolName.c_str());
            file >> aid;
            while(!file.eof()){
                fecha = aid.getFechaId();
                cant = 0;
                FechaReferencias* ar = new FechaReferencias(fecha);
                refLista = this->getRefLista();
                lista = new std::list<unsigned int>();
                while((aid.getFechaId() == fecha) && !file.eof()){
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

int IndiceFecha::packAppend(){
    if(Utils::existeArchivo(temporalOcurrencias)){
        std::cout << "Indexando fechas...";
        std::cout.flush();
        SortExterno<FechaOcurrencia>* sort = new SortExterno<FechaOcurrencia>(this->temporalOcurrencias,4096);
        SortExterno<FechaId>* sort2 = new SortExterno<FechaId>(this->fechas,4096);
        sort->ordenar();
        sort2->ordenar();
        delete sort;
        delete sort2;
        std::ifstream file;
        file.open(this->temporalOcurrencias.c_str());
        FechaOcurrencia aid;
        unsigned int fecha=0;
        unsigned int cant = 0;
        unsigned int refLista=0;
        std::list<unsigned int>* lista;
        arbol->abrir(this->arbolName.c_str());
        file >> aid;
        while(!file.eof()){
            fecha = aid.getFechaId();
            cant = 0;
            FechaReferencias* ar = new FechaReferencias(fecha);
            refLista = this->getRefLista();
            lista = new std::list<unsigned int>();
            bool b =arbol->buscar(fecha,*ar);
            if(b){
                cant = ar->getCant();
                if(cant > 5){
                    copylist(ar->getRefLista(),lista);
                }
            }
            while((aid.getFechaId() == fecha) && !file.eof()){
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

int IndiceFecha::copylist(unsigned int reflista,std::list<unsigned int>*lista){
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

unsigned int IndiceFecha::getRefLista(){
    std::ofstream file;
    file.open(this->listaRefs.c_str(),std::fstream::app);
    unsigned int pos = file.tellp();
    file.close();
    return pos;
}

int IndiceFecha::guardarRefLista(std::list<unsigned int>* lista){
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

int IndiceFecha::printOcurrencias(){
    std::ifstream file;
    file.open(temporalOcurrencias.c_str(), std::fstream::binary);
    FechaOcurrencia* o = new FechaOcurrencia();
    file >> *o;
    while(!file.eof()){
        std::cout << "(" << o->getFechaId() << "," << o->getDocumentoId() << ")";
        file >> *o;
    }
    delete o;
    file.close();
    return 0;
}


int IndiceFecha::recuperar(std::string fecha, std::list<unsigned int> *lista){
    int clave2 = this->buscarId(fecha);
    if(clave2 == -1){
        return 0;
    }
    unsigned int clave = (unsigned int) clave2;
    arbol->abrir(this->arbolName.c_str());
    FechaReferencias* ar = new FechaReferencias();
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

int IndiceFecha::eliminarTodo(){
    arbol->abrir(arbolName.c_str());
    arbol->eliminar();
    remove(fechas.c_str());
    remove(listaRefs.c_str());
    return 0;
}
