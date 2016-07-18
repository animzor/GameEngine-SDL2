#include "WindowBuilder.h"





WindowBuilder::WindowBuilder(std::string title, int width, int heigth)
{
	//Initialize everything SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	mainEvent = new SDL_Event;

	//Create the gamewindow with title and window size provided
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, heigth, SDL_WINDOW_SHOWN);

	//Initialize the renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}


WindowBuilder::~WindowBuilder()
{

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	delete mainEvent;

}

SDL_Renderer * WindowBuilder::getRenderer()
{
	return renderer;
}

SDL_Event * WindowBuilder::getMainEvent()
{
	return mainEvent;
}

void WindowBuilder::begin()
{

	SDL_RenderClear(renderer);
	SDL_PollEvent(mainEvent);

}

void WindowBuilder::end() {

	SDL_RenderPresent(renderer);

}
