#include "Vector2.h"

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

Vector2 Vector2::rotate(double degrees) {
	double radians = (degrees * 3.14159265) / 180;
}

Vector2 Vector2::rotate(double degrees, Vector origin) {

}