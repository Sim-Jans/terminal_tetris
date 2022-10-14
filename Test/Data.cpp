#include "Data.h"
#include <iostream>
using namespace std;

int Data:: setX(int x) {
	return this->x = x;
}
int Data::getX() {
	return this->x;
}
int Data::setY(int y) {
	return this->y = y;
}
int Data::getY() {
	return this->y;
}

Data::Data(int x, int y) {
	this->x = x;
	this -> y = y;
}
Data::~Data() {
	cout << "메모리 제거됨";
}

int Data::run() {
	return this->x + this->y;
}
