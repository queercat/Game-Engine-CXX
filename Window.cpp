#include "Window.h"
#include <iostream>

Window::Window(unsigned int width, unsigned int height) {
	this->width = width;
	this->height = height;
}

void Window::resize(unsigned int width, unsigned int height) {
	this->width = width;
	this->height = height;
}

void Window::printSize() {
	std::cout << "Width: " << width << " " << "Height: " << height << std::endl;
}