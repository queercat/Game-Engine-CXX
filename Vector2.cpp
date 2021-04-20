#include "Vector2.h"
#include <math.h>
#include <iostream>

Vector2::Vector2() {
	this->start = Vector();
	this->end = Vector();
}

Vector2::Vector2(Vector start, Vector end) {
	this->start = start;
	this->end = end;
}

Vector Vector2::getStart() {
	return start;
}

Vector Vector2::getEnd() {
	return end;
}

Vector2 Vector2::add(Vector2 addend) {
	Vector sumStart = start.add(addend.getStart());
	Vector sumEnd = end.add(addend.getEnd());

	return Vector2(sumStart, sumEnd);
}

Vector2 Vector2::sub(Vector2 difference) {
	Vector diffStart = start.sub(difference.getStart());
	Vector diffEnd = end.sub(difference.getEnd());

	return Vector2(diffStart, diffEnd);
}

Vector2 Vector2::multiply(Vector2 multiplicand) {
	Vector prodStart = start.multiply(multiplicand.getStart());
	Vector prodEnd = end.multiply(multiplicand.getEnd());

	return (Vector2(prodStart, prodEnd));
}

Vector2 Vector2::divide(Vector2 dividend) {
	Vector divStart = start.divide(dividend.getStart());
	Vector divEnd = end.divide(dividend.getEnd());

	return (Vector2(divStart, divEnd));
}

// Assuming we're rotating around the start vector.
Vector2 Vector2::rotate(double degrees) {
	return this->rotate(degrees, start);
}

Vector2 Vector2::rotate(double degrees, Vector origin) {
	double radians = (degrees * 3.14159265) / 180;

	Vector rotatedStart = start.rotate(radians, origin);
	Vector rotatedEnd = end.rotate(radians, origin);

	return Vector2(rotatedStart, rotatedEnd);
}

double Vector2::getMagnitude() {
	double magnitude = 0;

	magnitude += pow(abs(end.getX() - start.getX()), 2);
	magnitude += pow(abs(end.getY() - start.getY()), 2);

	return sqrt(magnitude);
}

void Vector2::print() {
	std::cout << "Start [x: " << start.getX() << ", y: " << start.getY() << "]" << std::endl;
	std::cout << "End [x: " << end.getX() << ", y: " << end.getY() << "]" << std::endl;
}