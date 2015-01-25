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
	/*delete pointers*/
	for (unsigned int i = 0; i < boids.size(); i++)
	{
		delete boids[i];
	}
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
	/*the resultant velocities*/
	Vec2 v1, v2, v3;

	/*test each Boid*/
	for (unsigned int i = 0; i < boids.size(); i++)
	{
		/*test rule 1*/
		v1 = rule1(boids[i]);
		/*test rule 2*/
		v2 = rule2(boids[i]);
		/*test rule 3*/
		v3 = rule3(boids[i]);

		/*update the Boid velocity*/
		boids[i]->setVelocity(boids[i]->getVelocity() + v1 + v2 + v3);
		/*update the Boid position*/
		boids[i]->setPosition(boids[i]->getPosition() + boids[i]->getVelocity());
	}
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

/**************************************************************************************************************/

/*applies Boid rule 1*/
Vec2 Game::rule1(Boid * boid)
{
	/*the new velocity*/
	Vec2 vel = { 0.0f, 0.0f};
	return vel;
}

/**************************************************************************************************************/

/*applies Boid rule 2*/
Vec2 Game::rule2(Boid * boid)
{
	/*the new velocity*/
	Vec2 vel = { 0.0f, 0.0f };
	return vel;
}

/**************************************************************************************************************/

/*applies Boid rule 3*/
Vec2 Game::rule3(Boid * boid)
{
	/*the new velocity*/
	Vec2 vel = { 0.0f, 0.0f };
	return vel;
}