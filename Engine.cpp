#include <stdio.h>
#include <SDL.h>
#include "Vector2.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void draw(SDL_Renderer* renderer, Vector2 line) {
	Vector start = line.getStart();
	Vector end = line.getEnd();

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawLine(renderer, start.getX(), start.getY(), end.getX(), end.getY());
}

void update(SDL_Renderer* renderer) {
	SDL_RenderPresent(renderer);
	SDL_Delay(.1);
}

int main(int argc, char* args[]) {
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return 1;
	} 

	window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (!window) {
		return 1;
	} 
		
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	if (!renderer) {
		return 1;
	}

	Vector2 line = Vector2(Vector(0, 0), Vector(SCREEN_WIDTH, SCREEN_HEIGHT));

	for (;;) {
		draw(renderer, line);
		update(renderer);

		line = line.rotate(1, Vector(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}