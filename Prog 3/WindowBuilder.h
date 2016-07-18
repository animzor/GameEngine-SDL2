#ifndef WINDOWBUILDER_H
#define WINDOWBUILDER_H
#include <SDL.h>
#include <string>
#include <iostream>

class WindowBuilder
{
public:
	WindowBuilder(std::string title, int width, int height);
	~WindowBuilder();

	SDL_Renderer* getRenderer();
	SDL_Event* getMainEvent();
	void begin();
	void end();

private:

	SDL_Renderer* renderer;
	SDL_Rect src;
	SDL_Rect dest;
	SDL_Window* window;
	SDL_Event* mainEvent;

};

#endif