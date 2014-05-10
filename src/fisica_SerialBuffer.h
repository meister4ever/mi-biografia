//  fisica_SerialBuffer.h


#ifndef fisica_SerialBuffer_h
#define fisica_SerialBuffer_h

#include <iostream>
#include <string.h>
#include "fisica_VarBuffer.h"

class SerialBuffer : public VarBuffer
{
public:
    SerialBuffer(unsigned int maxSize);
    ~SerialBuffer();
    void clear();
    int pack(const void *object, unsigned short int size);
    int unpack(void *objetc);

private:
    unsigned int ultimoLeido;

};

#endif
