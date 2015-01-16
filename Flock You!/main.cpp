#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
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

	/*Create Game*/
	Game * game = new Game(renderer, winWidth, winHeight);

	/*Start Game Loop*/
	bool go = true;
	while (go)
	{
		/*Time Check*/
		unsigned int current = SDL_GetTicks();
		float deltaTime = (float)(current - lastTime) / 1000.0f;
		lastTime = current;

		/*handle the inputs to the game*/
		go = game->input();

		/*check if the game is able to continue*/
		if (go)
		{ 
			/*update the game if not to be exited*/
			go = game->update(deltaTime);
		}

		/*draw the game*/
		game->draw();

		/*Time Limiter*/
		if (deltaTime < (1.0f / 50.0f))
		{
			SDL_Delay((unsigned int)(((1.0f / 50.0f) - deltaTime)*1000.0f));
		}
	}
	/*destroy data*/
	delete game;
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}