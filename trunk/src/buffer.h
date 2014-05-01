#ifndef TP_BUFFER_H
#define TP_BUFFER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "archivoBloques.h"
#include "archivo.h"


class Buffer
{
private:
	int tamanioBuffer;
	ArchivoBloques archivoBloques;
	Archivo archivo;

private:
	void liberar();
public:
	void leer();
	void obtenerBloque();
	void escribir();
};

#endif
