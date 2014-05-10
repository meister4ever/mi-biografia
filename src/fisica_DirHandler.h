// dirHandler.h




#ifndef DIRHANDLER_H_
#define DIRHANDLER_H_

#include <string>
#include <list>
#include "dirent.h"
using namespace std;

class DirHandler {
protected:
	string initialPathName;
	list<string>* fileList;

public:
	DirHandler(const char* path);
	virtual ~DirHandler();
	list<string>* getFileList();
	void getFiles(const char* dir);
	void setPath (const char* path);
};

#endif /* DIRHANDLER_H_ */
