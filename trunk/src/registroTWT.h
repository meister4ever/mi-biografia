#ifndef TP_REGISTRO_T_W_T_H
#define TP_REGISTRO_T_W_T_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "registroFijo.h"


class RegistroTWT : public RegistroFijo
{
private:
	int autor;
	int hashtag;
	int fecha;
	int contenido;
};


#endif
