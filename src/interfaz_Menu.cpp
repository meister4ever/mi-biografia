#include <iostream>
#include "interfaz_Menu.h"
#include "logica_Validator.h"
#include "logica_Indexer.h"
#include "logica_Buscador.h"
#include "logica_Utils.h"
#include "runtimeConfig.h"


using namespace std;

Menu::Menu(){ }

Menu::~Menu(){ }


int Menu::start(){
    string op;
    this->imprimir();
    cin >> op;
    int r = 0;
    int opcion = 0;
    if ((opcion = Validator::validateOpcion(op))){
        r = this->ingresarOpcion(opcion);
    }else{
        cout << "Opcion Invalida" << endl;
        return 1;
    }
    return r;
}


int Menu::imprimir()
{
    cout << "Almacenamiento y busqueda sobre fuentes RSS y Twitter" << endl << endl;
    cout << "Ingrese una opcion" << endl;
    cout << "1. Indexar fuentes " << endl;
    //cout << "2. Indexar fuentes  append" << endl;
    cout << "2. Buscar fuentes por autor" << endl;
    cout << "3. Buscar fuentes por titulo" << endl;
    //cout << "5. Buscar fuentes por frase" << endl;
    cout << "4. Listar todos las fuentes indexadas" << endl;

    cout << "5. Salir" << endl<<endl;
    return 0;
}

/*Obtener nuevos Twits
Obtener nuevos RSSs
Buscar por Autor
Buscar por Título
Buscar por Fecha
Buscar por Identificador
Eliminar todo lo contenido
Eliminar documento por Identificador
Eliminar documento por Fecha
Eliminar documento por Menor a Fecha
Eliminar documento por Mayor a Fecha
Ver Estructura*/


int Menu::ingresarOpcion(int opcion){
    string text;
    Indexer *in;
    Buscador *busc;
    switch(opcion){
        case 5:
            return 0;
        case 1:
            in = new Indexer;
            cout << "Indexando fuentes" << endl;
            cout << "Eliminando cualquier registro de fuentes previo" << endl;
            in->eliminarTodo();
            in->indexarFuentesDesde(0);
            std::cout << std::endl;
            delete in;
            break;
        /*case 2:
            in = new Indexer;
            cout << "Indexando fuentes  append" << endl;
            in->indexarFuentesDesde(1);
            std::cout << std::endl;
            delete in;
            break;*/
        case 2:
            busc = new Buscador();
            std::cout << "Ingrese el autor a buscar" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, text);


            text = Utils::uniformizarString(text);
            std::cout << std::endl;
            while (text.compare("0")){
                busc->buscarPorAutor(text);
                std::cout << std::endl;
                std::cout << "Ingrese el autor a buscar / Ingrese '0' para volver al menú principal" << std::endl;
                std::getline(std::cin, text);
                text = Utils::uniformizarString(text);
                std::cout << std::endl;
            }
            delete busc;
            break;
        case 3:
            busc = new Buscador();
            cout << "Ingrese el titulo a buscar" << endl;
            std::cin.ignore();
            std::getline(std::cin, text);


            text = Utils::uniformizarString(text);
            std::cout << std::endl;
            while (text.compare("0")){
                busc->buscarPorTitulo(text);
                std::cout << std::endl;
                std::cout << "Ingrese el titulo a buscar / Ingrese '0' para volver al menú principal" << std::endl;
                std::getline(std::cin, text);
                text = Utils::uniformizarString(text);
                std::cout << std::endl;
            }
            delete busc;
            std::cout << std::endl;
            break;
        /*case 5:
            busc = new Buscador();
            cout << "Ingrese la frase a buscar" << endl;
            std::cin.ignore();
            std::getline(std::cin, text);


            std::cout << std::endl;
            while (text.compare("0")){
                busc->buscarPorFrase(text);
                std::cout << std::endl;
                std::cout << "Ingrese la frase a buscar / Ingrese '0' para volver al menú principal" << std::endl;
                std::getline(std::cin, text);
                std::cout << std::endl;
            }
            delete busc;
            std::cout << std::endl;
            break;*/
        case 4:
            busc = new Buscador();
            busc->listarTodo();
            delete busc;
            break;


    }
    return 1;
}

