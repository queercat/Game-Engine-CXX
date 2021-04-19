#include "Vector.h"
#include <iostream>

Vector::Vector() {
	this->x = 0;
	this->y = 0;
}

Vector::Vector(double x, double y) {
	this->x = x;
	this->y = y;
}

Vector Vector::add(Vector addend) {
	Vector sumVector = Vector(x + addend.getX(), y + addend.getY());

	return sumVector;
}

Vector Vector::sub(Vector difference) {
	Vector diffVector = Vector(x - difference.getX(), y - difference.getY());
	
	return diffVector;
}

Vector Vector::multiply(Vector multiplicand) {
	Vector mulVector = Vector(x * multiplicand.getX(), y * multiplicand.getY());

	return mulVector;
}

Vector Vector::divide(Vector dividend) {
	Vector divVector = Vector(x / dividend.getX(), y / dividend.getY());

	return divVector;
}

double Vector::getX() {
	return x;
}

double Vector::getY() {
	return y;
}

void Vector::print() {
	std::cout << "x: " << x << " y: " << y << std::endl;
}