#ifndef __JGGAME__
#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include "JgUnit.h"

namespace JagGame {
/*!\brief Class Game is the instantiable Game object, which is extended and `start()`ed in order to run the game.
	
	The process to start a `Game` should be to initialize SDL2 and whatever other extensions one needs (probably SDL_image and SDL_sound),
	and then `init()` and `start()` the `Game`. Don't forget to create it a window and rendering context, passing in the latter with
	`setRenderer` or the constructor. */
class Game: public Unit {
	public:
	Game(); //!<\brief No-argument constructor for `Game`. Don't forget to give it the rendering context.
	Game(SDL_Renderer*); //!<\brief Constructor accepting an `SDL_Renderer*`. Favor the use of this one.
	//setSoundthing(soundthing)
	int start(); //!<\brief Start the `Game`. Will return when something has caused the `Game` to quit.
	virtual int init(); //!<\brief Implement this to do your initialization.
	virtual ~Game(); //!<\brief Destroy this `Unit`s stuff in preparation for `delete`ion.
	protected:
	bool quit; //!<\brief The flag for when the `Game` should quit.
	std::vector<std::shared_ptr<SDL_Event>> *events; //!<\brief The `vector` containing the events for this frame. Used by the game loop, but child classes mighwant to mess with it.
	
};
}

#define __JGGAME__
#endif
