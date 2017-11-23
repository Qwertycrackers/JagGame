#include "JgUnit.h"
using namespace JagGame;


Unit::Unit() {}

Unit::Unit(SDL_Renderer* r) {
	setRenderer(r);
}

const SDL_Rect *const Unit::getRegion() {
	return region;
}


inline void Unit::setRenderer(SDL_Renderer *r) {
	renderer = r;
}

inline void Unit::setRegion(SDL_Rect *r) {
	delete(region);
	region = r;
}

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

void Unit::destroy() {
	delete(region);
}
