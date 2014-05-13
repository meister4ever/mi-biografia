#include <iostream>
#include <list>
#include "logica_Buscador.h"
#include "logica_Utils.h"
#include "runtimeConfig.h"


Buscador::Buscador() {
    this->dest = destPath();
    this->outName=dest+"salida.out";
    autores = new IndiceAutor(dest);
    titulos =  new IndiceTitulo(dest);
    fechas =  new IndiceFecha(dest);
    identificadores = new IndiceIdentificadores(dest);
}

Buscador::~Buscador(){
    delete autores;
    delete titulos;
    delete identificadores;
}

int Buscador::buscarPorAutor(std::string autor){
    std::list<unsigned int> *listilla;
    listilla = new std::list<unsigned int>;
    autores->recuperar(autor,listilla);
    remove(outName.c_str());
    if(listilla->size() == 0){
        cout << "No se encontraron fuentes" << std::endl;
        delete listilla;
        return 0;
    }
    cout << "Se encontraron los siguientes fuentes" << std::endl;
    std::ifstream file;
    std::string fileName = dest + ".master";
    file.open(fileName.c_str());
    std::string header;
    unsigned int largo;
    for (std::list<unsigned int>::iterator it = listilla->begin();it != listilla->end();it++){
        file.seekg(*it);
        file.read((char*)&largo,sizeof(largo));
        getline(file,header);


        cout << header << std::endl;
        imprimirFuente(*it);
    }
    cout << "Los autores fueron impresos en el archivo salida.out de su carpeta de destino" << std::endl;
    file.close();
    delete listilla;
    return 0;
}

int Buscador::buscarPorTitulo(std::string titulo){
    std::list<unsigned int> *listilla;
    listilla = new std::list<unsigned int>;
    titulos->recuperar(titulo,listilla);
    remove(outName.c_str());
    if(listilla->size() == 0){
        cout << "No se encontraron fuentes" << std::endl;
        delete listilla;
        return 0;
    }
    cout << "Se encontraron los siguientes fuentes" << std::endl;
    std::ifstream file;
    std::string fileName = dest + ".master";
    file.open(fileName.c_str());
    std::string header;
    unsigned int largo;
    for (std::list<unsigned int>::iterator it = listilla->begin();it != listilla->end();it++){
        file.seekg(*it);
        file.read((char*)&largo,sizeof(largo));
        getline(file,header);


        cout << header << std::endl;
        imprimirFuente(*it);
    }
    cout << "Los titulos fueron impresos en el archivo salida.out de su carpeta de destino" << std::endl;
    file.close();
    delete listilla;
    return 0;
}

int Buscador::buscarPorFecha(std::string fecha){
    std::list<unsigned int> *listilla;
    listilla = new std::list<unsigned int>;
    fechas->recuperar(fecha,listilla);
    remove(outName.c_str());
    if(listilla->size() == 0){
        cout << "No se encontraron fuentes" << std::endl;
        delete listilla;
        return 0;
    }
    cout << "Se encontraron los siguientes fuentes" << std::endl;
    std::ifstream file;
    std::string fileName = dest + ".master";
    file.open(fileName.c_str());
    std::string header;
    unsigned int largo;
    for (std::list<unsigned int>::iterator it = listilla->begin();it != listilla->end();it++){
        file.seekg(*it);
        file.read((char*)&largo,sizeof(largo));
        getline(file,header);


        cout << header << std::endl;
        imprimirFuente(*it);
    }
    cout << "Las fechas fueron impresas en el archivo salida.out de su carpeta de destino" << std::endl;
    file.close();
    delete listilla;
    return 0;
}

int Buscador::buscarPorIdentificador(std::string identificador){
    std::list<unsigned int> *listilla;
    listilla = new std::list<unsigned int>;
    identificadores->recuperar(identificador,listilla);
    remove(outName.c_str());
    if(listilla->size() == 0){
        cout << "No se encontraron fuentes" << std::endl;
        delete listilla;
        return 0;
    }
    cout << "Se encontraron las siguientes fuentes" << std::endl;
    std::ifstream file;
    std::string fileName = dest + ".master";
    file.open(fileName.c_str());
    std::string header;
    unsigned int largo;
    for (std::list<unsigned int>::iterator it = listilla->begin();it != listilla->end();it++){
        file.seekg(*it);
        file.read((char*)&largo,sizeof(largo));
        getline(file,header);

        cout << header << std::endl;
        imprimirFuente(*it);
    }
    cout << "Las fuentes fueron impresas en el archivo salida.out de su carpeta de destino" << std::endl;
    file.close();
    delete listilla;
    return 0;
}



int Buscador::imprimirFuente(unsigned int ref){
    std::ifstream file;
    std::ofstream out;
    std::string fileName = dest+ ".master";
    file.open(fileName.c_str());
    out.open(outName.c_str(),std::fstream::app);
    unsigned int largo;
    file.seekg(ref);
    file.read((char*)&largo,sizeof(largo));
    for(unsigned int i=0;i<largo;i++){
        char c;
        file.read(&c,sizeof(char));
        out.write(&c,sizeof(char));
    }
    out << std::endl;
    file.close();
    out.close();
    return 0;
}


int Buscador::listarTodo(){
    std::ifstream file;
    std::string fileName = dest + ".master";
    file.open(fileName.c_str());
    if(!file.good()){
         cout << "No hay fuentes indexados." << std::endl;
         return 0;
    }
    std::string header;
    unsigned int largo =0;
    unsigned int pos=0;
    int flag = 0;
    cout << "Se encuentran indexados los siguientes fuentes:" << std::endl;
    file.read((char*)&largo,sizeof(largo));
    while(!file.eof()){
        flag = 1;
        pos = file.tellg();
        pos = pos + largo;
        getline(file,header);
        cout << header << std::endl;
        file.seekg(pos);
        file.read((char*)&largo,sizeof(largo));
    }
    if(!flag){
        cout << "No hay fuentes indexados." << std::endl;
    }
    cout  << std::endl;
    return 0;
}
