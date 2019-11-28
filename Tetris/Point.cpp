#include "Point.h"
#include <sstream>


Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(int newX, int newY) {
	x = newX;
	y = newY;
}

void Point::setX(int x) {
	this->x = x;
}

void Point::setY(int y) {
	this->y = y;
}

void Point::setXY(int x, int y) {
	this->x = x;
	this->y = y;
}

void Point::swapXY() {
	//std::swap(x, y);
	int temp = x;
	x = y;
	y = temp;
}

void Point::multiplyX(int factor) {
	x = x * factor;
}

void Point::multiplyY(int factor) {
	this->y = y * factor;
}

std::string Point::toString() const {
	std::stringstream ss;
	ss << "[" << x << "," << y << "]";
	std::string str = ss.str();
	return str;
}