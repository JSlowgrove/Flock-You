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
	/*initialise all of the rules to be off*/
	applyRule1 = applyRule2 = applyRule3 = false;
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

			case SDLK_RETURN: /*If Enter is pressed all rules are active*/

				/*activate all rules*/
				applyRule1 = applyRule2 = applyRule3 = true;
				break;

			case SDLK_1: /*If 1 is pressed only rule 1 is active*/

				/*activate rule 1*/
				applyRule1 = true;
				/*deactivate all other rules*/
				applyRule2 = applyRule3 = false;
				break;

			case SDLK_2: /*If 2 is pressed only rule 2 is active*/

				/*activate rule 2*/
				applyRule2 = true;
				/*deactivate all other rules*/
				applyRule1 = applyRule3 = false;
				break;

			case SDLK_3: /*If 3 is pressed only rule 3 is active*/

				/*activate rule3*/
				applyRule3 = true;
				/*deactivate all other rules*/
				applyRule1 = applyRule2 = false;
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
	/*initialise the resultant velocities*/
	Vec2 v1 = { 0.0f, 0.0f };
	Vec2 v2 = { 0.0f, 0.0f };
	Vec2 v3 = { 0.0f, 0.0f };

	/*test each Boid*/
	for (unsigned int i = 0; i < boids.size(); i++)
	{
		/*test rule 1 if active*/
		if (applyRule1)
		{
			v1 = rule1(i);
		}
		/*test rule 2 if active*/
		if (applyRule2)
		{
			v2 = rule2(i);
		}
		/*test rule 3 if active*/
		if (applyRule3)
		{
			v3 = rule3(i);
		}

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
Vec2 Game::rule1(int boidIndex)
{
	/*initialise the new velocity*/
	Vec2 vel = { 0.0f, 0.0f };
	/*initialise the center of mass*/
	Vec2 cOfM = { 0.0f, 0.0f };

	/*test each Boid*/
	for (unsigned int i = 0; i < boids.size(); i++)
	{
		/*if the Boid to be tested is not the inputed Boid*/
		if (i != boidIndex)
		{
			/*update the center of mass*/
			cOfM = boids[i]->getPosition() + cOfM;
		}
	}

	/*divide the center of mass by the number of Boid objects tested*/
	cOfM = cOfM / (boids.size() - 2);

	/*set the new velocity to the amount to move towards the Boid (1% of the distance in this case)*/
	vel = (cOfM - boids[boidIndex]->getPosition()) / 100;

	/*return the new velocity*/
	return vel;
}

/**************************************************************************************************************/

/*applies Boid rule 2*/
Vec2 Game::rule2(int boidIndex)
{
	/*the new velocity*/
	Vec2 vel = { 0.0f, 0.0f };
	return vel;
}

/**************************************************************************************************************/

/*applies Boid rule 3*/
Vec2 Game::rule3(int boidIndex)
{
	/*the new velocity*/
	Vec2 vel = { 0.0f, 0.0f };
	return vel;
}