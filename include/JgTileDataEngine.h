#ifndef __JGTILEDATAENGINE__
#include <SDL2/SDL.h>
#include <vector>
#include "JgCell.h"

namespace JagGame {
class TileDataEngine {
	public:
	TileDataEngine(Cell,int); 
	Cell *getOrigin(); //!<\brief Get pointer to the current `origin` cell. 
	int getZoom(); //!<\ Get the default zoom level. 
	virtual const std::vector<SDL_Texture*> *getTextures(int,int)=0; //!<\brief Get the textures for a tile (x,y) from the origin.
	virtual void setCurrentCell(Cell)=0; //!<\brief Set the cell the selection will be on, relative to current origin.
	virtual void selectCell(Cell,SDL_Event*)=0; //!<\brief Indicate user has selected a cell for interaction.
	virtual void handleKeyInput(SDL_Event*)=0; //!<\brief Pass the engine a key input.
	protected:
	int defzoom; //!<\brief Default zoom level. Set it in child constructor.
	Cell origin; //!<\brief Origin cell. Other cell inputs relative to this. Mutable.
};
} //namespace JagGame

#define __JGTILEDATAENGINE__
#endif
