#include "help.h"

/**************************************************************************************************************/

/*Constructs the Help object*/
Help::Help(StateManager * inStateManager, SDL_Renderer* inRenderer, int inWidth, int inHeight)
	: State(inStateManager, inRenderer, inWidth, inHeight)
{
	/*initialise the text*/
	text.push_back(new Text("Hit Delete to Quit", "font/Underdog_tt_hinted.ttf", renderer, 102, 51, 153));
	text.push_back(new Text("Hit Escape to Return", "font/Underdog_tt_hinted.ttf", renderer, 102, 51, 153));
	text.push_back(new Text("Commands:", "font/Underdog_tt_hinted.ttf", renderer, 102, 51, 153));
	text.push_back(new Text("-Press enter to apply all rules.", "font/Underdog_tt_hinted.ttf", renderer, 102, 51, 153));
	text.push_back(new Text("-Press 1 to apply rule 1 only.", "font/Underdog_tt_hinted.ttf", renderer, 102, 51, 153));
	text.push_back(new Text("-Press 2 to apply rule 2 only.", "font/Underdog_tt_hinted.ttf", renderer, 102, 51, 153));
	text.push_back(new Text("-Press 3 to apply rule 3 only.", "font/Underdog_tt_hinted.ttf", renderer, 102, 51, 153));
	text.push_back(new Text("-Hold Space to scatter the flock.", "font/Underdog_tt_hinted.ttf", renderer, 102, 51, 153));
	text.push_back(new Text("Rules:", "font/Underdog_tt_hinted.ttf", renderer, 102, 51, 153));
	text.push_back(new Text("-Rule 1 = Boids try to fly towards the centre of mass", "font/Underdog_tt_hinted.ttf", renderer, 102, 51, 153));
	text.push_back(new Text("of neighbouring boids.", "font/Underdog_tt_hinted.ttf", renderer, 102, 51, 153));
	text.push_back(new Text("-Rule 2 = Boids try to keep a small distance away from other", "font/Underdog_tt_hinted.ttf", renderer, 102, 51, 153));
	text.push_back(new Text("objects (including other boids).", "font/Underdog_tt_hinted.ttf", renderer, 102, 51, 153));
	text.push_back(new Text("-Rule 3 = Boids try to match velocity with near boids.", "font/Underdog_tt_hinted.ttf", renderer, 102, 51, 153));

}

/**************************************************************************************************************/

/*Destructs the Help object*/
Help::~Help()
{
	/*delete text*/
	for (unsigned int i = 0; i < text.size(); i++)
	{
		delete text[i];
	}
}

/**************************************************************************************************************/

/*handles inputs*/
bool Help::input()
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
			case SDLK_DELETE: /*If Delete is pressed, end the game loop*/

				return false;
				break;

			case SDLK_ESCAPE: /*If Escape is pressed, return to game*/
				/*return to the game*/
				stateManager->changeState(new Game(stateManager, renderer, screenWidth, screenHeight));
				return true;
				break;
			}
			break;
		}
	}
	return true;
}

/**************************************************************************************************************/

/*updates the Help*/
void Help::update(float dt)
{
}

/**************************************************************************************************************/

/*draws the Help*/
void Help::draw()
{
	/*set draw colour to purple*/
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	/*Clear the entire screen to the set colour*/
	SDL_RenderClear(renderer);

	/*display text*/
	text[0]->pushToScreen(renderer, screenWidth - 210, 10, 200, 20);
	text[1]->pushToScreen(renderer, 10, 10, 200, 20);
	text[2]->pushToScreen(renderer, 10, 70, 100, 20);
	text[3]->pushToScreen(renderer, 10, 100, 300, 20);
	text[4]->pushToScreen(renderer, 10, 130, 280, 20);
	text[5]->pushToScreen(renderer, 10, 160, 280, 20);
	text[6]->pushToScreen(renderer, 10, 190, 280, 20);
	text[7]->pushToScreen(renderer, 10, 220, 320, 20);
	text[8]->pushToScreen(renderer, 10, 280, 60, 20);
	text[9]->pushToScreen(renderer, 10, 310, 550, 20);
	text[10]->pushToScreen(renderer, 110, 340, 220, 20);
	text[11]->pushToScreen(renderer, 10, 370, 580, 20);
	text[12]->pushToScreen(renderer, 110, 400, 260, 20);
	text[13]->pushToScreen(renderer, 10, 430, 500, 20);

	/*display renderer*/
	SDL_RenderPresent(renderer);
}