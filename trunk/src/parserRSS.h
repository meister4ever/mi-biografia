#ifndef TP_PARSER_R_S_S_H
#define TP_PARSER_R_S_S_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "parser.h"


class ParserRSS : public Parser
{
public:
	void extraerTitulo();
	void extraerAutor();
	void extraerFecha();
};


#endif
