#include "JgGridUnit.h"
using namespace JagGame;
/*! \param r The rendering context. 
 *  \param reg the region
 *  \param e the `TileDataEngine` */
GridUnit::GridUnit(SDL_Renderer *r, SDL_Rect *reg, TileDataEngine *e): Unit(r) {
	region = reg;
	engine = e;
	numTiles = engine->getZoom();
	origin = engine->getOrigin();
	updateTileWidth();
}
/*! \returns A bitwise OR'd flag representing the `SDL_Event` types accepted. */
Uint32 GridUnit::getEventFlags() {
	return SDL_KEYDOWN|SDL_MOUSEMOTION|SDL_MOUSEBUTTONDOWN; //perhaps do more logic here later
}
/*! Set the region occupied by this `GridUnit`. 
	\param r the region to be used. */
void GridUnit::setRegion(SDL_Rect *r) {
	Unit::setRegion(r);
	updateTileWidth();
}
/*! Update the onscreen tile width in response to something. */
void GridUnit::updateTileWidth() {
	tileWidth = ((region->w > region->h) ? region->h : region->w)/numTiles;
}
/*! Set the `TileDataEngine`.
 * \param e Pointer to the engine to use */
void GridUnit::setTileDataEngine(TileDataEngine *e) {
	engine = e;
	origin = engine->getOrigin();
	numTiles = engine->getZoom();
	updateTileWidth();
}
/*! \param *events The event to handle. */
void GridUnit::handleEvent(SDL_Event *e) {
	if(e->type == SDL_MOUSEMOTION && (e->motion.x >= region->x) && (e->motion.y >= region->y))
		engine->setCurrentCell(findMouseCell(e));
	if(e->type == SDL_MOUSEBUTTONDOWN && (e->button.x >= region->x) && (e->button.y >= region->y))
		engine->selectCell(findMouseCell(e),e);
	if(e->type == SDL_KEYDOWN)
		handleKeyInput(e);
}
/*! Handle a single key input
 * 	\param e The SDL_KeyEvent to handle */
void GridUnit::handleKeyInput(SDL_Event *e) {
	switch(e->key.keysym.sym) {
		case(SDLK_RIGHTBRACKET):
			numTiles += 3; //probably stop using magic numbers at some point
			updateTileWidth();
			break;
		case(SDLK_LEFTBRACKET):
			numTiles = (numTiles - 3 < 0) ? numTiles : numTiles - 3;
			updateTileWidth();
			break;
	}
	engine->handleKeyInput(e);
}
/*! Find the cell which the mouse is currently over 
 *  \param e The SDL_MouseEvent with the data
 *  \returns A `Cell` representing the selected cell, offset from `origin` */
Cell GridUnit::findMouseCell(SDL_Event *e) {
	int i, j;
	if(e->type == SDL_MOUSEMOTION) {
		i = (e->motion.x - region->x)/tileWidth;
		j = (e->motion.y - region->y)/tileWidth;
	}
	if(e->type == SDL_MOUSEBUTTONDOWN) {
		i = (e->button.x - region->x)/tileWidth;
		j = (e->button.y - region->y)/tileWidth;
	}
	return Cell(i,j);
}

/*! Render a frame of data from the `TileDataEngine` onto the region prescribed to this `Unit`. */
void GridUnit::render() {
	int i = 0; //counter in the x
	int j = 0; //counter in the y
	SDL_Texture *sprite; //whatever's on the tile
	SDL_Texture *floor; //the tile's backround
	SDL_Rect tile; //rectangle where the current tile will go
	tile.x = region->x; //set starting x and y to upper corner of region.
	tile.y = region->y;
	tile.h = tileWidth; //make area as large as one tile (always square)
	tile.w = tileWidth;
	while(tile.x < region->x + region->w) { //until we've looped across the x
		while(tile.y < region->y + region->h) { //until we've looped across the y
			engine->getTextures(i,j,sprite,floor); //Set sprite and floor to point at the textures for the cell
			SDL_RenderCopy(renderer, floor, NULL, &tile); //render the floor
			SDL_RenderCopy(renderer, sprite, NULL, &tile); //render the sprite
			j++;
			tile.y += tileWidth;
		}
		j = 0;
		i++;
		tile.x += tileWidth;
	}
}
