#pragma once
#include <vector>

#include "Vector2.h"

enum ShapeType {
	TRIANGLE = 0, SQUARE = 1
};

class Shape {
public:
	Shape(int, std::vector<Vector2>*);
	
	Vector getOrigin();
	std::vector<Vector2>* getLines();

private:
	std::vector<Vector2>* lines;
	Vector origin;

	int type;
};

