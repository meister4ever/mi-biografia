#ifndef TP_PARSER_T_W_T_H
#define TP_PARSER_T_W_T_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "parser.h"


class ParserTWT : public Parser
{
public:
	void extraerTitulo();
	void extraerAutor();
	void extraerFecha();
};


#endif
