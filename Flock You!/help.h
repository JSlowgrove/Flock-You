#pragma once

#include <SDL.h>
#include "state.h"
#include "stateManager.h"
#include "audio.h"
#include "text.h"
#include "game.h"

/**
@brief Creates an Help object that inherits State
Creates an Help object that inherits State and runs the Help.
*/
class Help : public State
{
private:
	/*rendered text*/
	std::vector<Text *> text;

public:
	/**
	Constructs an Help object
	@param StateManager * a pointer to the StateManager
	@param SDL_Renderer * a pointer to the renderer
	@param int the screen width
	@param int the screen height
	*/
	Help(StateManager *, SDL_Renderer *, int, int);

	/**
	Destructs an Help object
	*/
	~Help();

	/**
	Handles the Help input
	@returns bool if false the quit the Help State
	*/
	bool input();

	/**
	A function to update the Help
	A function to update the Help to allow the Help to run
	@param float the delta time
	*/
	void update(float deltaTime);

	/**
	A function to draw to the screen
	*/
	void draw();
};