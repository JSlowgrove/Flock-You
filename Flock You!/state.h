#pragma once

#include <SDL.h>
#include <iostream>
#include <string.h>

/**forward declaration of StateManager for the pointer to the StateManager*/
class StateManager;

/**
@brief Creates a State object.
Creates a State object to be inherited.
*/
class State
{
protected:
	/*A pointer to the state manager*/
	StateManager * stateManager;
	/*The render to display to*/
	SDL_Renderer * renderer;
	/*the dimensions of the screen*/
	int screenWidth;
	int screenHeight;
public:
	/**
	Constructs a State object
	@param StateManager * a pointer to the StateManager
	@param SDL_Renderer * a pointer to the renderer in use.
	@param int the screen width
	@param int the screen height
	*/
	State(StateManager *, SDL_Renderer *, int, int);

	/**
	A virtual destructor for the State object
	*/
	virtual ~State();

	/**
	A virtual function to handle the user input
	A virtual function to handle the user input for use with the State
	@returns bool if false then quit State
	*/
	virtual bool input() = 0;

	/**
	A virtual function to update the State
	A virtual function to update the State to allow the State to run
	@param float the delta time
	*/
	virtual void update(float deltaTime) = 0;

	/**
	A virtual function to draw to the screen
	A virtual function to draw to the screen using the renderer
	*/
	virtual void draw() = 0;
};