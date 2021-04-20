#pragma once
#include <vector>

#include "Vector2.h"
#include "Shape.h"

class GameObject {
public:
	GameObject(bool, bool, Vector, Shape*);

	bool isAlive();
	bool isRenderable();

	Shape* getShape();
	Vector getOrigin();

private:
	bool alive;
	bool renderable;

	Shape *shape;
	Vector origin;
};

