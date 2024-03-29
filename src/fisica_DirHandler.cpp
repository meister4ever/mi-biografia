#include "fisica_DirHandler.h"
#include <iostream>
#include <stdio.h>
#include <sstream>
using namespace std;

DirHandler::DirHandler(const char* path) {
	this->fileList= new list<string>;
	this->initialPathName=path;
}

DirHandler::~DirHandler() {
	delete this->fileList;
}

list<string>* DirHandler::getFileList() {
	return this->fileList;
}

void DirHandler::setPath(const char* path){
	this->initialPathName=path;
}


void DirHandler::getFiles(const char* dir){
	DIR *dirStream;
	struct dirent *dirEntry  = 0;
	dirStream = opendir(dir);

	if (! dirStream)
		return ;
	while ((dirEntry = readdir(dirStream))){
		if (dirEntry->d_name[0]=='.')
			continue;
		if (dirEntry->d_type == DT_DIR){
			stringstream tmp;
			tmp << dir << "/" << dirEntry->d_name ;
			this->setPath(tmp.str().c_str());
			this->getFiles(tmp.str().c_str());
		}
		else{
			string actualPath = dir;
			actualPath += "/";
			actualPath += dirEntry->d_name;
			this->fileList->push_back(actualPath);
		}
	}
	(void) closedir(dirStream);
}
