// VarBuffer.h


#ifndef fisica_VarBuffer_h
#define fisica_VarBuffer_h

#include <iostream>
#include <fstream>

using namespace std;

class VarBuffer
{

public:
    VarBuffer(const unsigned int maxSize);
    ~VarBuffer();
    void clear();
    int read(fstream &file);
    int write(fstream &file);
    int pack(const void* object, unsigned short int size);
    int unpack(void* object);
    unsigned short int getBuffSize();
    char* getBuffer();

protected:
    unsigned short int bufferSize;
    unsigned short int maxSize;
    char* buffer;
};


#endif
