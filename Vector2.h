#pragma once
#include "Vector.h"

class Vector2 {
public:
	Vector2();
	Vector2(Vector start, Vector end);

	Vector2 add(Vector2);
	Vector2 sub(Vector2);
	Vector2 multiply(Vector2);
	Vector2 divide(Vector2);

	Vector2 rotate(double);
	Vector2 rotate(double, Vector);

	Vector getStart();
	Vector getEnd();

	double getMagnitude();

	void print();

private:
	Vector start;
	Vector end;
};