#include "JgGridUnit.h"
using namespace JagGame;
GridUnit() {}
/*! \param r The rendering context. */
GridUnit(SDL_Renderer *r): Unit(r) {}

~GridUnit() {}
/*! \returns A bitwise OR'd flag representing the `SDL_Event` types accepted. */
Uint32 GridUnit()::getEventFlags() {
	return SDL_KEYDOWN|SDL_MOUSEMOTION|SDL_MOUSEBUTTON;
}
/*! Set the region occupied by this `GridUnit`. 
	\param r the region to be used. */
void setRegion(SDL_Rect *r) {
	Unit::setRegion(r);
	int param = 
/*! \param *events A pointer to a `std::vector` containing the events to handle. */
void GridUnit::handleEvent(SDL_Event &e) {
	if(e.type == SDL_MOUSEMOTION)
		engine->setCurrentCell(findMouseCell(e));
	if(e.type == SDL_MOUSEBUTTON)
		engine->selectCell(findMouseCell(e),e);
	if(e.type == SDL_KEYDOWN)
		handleKeyInput(e);
}

void GridUnit::render() {

}
