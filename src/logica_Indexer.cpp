#include <iostream>
#include <fstream>
#include <sstream>
#include "logica_Indexer.h"
#include "fisica_DirHandler.h"
#include "logica_FileHandler.h"
#include "logica_Validator.h"
#include "logica_Utils.h"

#include "runtimeConfig.h"

Indexer::Indexer(){
    this->fromPath=sourcePath();
    this->dest=destPath();
    masterName = dest+".master";
    autores = new IndiceAutor(dest);
    titulos =  new IndiceTitulo(dest);
    fechas =  new IndiceFecha(dest);
    identificadores =  new IndiceIdentificador(dest);
}

Indexer::~Indexer(){
    delete autores;
    delete titulos;
    delete fechas;
    delete identificadores;
}

int Indexer::eliminarTodo(){
    remove(masterName.c_str());
    autores->eliminarTodo();
    titulos->eliminarTodo();
    fechas->eliminarTodo();
    identificadores->eliminarTodo();
    return 0;
}

int Indexer::indexarFuentesDesde(int mode){
    DirHandler *dirH = new DirHandler(fromPath.c_str());
    FileHandler *fileH = new FileHandler();
    dirH->getFiles(fromPath.c_str());
    std::list<string> *archivos = dirH->getFileList();
    std::list<string>::iterator it;
    for(it = archivos->begin(); it != archivos->end(); it++){ //Recorro todos los archivos
        cout << "Indexando archivo..  " << *it << endl;
        std::string header = fileH->getFirstLine(*it);
        cout << "Validando Header.. " << header << endl;
        int size;
        if(!(size = Validator::validateHeader(header))){  //valido header
            std::cout << "Error en header. Descartado." << std::endl;
        }else{
            std::cout << "Header OK." << std::endl << "Verificando si ya esta indexada..";
            if (this->estaIndexado(header)){ //verifico si ya esta indexada
                std::cout << "Archivo ya indexado. Descartado" << endl;
            }else{
                std::cout << "OK." << std::endl;
                unsigned int textPosition = this->copyToMaster(*it, masterName); //copio al archivo mestro la fuente
                std::cout << textPosition;
                this->indexarAutores(header,textPosition); //agrego ocurrencia de autor
                this->indexarTitulo(header,textPosition);//agrego ocurrencia de titulo
                this->indexarFecha(header,textPosition);//agrego ocurrencia de fecha
                this->indexarIdentificador(header,textPosition);//agrego ocurrencia de identificador
                }
        }
    }
    if(mode){ //verifico si es modo scratch o append
        autores->packAppend();//guardo en arboles y hash
        titulos->packAppend();
        fechas->packAppend();
        identificadores->packAppend();
    }else{
        autores->pack();
        titulos->pack();
        fechas->pack();
        identificadores->pack();
    }


    delete dirH;
    delete fileH;
    return 0;
}


int Indexer::estaIndexado(std::string header){
    std::string s;
    std::string clave;
    s = Utils::getTituloFromHeader(header);
    clave = Utils::getClaveFromHeader(header);
    std::list<unsigned  int> refs;
    titulos->recuperar(s,&refs);
    std::list<unsigned int>::iterator it;
    std::ifstream master;
    std::string header2;
    std::string clave2;
    for(it = refs.begin();it != refs.end();it++){
        master.open(this->masterName.c_str());
        master.seekg(*it);
        unsigned int size;
        master.read((char*) &size,sizeof(unsigned int));
        getline(master,header2);
        clave2 = Utils::getClaveFromHeader(header2);
        master.close();
        if(!clave.compare(clave2)){
            return 1;
        }
    }
    return 0;
}

int Indexer::copyToMaster(std::string from, std::string to){
    std::ifstream source(from.c_str());
    std::ofstream dest(to.c_str(), std::fstream::app);
    unsigned int pos = dest.tellp();
    source.seekg(0,std::ios_base::end);
    unsigned int tam = source.tellg();
    source.seekg(0,std::ios_base::beg);
    dest.write((char*)&tam, sizeof(tam));
    //dest << tam;
    dest << source.rdbuf();
    source.close();
    dest.close();
    return pos;
}

int Indexer::indexarAutores(std::string header, unsigned int textPosition){
    std::list<std::string>* autoresLista = new std::list<std::string>;
    Utils::getAutoresFromHeader(header,autoresLista);
    std::list<std::string>::iterator it;
    for(it = autoresLista->begin(); it != autoresLista->end();it++){
        this->autores->agregar(textPosition,*it);
    }
    delete autoresLista;
    return 0;
}

int Indexer::indexarTitulo(std::string header, unsigned int textPosition){
    std::list<std::string>* titulosLista = new std::list<std::string>;
    Utils::getTitulosFromHeader(header,titulosLista);
    std::list<std::string>::iterator it;
    for(it = titulosLista->begin(); it != titulosLista->end();it++){
        this->titulos->agregar(textPosition,*it);
    }
    delete titulosLista;
    return 0;
}

int Indexer::indexarFecha(std::string header, unsigned int textPosition){
    std::list<std::string>* fechasLista = new std::list<std::string>;
    Utils::getFechasFromHeader(header,fechasLista);
    std::list<std::string>::iterator it;
    for(it = fechasLista->begin(); it != fechasLista->end();it++){
        this->fechas->agregar(textPosition,*it);
    }
    delete fechasLista;
    return 0;
}

int Indexer::indexarIdentificador(std::string header, unsigned int textPosition){
    std::list<std::string>* IdentificadoresLista = new std::list<std::string>;
    Utils::getIdentificadorFromHeader(header,IdentificadoresLista);
    std::list<std::string>::iterator it;
    for(it = IdentificadoresLista->begin(); it != IdentificadoresLista->end();it++){
        this->identificadores->agregar(textPosition,*it);
    }
    delete IdentificadoresLista;
    return 0;
}

