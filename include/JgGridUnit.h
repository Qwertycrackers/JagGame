#ifndef __JGGRIDUNIT__
#include <SDL2/SDL.h>
#include "JgUnit.h"
#include "JgTileEngine.h"
#include "JgCell.h"
#include <vector>
namespace JagGame{
/*!\brief Class GridUnit renders a grid to its region and renders tile data to the grid in concordance with its TileDataEngine.

	To use GridUnit, simply implement the TileDataEngine interface and give an instance of such to the GridUnit, which will handle the
	rendering, panning and zooming. 
	\see TileDataEngine */
class GridUnit: public Unit {
	public:
	GridUnit(); //!<\brief No-argument constructor
	~GridUnit(); //!<\brief Destructor
	GridUnit(SDL_Renderer*); //!<\brief Quickly set the renderer in constructor.
	Uint32 getEventFlags(); //!<\brief Get the GridUnit event flags. It normally needs KeyEvents and MouseEvents.
	void render(); //!<\brief Render this `Unit` to its region.
	void setRegion(SDL_Rect *r); //!<\brief Overloaded `setRegion()`.
	protected:
	void handleEvent(SDL_Event&); //!<\brief Handle a single event.
	inline Cell findMouseCell(SDL_Event&); //!<\brief Find the cell coordinates of a mouse event.
	inline void handleKeyInput(SDL_Event&) //!<\brief Handle a key event for input.
	inline void updateTileWidth(); //!<\brief Change tile width in response to various things
	TileDataEngine *engine; //!<\brief The engine handling game logic for this `Unit`.
	int tileWidth; //!<\brief Width of a tile at the current moment
	int numTiles; //!<\brief Number of tiles on a side at the current moment
}
} //namespace JagGame 
#define __JGGRIDUNIT__
#endif
