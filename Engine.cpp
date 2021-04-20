#include "Engine.h"

const int SUCCESS = 0;
const int FAILURE = 1;

Engine::Engine(int width, int height) {
	this->width = width;
	this->height = height;
}

int Engine::init() {
	// Attempt to intiailize video.
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return FAILURE;
	}

	window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	
	// Attempt to initialize the window.
	if (!window) {
		return FAILURE;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	if (!renderer) {
		return 1;
	}

	return 0;
}

void Engine::run() {
	running = true;

	while (running) {
		handleInput();
	}

	exit();
}

void Engine::handleInput() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_KEYUP:
				handleKeyEvent(&event.key);
				break;

			case SDL_QUIT:
				running = false;
				break;

		}
	}
}

void Engine::handleKeyEvent(SDL_KeyboardEvent* key) {	
	switch (key->keysym.sym) {
		case (SDLK_ESCAPE): {
			running = false;
			break;
		}
	}
}

void Engine::drawLine(Vector2 line) {
	Vector start = line.getStart();
	Vector end = line.getEnd();

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawLine(renderer, start.getX(), start.getY(), end.getX(), end.getY());
}

void Engine::update() {
	SDL_RenderPresent(renderer);
	SDL_Delay(.1);
}

void Engine::exit() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}