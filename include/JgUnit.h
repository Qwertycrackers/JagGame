#ifndef __JGUNIT__
#include <SDL2/SDL.h>
#include <vector>

namespace JagGame {
/*!\brief Class Unit is the fundamental structure upon which JagGame works.

	The Unit class is given a region on the screen and a renderer. It holds logic and possibly loads assets in order to handle event
	stacks passed to it, which it processes (possibly by passing them to other `Units`). The `render` method draws whatever is necessary to
	display the `Unit` to the screen. Everything which appears on the screen in a JagGame is somehow a `Unit`. */
class Unit {
	public:
	Unit(); //!<\brief No-argument constructor for `Unit`. Remember to give it a `SDL_Renderer`.
	Unit(SDL_Renderer*); //!<\brief Set the renderer in some smooth motion. Prefer the use of this constructor.
	const SDL_Rect *const getRegion(); //!<\brief Get the `SDL_Rect` representing the region on the screen occupied by this `Unit`.
	virtual Uint32 getEventFlags(); //!<\brief Get a bitwise OR'd stack of `SDL_Event.type` flags desired by this `Unit`.
	virtual void render(); //!<\brief Draw this `Unit`'s stuff to the screen.
	inline void setRenderer(SDL_Renderer*); //!<\brief Set the renderer to to be used by this `Unit`.
	virtual void setRegion(SDL_Rect*); //!<\brief Set the screen region owned by this `Unit`.
	void receiveEvents(std::vector<SDL_Event>*); //!<\brief Give this `Unit` a stack of events to handle. Once per frame.
	virtual ~Unit(); 
	protected:
	virtual void handleEvent(SDL_Event&); //!<\brief Handle a single event. Children should define the actual logic for this.
	
	SDL_Renderer *renderer; //!<\brief The renderering context of this `Unit`.
	SDL_Rect *region; //!<\brief The region owned by this `Unit`.
	int nUnits; //!<\brief The number of sub-`Unit`s in this `Unit`. Children should set this.
	Unit **units; //!<\brief A C-style array containing pointers to the sub-`Unit`s. Children should create this.
	Uint32 eventFlags[]; //!<\brief A C-style array with the event flags for each sub-`Unit`.
	std::vector<SDL_Event> unitEvents[]; //!<\brief a C-style array of `vector`s containing the events to be passed to each sub-`Unit`.
	
};
}//namespace JagGame
#define __JGUNIT__
#endif
