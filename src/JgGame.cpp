#include "JgGame.h"

using namespace JagGame;
/*! Start a loop of receiving `SDL_Event`s and rendering. Intended to be used with Vsync enabled, unpredictable otherwise. 
 * 	After a testable version is working, I'll write it to handle lack of Vsync.
	\returns An error code if something went wrong, 1 otherwise. */
int Game::start() {
	events = new std::vector<std::shared_ptr<SDL_Event>>();
	SDL_Event *event;
	while(!quit) {
		while(SDL_PollEvent(event)) {
			events->push_back(std::shared_ptr<SDL_Event>(event));
			handleEvent(event); //Game's own event response. For menus and stuff.
		}
		Unit::receiveEvents(events); //pass events down to child `Unit`s
		events->clear(); //event stack is no longer needed
		SDL_RenderClear(renderer); //clear the screen for rendering
		render(); //draw everything
		SDL_RenderPresent(renderer); //show the drawn screen
	}
	delete(events); //delete the event stack
	return 1; //consider returning some other values elsewhere for error 
}
/*! \param r The `SDL_Renderer` for this `Game` to use. */
Game::Game(SDL_Renderer* r): Unit(r) {}

Game::Game() {}

Game::~Game() {}
