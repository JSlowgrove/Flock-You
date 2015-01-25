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
	Vec2 v4 = { 0.0f, 0.0f };

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

		/*apply boundaries*/
		v4 = roughBoundaries(i);

		/*update the Boid velocity*/
		boids[i]->setVelocity(boids[i]->getVelocity() + v1 + v2 + v3 + v4);
		/*limit the velocity of the Boid*/
		limitVelocity(i);
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

	/*test each Boid*/
	for (unsigned int i = 0; i < boids.size(); i++)
	{
		/*if the Boid to be tested is not the inputed Boid*/
		if (i != boidIndex)
		{
			/*if the Boid is closer than 10 pixels to another Boid on the x axis (using absolute values)*/
			if (std::abs(boids[boidIndex]->getPosition().x - boids[i]->getPosition().x) < 10)
			{
				vel.x = vel.x - (boids[i]->getPosition().x - boids[boidIndex]->getPosition().x);
			}

			/*if the Boid is closer than 10 pixels to another Boid on the y axis (using absolute values)*/
			if (std::abs(boids[boidIndex]->getPosition().y - boids[i]->getPosition().y) < 10)
			{
				vel.y = vel.y - (boids[i]->getPosition().y - boids[boidIndex]->getPosition().y);
			}
		}
	}

	/*return the new velocity*/
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

/**************************************************************************************************************/

/*applies Boid rough boundaries*/
Vec2 Game::roughBoundaries(int boidIndex)
{
	/*initialise the new velocity*/
	Vec2 vel = { 0.0f, 0.0f };

	/*check if the Boid is off the right of the screen*/
	if (boids[boidIndex]->getPosition().x > screenWidth)
	{
		/*set a negative x velocity*/
		vel.x = -10.0f;
	}
	/*check if the Boid is off the right of the screen*/
	else if (boids[boidIndex]->getPosition().x < 0)
	{
		/*set a positive x velocity*/
		vel.x = 10.0f;
	}

	/*check if the Boid is off the bottom of the screen*/
	if (boids[boidIndex]->getPosition().y > screenHeight)
	{
		/*set a negative y velocity*/
		vel.y = -10.0f;
	}
	/*check if the Boid is off the top of the screen*/
	else if (boids[boidIndex]->getPosition().y < 0)
	{
		/*set a positive y velocity*/
		vel.y = 10.0f;
	}

	/*return the new velocity*/
	return vel;
}

/**************************************************************************************************************/

/*limit the velocity of the Boid*/
void Game::limitVelocity(int boidIndex)
{
	/*the max velocity*/
	float maxVel = 25.0f;

	/*test if the absolute of the x velocity is greater than the max velocity*/
	if (std::abs(boids[boidIndex]->getVelocity().x) > maxVel)
	{
		/*work out if negative or positive*/
		float sign = boids[boidIndex]->getVelocity().x / std::abs(boids[boidIndex]->getVelocity().x);
		/*set the x velocity to the max velocity*/
		boids[boidIndex]->setVelocity(Vec2(maxVel * sign, boids[boidIndex]->getVelocity().y));
	}

	/*test if the absolute of the y velocity is greater than the max velocity*/
	if (std::abs(boids[boidIndex]->getVelocity().y) > maxVel)
	{
		/*work out if negative or positive*/
		float sign = boids[boidIndex]->getVelocity().y / std::abs(boids[boidIndex]->getVelocity().y);
		/*set the y velocity to the max velocity*/
		boids[boidIndex]->setVelocity(Vec2(boids[boidIndex]->getVelocity().x, maxVel * sign));
	}
}
