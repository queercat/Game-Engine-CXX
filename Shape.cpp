#include "Shape.h"

Shape::Shape(int type, std::vector<Vector2>* lines) {
	this->type = type;
	this->lines = lines;
}

Vector Shape::getOrigin() {
	double xOrigin = 0;
	double yOrigin = 0;

	std::vector<Vector2> line = *lines;
	
	switch (type) {
		case (ShapeType::TRIANGLE):
			double length = (line.at(0).getMagnitude());

			xOrigin = abs(length / 2) + line.at(0).getStart().getX();
			yOrigin = abs(sqrt(length - xOrigin)) + line.at(0).getStart().getY();
	}

	return Vector(xOrigin, yOrigin);
}

std::vector<Vector2>* Shape::getLines() {
	std::cout << this;
	return lines;
}