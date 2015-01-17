#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include "stateManager.h"
#include "game.h"

int main(int argc, char *argv[])
{
	/*Initialise SDL*/
	if (SDL_Init(SDL_INIT_VIDEO) < 0) /*Check SDL initialisation*/
	{
		/*Failed initialisation*/
		std::cout << "Failed to initialise SDL" << std::endl;
		return -1;
	}

	/*Initialise SDL_ttf*/
	if (TTF_Init() < 0) /*Check SDL_ttf initialisation*/
	{
		/*Failed initialisation*/
		std::cout << "SDL_ttf init failed: " << TTF_GetError << std::endl;
		return -1;
	}

	/*Initialise SDL_mixer*/
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cout << "Failed to initialise SDL Mixer, Error is: " << Mix_GetError() << std::endl;
		return -1;
	}

	/*Time Check*/
	unsigned int lastTime = SDL_GetTicks();

	/*Create Window*/
	int winPosX = 100;
	int winPosY = 100;
	int winWidth = 640;
	int winHeight = 480;
	SDL_Window *window = SDL_CreateWindow("Flock You!",  /*The first parameter is the window title*/
		winPosX, winPosY,
		winWidth, winHeight,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	/*Create Renderer from the window*/
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

	/*setup state manager*/
	StateManager * stateManager = new StateManager();
	/*set the initial state*/
	stateManager->addState(new Game(stateManager, renderer, winWidth, winHeight));

	/*Start Game Loop*/
	bool go = true;
	while (go)
	{
		/*Time Check*/
		unsigned int current = SDL_GetTicks();
		float deltaTime = (float)(current - lastTime) / 1000.0f;
		lastTime = current;

		/*handle the current state inputs*/
		go = stateManager->input();

		/*update the current state*/
		stateManager->update(deltaTime);

		/*draw the states*/
		stateManager->draw();

		/*Time Limiter*/
		if (deltaTime < (1.0f / 50.0f))
		{
			SDL_Delay((unsigned int)(((1.0f / 50.0f) - deltaTime)*1000.0f));
		}
	}
	/*destroy data*/
	delete stateManager;
	SDL_DestroyWindow(window);
	SDL_Quit();
	return -1;
}