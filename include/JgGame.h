#ifndef __JGGAME__
#include <SDL2/SDL.h>
#include <vector>
#include "JgUnit.h"

namespace JagGame {
class Game: public Unit {
	public:
	Game();
	Game(SDL_Renderer*);
	//setSoundthing(soundthing)
	virtual int start();
	protected:
	bool quit;
	std::vector<SDL_Event> *events;
};
}

#define __JGGAME__
#endif
