#ifndef TP_BUFFER_H
#define TP_BUFFER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>


class Buffer
{
private:
	int tamanioBuffer;

private:
	void liberar();
public:
    Buffer();
	void leer();
	void obtenerBloque();
	void escribir();
};

#endif
