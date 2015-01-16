#pragma once

#include <SDL.h>
#include <vector>
#include <time.h>
#include "texture.h"
#include "boid.h"

/**
@brief Creates an Game object that runs the Game
Creates an Game object that runs the Game.
*/
class Game
{
private:
	/*a pointer to the renderer*/
	SDL_Renderer * renderer;
	/*the dimensions of the screen*/
	int screenWidth;
	int screenHeight;
	/*a texture of a white square*/
	Texture * whiteSquare;
	/*a vector of Boid objects*/
	std::vector<Boid*> boids;
public:
	/**
	Constructs an Game object
	Constructs the Game object
	@param SDL_Renderer * a pointer to the renderer
	@param int the screen width
	@param int the screen height
	*/
	Game(SDL_Renderer *, int, int);

	/**
	De-constructs an Game object
	De-constructs the Game object
	*/
	~Game();

	/**
	Handles the game input
	@returns bool if false the quit game
	*/
	bool input();

	/**
	Update the Game object
	@param float the deltaTime
	@returns bool if false the quit game
	*/
	bool update(float);

	/**
	Draws the Game object
	*/
	void draw();
};