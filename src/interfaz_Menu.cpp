#include <iostream>
#include "interfaz_Menu.h"
#include "logica_Validator.h"
#include "logica_Indexer.h"
#include "logica_Buscador.h"
#include "logica_Utils.h"
#include "runtimeConfig.h"
#include "logica_Descargador.h"
#include "lz77.h"
#include "lz78.h"
#include <ctime>

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
    cout << "2. Buscar fuentes por autor" << endl;
    cout << "3. Buscar fuentes por titulo" << endl;
    cout << "4. Buscar fuentes por fecha" << endl;
    cout << "5. Buscar fuentes por identificador" << endl;
    cout << "6. Buscar fuentes por frase" << endl;
    cout << "7. Descargar fuente Rss" << endl;
    cout << "8. Descargar fuente Twt" << endl;
    cout << "9. Borrar Autor" << endl;
    cout << "10. Borrar Fecha" << endl;
    cout << "11. Borrar Identificador" << endl;
    cout << "12. Borrar Titulo" << endl;
    cout << "13. Listar todos las fuentes indexadas" << endl;
    cout << "14. Ver Estructura" <<endl;
    cout << "15. Estadistica de compresiones" <<endl;
    cout << "16. Salir" << endl<<endl;
    return 0;
}

int Menu::ingresarOpcion(int opcion){
    string text;
    Indexer *in;
    Buscador *busc;
    switch(opcion){
        case 16:
            return 0;
        case 1:
            in = new Indexer;
            cout << "Indexando fuentes" << endl;
            cout << "Eliminando cualquier registro de fuentes previo" << endl;
            in->eliminarTodo();
            Utils::dividirTwtFiles(Utils::getFecha());
            Utils::dividirRssFiles(Utils::getFecha());
            in->indexarFuentesDesde(0);
            std::cout << std::endl;
            delete in;
            break;

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
            cout << "Ingrese el titulo a buscar" << std::endl;
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
        case 4:
            busc = new Buscador();
            cout << "Ingrese el fecha a buscar" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, text);


            text = Utils::uniformizarString(text);
            std::cout << std::endl;
            while (text.compare("0")){
                busc->buscarPorFecha(text);
                std::cout << std::endl;
                std::cout << "Ingrese la fecha a buscar / Ingrese '0' para volver al menú principal" << std::endl;
                std::getline(std::cin, text);
                text = Utils::uniformizarString(text);
                std::cout << std::endl;
            }
            delete busc;
            std::cout << std::endl;
            break;

        case 5:
            busc = new Buscador();
            cout << "Ingrese el identificador a buscar" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, text);


            text = Utils::uniformizarString(text);
            std::cout << std::endl;
            while (text.compare("0")){
                busc->buscarPorIdentificador(text);
                std::cout << std::endl;
                std::cout << "Ingrese el identificador a buscar / Ingrese '0' para volver al menú principal" << std::endl;
                std::getline(std::cin, text);
                text = Utils::uniformizarString(text);
                std::cout << std::endl;
            }
            delete busc;
            std::cout << std::endl;
            break;


        case 6:
            busc = new Buscador();
            cout << "Ingrese la frase a buscar" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, text);

            text = Utils::uniformizarString(text);
            std::cout << std::endl;
            while (text.compare("0")){
                busc->buscarPorFrase(text);
                std::cout << std::endl;
                std::cout << "Ingrese el la frase a buscar / Ingrese '0' para volver al menú principal" << std::endl;
                std::getline(std::cin, text);
                text = Utils::uniformizarString(text);
                std::cout << std::endl;
            }
            delete busc;
            std::cout << std::endl;
            break;

        case 7:
            Descargador::menuRss();
            break;

        case 8:
            std::cout << "Descargando Tweets"<<std::endl;
            Descargador::descargarTwt();
            break;

        case 9:
            busc = new Buscador();
            std::cout << "Ingrese el autor a borrar" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, text);


            text = Utils::uniformizarString(text);
            std::cout << std::endl;
            while (text.compare("0")){
                busc->borrarPorAutor(text);
                std::cout << std::endl;
                std::cout << "Ingrese el autor a borrar / Ingrese '0' para volver al menú principal" << std::endl;
                std::getline(std::cin, text);
                text = Utils::uniformizarString(text);
                std::cout << std::endl;
            }
            delete busc;
            break;

        case 10:
            busc = new Buscador();
            std::cout << "Ingrese la fecha a borrar" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, text);


            text = Utils::uniformizarString(text);
            std::cout << std::endl;
            while (text.compare("0")){
                busc->borrarPorAutor(text);
                std::cout << std::endl;
                std::cout << "Ingrese la fecha a borrar / Ingrese '0' para volver al menú principal" << std::endl;
                std::getline(std::cin, text);
                text = Utils::uniformizarString(text);
                std::cout << std::endl;
            }
            delete busc;
            break;

        case 11:
            busc = new Buscador();
            std::cout << "Ingrese el identificador a borrar" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, text);


            text = Utils::uniformizarString(text);
            std::cout << std::endl;
            while (text.compare("0")){
                busc->borrarPorIdentificador(text);
                std::cout << std::endl;
                std::cout << "Ingrese el identificador a borrar / Ingrese '0' para volver al menú principal" << std::endl;
                std::getline(std::cin, text);
                text = Utils::uniformizarString(text);
                std::cout << std::endl;
            }
            delete busc;
            break;

        case 12:
            busc = new Buscador();
            std::cout << "Ingrese el titulo a borrar" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, text);


            text = Utils::uniformizarString(text);
            std::cout << std::endl;
            while (text.compare("0")){
                busc->borrarPorTitulo(text);
                std::cout << std::endl;
                std::cout << "Ingrese el titulo a borrar / Ingrese '0' para volver al menú principal" << std::endl;
                std::getline(std::cin, text);
                text = Utils::uniformizarString(text);
                std::cout << std::endl;
            }
            delete busc;
            break;

            case 13:
            busc = new Buscador();
            busc->listarTodo();
            delete busc;
            break;

            case 14:
            {
            string destino = destPath()+"Estructura.txt";
            std::remove(destino.c_str());
            ofstream entrada;

            entrada.open(destino.c_str(), ios_base::app);
            entrada << "Arbol B+ Títulos"<< std::endl;
            entrada.close();
            std::cout << "Se guardó en Estructura.txt (../destino) Arbol B+ Titulos"<< std::endl;
            Utils::imprimir(".arboltitulos");

            entrada.open(destino.c_str(), ios_base::app);
            entrada << "Arbol B+ Autores"<< std::endl;
            entrada.close();
            std::cout << "Se guardó en Estructura.txt (../destino) Arbol B+ Autores"<< std::endl;
            Utils::imprimir(".arbolautores");

            entrada.open(destino.c_str(), ios_base::app);
            entrada << "Arbol B+ Fechas"<< std::endl;
            entrada.close();

            std::cout << "Se guardó en Estructura.txt (../destino) Arbol B+ Fechas"<< std::endl;
            Utils::imprimir(".arbolfechas");
            }
            break;

            case 15:
            {
            string sFileOutLz77;
            string sFileOutLz78;
            string sFileIn;
            sFileIn = destPath()+"Estructura.txt";
            lz77 tmp;
            lz78 tmp2;
            if (sFileOutLz77 == "") sFileOutLz77 = sFileIn + ".lz77";
            if (sFileOutLz78 == "") sFileOutLz78 = sFileIn + ".lz78";

            std::clock_t    start;
            start = std::clock();
            tmp.compress(sFileIn,sFileOutLz77);
            std::cout << "El lz77 tardo en comprimir: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

            tmp2.readFile(sFileIn);

            std::clock_t    start2;
            start2 = std::clock();
            tmp2.compress(sFileOutLz78);
            std::cout << "El lz78 tardo en comprimir: " << (std::clock() - start2) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;


            std::cout << "Se comprimio el archivo Estructura.txt en lz77 y lz78 (../destino)"<< std::endl;



            ifstream archivo( sFileIn.c_str(), ios::binary | ios::ate);
            ifstream comprimidolz77( sFileOutLz77.c_str(), ios::binary | ios::ate);
            ifstream comprimidolz78( sFileOutLz78.c_str(), ios::binary | ios::ate);

            int tamanioarchivo = archivo.tellg();
            int tamaniocomprimidolz77 = comprimidolz77.tellg();
            int tamaniocomprimidolz78 = comprimidolz78.tellg();
            cout << "El archivo ocupa " << tamanioarchivo << "bytes" << std::endl;
            cout << "El archivo comprimido por lz77 ocupa " << tamaniocomprimidolz77 << "bytes" << std::endl;
            cout << "El archivo comprimido por lz78 ocupa " << tamaniocomprimidolz78 << "bytes" << std::endl;
            cout << "El porcentaje que ocupa el archivo final comprimido por lz77 respecto del archivo inicial es: " << tamaniocomprimidolz77 *100 / tamanioarchivo << "%" << std::endl;
            cout << "El porcentaje que ocupa el archivo final comprimido por lz78 respecto del archivo inicial es: " << tamaniocomprimidolz78 *100 / tamanioarchivo << "%" << std::endl;
            }
            break;
    }
    return 1;
}

