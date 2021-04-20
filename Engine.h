#pragma once
#include <SDL.h>
#include <queue>

#include "Vector2.h"

class Engine
{
public:
	Engine(int, int);
	int init();
	void run();

private:
	SDL_Window* window = NULL;
	SDL_Surface* surface = NULL;
	SDL_Renderer* renderer = NULL;

	std::queue<Vector2> renderBus;
	
	bool running;

	int width;
	int height;

	void update();
	void exit();

	void drawLine(Vector2);
	void handleInput();
	void handleKeyEvent(SDL_KeyboardEvent*);
};

