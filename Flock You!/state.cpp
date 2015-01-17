#include "state.h"

/**************************************************************************************************************/

/*Constructs the state object*/
State::State(StateManager * inStateManager, SDL_Renderer* inRenderer, int inWidth, int inHeight)
{
	/*sets the pointer to the state manager*/
	stateManager = inStateManager;
	/*sets the pointer to the renderer*/
	renderer = inRenderer;
	/*load the screen dimensions*/
	screenWidth = inWidth;
	screenHeight = inHeight;

}

/**************************************************************************************************************/

/*Destructs the state object*/
State::~State() 
{
}