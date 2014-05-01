#ifndef TP_SERIALIZABLE_H
#define TP_SERIALIZABLE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "buffer.h"


class Serializable
{
private:
	Buffer buffer;

public:
	virtual void leerObjeto()=0;
	virtual void escribirObjeto()=0;
};


#endif
