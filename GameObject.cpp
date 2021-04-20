#include "GameObject.h"

GameObject::GameObject(bool alive, bool renderable, Vector origin, Shape* shape) {
	this->alive = alive;
	this->renderable = renderable;

	this->origin = origin;
	this->shape = shape;
}

bool GameObject::isAlive() {
	return alive;
}

bool GameObject::isRenderable() {
	return renderable;
}

Vector GameObject::getOrigin() {
	return origin;
}

Shape* GameObject::getShape() {
	return shape;
}