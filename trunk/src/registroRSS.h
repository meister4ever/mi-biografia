#ifndef TP_REGISTRO_R_S_S_H
#define TP_REGISTRO_R_S_S_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "registroVar.h"


class RegistroRSS : public RegistroVar
{
private:
	int autor;
	int titulo;
	int fecha;
	int contenido;
};


#endif
