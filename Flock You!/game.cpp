#include "game.h"

/**************************************************************************************************************/

/*Constructs the game object*/
Game::Game(StateManager * inStateManager, SDL_Renderer* inRenderer, int inWidth, int inHeight) 
	: State(inStateManager, inRenderer, inWidth, inHeight)
{
	/*initialize random seed*/
	srand(time(NULL));
	/*a texture of a white square*/
	whiteSquare = new Texture(renderer, 255, 255, 255);
	/*initialise a random number of Boid objects*/
	for (unsigned int i = 0; i < (rand() % 160) + 1; i++)
	{
		/*creates a Boid at a random position on the screen*/
		boids.push_back(new Boid(whiteSquare, Vec2((float)(rand() % 608), (float)(rand() % 448)), Vec2(4.0f, 4.0f)));
	}
}

/**************************************************************************************************************/

/*Destructs the game object*/
Game::~Game()
{
	
}

/**************************************************************************************************************/

/*handles inputs*/
bool Game::input()
{
	/*Check for user input*/
	SDL_Event incomingEvent;
	while (SDL_PollEvent(&incomingEvent))
	{
		switch (incomingEvent.type)
		{
		case SDL_QUIT: /*If player closes the window, end the game loop*/

			return false;
			break;

		case SDL_KEYDOWN:

			switch (incomingEvent.key.keysym.sym)
			{
			case SDLK_ESCAPE: /*If Escape is pressed, end the game loop*/

				return false;
				break;
			}
		}
	}
	return true;
}

/**************************************************************************************************************/

/*updates the game*/
void Game::update(float dt)
{
}

/**************************************************************************************************************/

/*draws the game*/
void Game::draw()
{
	/*set draw colour to purple*/
	SDL_SetRenderDrawColor(renderer, 0x66, 0x33, 0x99, 0xFF);

	/*Clear the entire screen to the set colour*/
	SDL_RenderClear(renderer);

	/*display the Boid objects*/
	for (unsigned int i = 0; i < boids.size(); i++)
	{
		/*display the Boid*/
		boids[i]->display(renderer);
	}

	/*display renderer*/
	SDL_RenderPresent(renderer);
}