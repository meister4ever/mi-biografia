#include <iostream>
#include "interfaz_Menu.h"
#include "logica_Utils.h"


using namespace std;

int main()
{
	Menu *m = new Menu;
	while(m->start());
	delete m;
	return 0;
}
