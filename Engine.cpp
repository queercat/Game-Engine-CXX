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

	gameObjects.clear();

	std::vector<Vector2> lines;

	Vector2 line0 = Vector2(Vector(0, 0), Vector(0, 10));
	Vector2 line1 = Vector2(Vector(10, 10), Vector(5, 10));
	Vector2 line2 = Vector2(Vector(5, 10), Vector(0, 0));

	lines.push_back(line0);
	lines.push_back(line1);
	lines.push_back(line2);

	Shape triangle = Shape(ShapeType::TRIANGLE, &lines);
	GameObject obj = GameObject(true, true, Vector(width / 2, height / 2), &triangle);

	gameObjects.push_back(&obj);

	return 0;
}

void Engine::draw() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	while (!renderBus.empty()) {
		drawLine(renderBus.front());
		renderBus.pop();
	}
}

void Engine::logic() {
	GameObject* gameObj = gameObjects.front();
	Shape* shape = gameObj->getShape();
	std::vector<Vector2>* lines = shape->getLines();

	std::cout << lines;
}

void Engine::run() {
	running = true;

	while (running) {
		handleInput();
		logic();
		draw();
		update();
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