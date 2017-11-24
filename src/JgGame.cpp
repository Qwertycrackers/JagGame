#include "JgGame.h"

using namespace JagGame;
/*! Start a loop of receiving `SDL_Event`s and rendering. Intended to be used with Vsync enabled, unpredictable otherwise. 
	@returns An error code if something went wrong, 1 otherwise. */
int Game::start() {
	events = new std::vector<SDL_Event>();
	SDL_Event *event;
	while(!quit) {
		while(SDL_PollEvent(event)) {
			events->push_back(*event);		
		}
		for(SDL_Event e : *events) {
			handleEvent(e);
		}
		events->clear();
		SDL_RenderClear(renderer);
		render();
		SDL_RenderPresent(renderer);
	}
	return 1; //consider returning some other values elsewhere for error 
}
/*! \param r The `SDL_Renderer` for this `Game` to use. */
Game::Game(SDL_Renderer* r): Unit(r) {
}

Game::Game() {}

Game::~Game() {
	delete(events);
}
