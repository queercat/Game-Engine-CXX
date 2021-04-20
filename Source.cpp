#include <stdio.h>
#include <SDL.h>

#include "Vector2.h"
#include "Engine.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
	Engine gameEngine = Engine(SCREEN_WIDTH, SCREEN_HEIGHT);

	if (gameEngine.init() > 0) {
		std::cout << "Failed to initialize engine!" << std::endl;
		return 1;
	}

	gameEngine.run();

	return 0;
}