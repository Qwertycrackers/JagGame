#include "JgTileDataEngine.h"
using namespace JagGame;
/*! \param c the starting origin cell.
 *  \param i the starting indentation level. */
TileDataEngine::TileDataEngine(Cell c, int i=5) {
	origin = c;
	defzoom = i;
}
/*! \returns The width of a square screen at the default zoom level. */
int TileDataEngine::getZoom() { return defzoom; };
/*! \returns Pointer to origin cell. Intended that the user modify this to change camera position. */
Cell *TileDataEngine::getOrigin() { return &origin; };
