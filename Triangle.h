#include "Vector2.h"

#pragma once
class Triangle {
	public:
		Triangle(Vector2* lines[3]);

		Vector2 getOrigin();

		Triangle rotate(double degrees);
		Triangle scale(double scalar);
	private:
		Vector2* lines[3];
};

