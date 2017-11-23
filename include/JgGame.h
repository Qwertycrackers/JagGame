#ifndef __JGGAME__
#include <SDL2/SDL.h>
#include <vector>
#include "JgUnit.h"

namespace JagGame {
class Game: public Unit {
	public:
	Game();
	Game(SDL_Renderer*); //use this constructor mostly
	//setSoundthing(soundthing)
	virtual int start(); //start the game. call this at the d
	virtual int init(); //implement this to do your initialization
	protected:
	bool quit;
	std::vector<SDL_Event> *events;
};
}

#define __JGGAME__
#endif
