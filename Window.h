#pragma once

class Window {
	public:
			Window(unsigned int width, unsigned int height);
			
			void resize(unsigned int width, unsigned int height);
			void printSize();

	private:
		unsigned int width;
		unsigned int height;
};