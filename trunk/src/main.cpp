#include <iostream>
#include "interfaz_Menu.h"
#include "logica_Utils.h"
#include <time.h>

using namespace std;

int main()
{
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    int fecha = aTime->tm_year + 1900; // da anio desde 1900

    Utils::dividirRssFiles(fecha);
    Utils::dividirTwtFiles(fecha);

	Menu *m = new Menu;
	while(m->start());
	delete m;
	return 0;
}
