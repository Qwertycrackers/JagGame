#include "JgUnit.h"
using namespace JagGame;


Unit::Unit() {}
/*! \param r The renderer to use for drawing. */
Unit::Unit(SDL_Renderer* r) {
	setRenderer(r);
}
/*! \returns The region occupied by the `Unit`. */
const SDL_Rect *const Unit::getRegion() {
	return region;
}
/*! \param r The rendering context for this `Unit` to now use. */
inline void Unit::setRenderer(SDL_Renderer *r) {
	renderer = r;
}
/*! \param r The region for the `Unit` to draw on. The `Unit` will own this `SDL_Rect` now, so don't delete it from elsewhere. */
inline void Unit::setRegion(SDL_Rect *r) {
	delete(region);
	region = r;
}
/*! This implementation of the method is intended to handle all the stuff which every Unit must to. When extending the class, do child-specific
	logic and then call this one. */
void Unit::receiveEvents(std::vector<SDL_Event> *events) {
	int size = events->size();	
	for(int i = 0; i < size; i++) {
		handleEvent((*events)[i]);
		for(int k = 0; k < nUnits; k++) {
			if(i == 0)
				unitEvents[k].clear();
			if(events->at(i).type & eventFlags[k] != 0)
				unitEvents[k].push_back(events->at(i));
			if(i == size-1)
				units[k]->receiveEvents(&unitEvents[k]);
		}
	}
}
/*! Don't forget to overload this in child classes to destroy the child's stuff, and then call this one. */
Unit::~Unit() {
	delete(region);
}
