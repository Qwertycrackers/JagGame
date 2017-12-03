#ifndef __JGUNIT__
#include <SDL2/SDL.h>
#include <vector>

namespace JagGame {
class Unit {
	public:
	const SDL_Rect *const getRegion();
	virtual Uint32 getEventFlags();
	virtual void render();
	inline void setRenderer(SDL_Renderer*);
	inline void setRegion(SDL_Rect*);
	void receiveEvents(std::vector<SDL_Event>&);
	virtual void destroy();

	protected:
	virtual void handleEvent(SDL_Event&);
	
	SDL_Renderer *renderer;
	SDL_Rect *region;
	int nUnits;
	Unit **units;
	Uint32 eventFlags[];
	std::vector<SDL_Event> unitEvents[];
};
}//namespace JagGame

#define __JAGUNIT__
#endif
