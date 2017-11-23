#include "JgGame.h"

using namespace JagGame;

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
	return 1; //consider returning some other values elsewhere for error returning
}

Game::Game(SDL_Renderer* r): Unit(r) {
}

Game::Game() {}
