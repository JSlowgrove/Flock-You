#pragma once

#include <vector>
#include "state.h"

/**
@brief Creates a StateManager object.
Creates a StateManager object to be inherited.
*/
class StateManager
{
private:
	/**the current states that are in use*/
	std::vector<State*> currentStates;
public:
	/**
	Constructs a StateManager object
	*/
	StateManager();

	/**
	Destructs a StateManager object
	*/
	~StateManager();

	/**
	Adds a new state
	Adds a new state to the current stack of states
	@param State * a pointer to the State in use
	*/
	void addState(State*);

	/**
	Changes to a new State
	Changes the current State to a new State
	@param State * a pointer to the State in use
	*/
	void changeState(State*);

	/**
	Removes the last State from the vector
	*/
	void removeLastState();

	/**
	Handles the user input
	The input function that will allow the equivalent input function to run in the current State
	@returns bool if false then quit the application
	*/
	bool input();

	/**
	Updates the current State
	The update function that will allow the equivalent update function to run in the current State
	@param float the delta time for use within the update function
	*/
	void update(float deltaTime);

	/**
	Draws the current State
	The draw function that will allow the equivalent draw function to run in the current State
	*/
	void draw();
};