//Reg.cpp


#include "logica_Reg.h"
#include <string>
using namespace std;

Reg::Reg(int id, int fileAdress) {
	this->id=id;
	this->fileAdress=fileAdress;
}

Reg::~Reg() {
}

void Reg::setFileAdress(int fileAdress){
	this->fileAdress=fileAdress;
}

int Reg::getFileAdress(){
	return this->fileAdress;
}
int Reg:: getId(){
	return id;
}

int Reg:: getSize(){
	return sizeof(this->id)+sizeof(this->fileAdress);
}
