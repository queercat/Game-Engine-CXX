#pragma once
#include <SDL.h>
#include <queue>
#include <vector>

#include "Vector2.h"
#include "GameObject.h"

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

	std::vector<GameObject*> gameObjects;
	std::queue<Vector2> renderBus;
	
	int width;
	int height;

	bool running = false;

	void logic();
	void draw();
	void update();

	void exit();

	void drawLine(Vector2);
	void handleInput();
	void handleKeyEvent(SDL_KeyboardEvent*);
};

