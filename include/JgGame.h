#ifndef __JGGAME__
#include <SDL2/SDL.h>
#include <vector>
#include "JgUnit.h"

namespace JagGame {
class Game: public Unit {
	public:
	Game();
	Game(SDL_Renderer*): Unit(SDL_Renderer*);
	//setSoundthing(soundthing)
	virtual void start();
	protected:
	bool quit;
	SDL_Renderer renderer;
	std::vector<SDL_Event> *events;
}
}

#define __JGGAME__
#endif
