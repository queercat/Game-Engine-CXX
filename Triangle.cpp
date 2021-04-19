#include "Triangle.h"

Vector2 Triangle::getOrigin() {
	double xOrigin = 0;
	double yOrigin = 0;
	
	for (int index = 0; index < 3; index++) {
		Vector2 line = *lines[index];

		xOrigin += line.getX();
		yOrigin += line.getY();
	}
}

Triangle Triangle::rotate(double degrees) {
	for (int index = 0; index < 3; index++) {
		Vector2 line = *lines[index];
		
		*lines[index] = line.rotate(degrees, this->getOrigin());
	}
}