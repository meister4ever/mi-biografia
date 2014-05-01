#ifndef TP_PARSER_H
#define TP_PARSER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "archivoBloques.h"


class Parser
{
private:
	ArchivoBloques archivoBloques;

public:
	virtual void extraerTitulo()=0;
	virtual void extraerAutor()=0;
	virtual void extraerFecha()=0;
	void leerLinea();
};


#endif
