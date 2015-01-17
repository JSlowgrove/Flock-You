#pragma once

#include <SDL.h>
#include <vector>
#include <time.h>
#include "state.h"
#include "stateManager.h"
#include "texture.h"
#include "audio.h"
#include "boid.h"

/**
@brief Creates an Game object that inherits State
Creates an Game object that inherits State and runs the Game.
*/
class Game : public State
{
private:
	/*a texture of a white square*/
	Texture * whiteSquare;
	/*a vector of Boid objects*/
	std::vector<Boid*> boids;
public:
	/**
	Constructs an Game object
	@param StateManager * a pointer to the StateManager
	@param SDL_Renderer * a pointer to the renderer
	@param int the screen width
	@param int the screen height
	*/
	Game(StateManager *, SDL_Renderer *, int, int);

	/**
	Destructs an Game object
	*/
	~Game();

	/**
	Handles the Game input
	@returns bool if false the quit the Game State
	*/
	bool input();

	/**
	A function to update the Game
	A function to update the Game to allow the Game to run
	@param float the delta time
	*/
	void update(float deltaTime);

	/**
	A function to draw to the screen
	*/
	void draw();
};