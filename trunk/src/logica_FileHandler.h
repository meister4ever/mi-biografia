// fileHandler.h


#ifndef FILEHANDLER_H_
#define FILEHANDLER_H_

#include <string>

using namespace std;

class FileHandler {
public:
	FileHandler();
	virtual ~FileHandler();
	string getFirstLine(string fileName);
	string getAuthor(string line);
	string getSourceName(string line);
};

#endif /* FILEHANDLER_H_ */
