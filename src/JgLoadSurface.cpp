#include "JgLoadSurface.h"

SDL_Surface* JagGame::LoadSurface(std::string path, Uint32 format) {
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	//if( loadedSurface == NULL ) 
		//throw some exception in here
	SDL_Surface* optimizedSurface = SDL_ConvertSurfaceFormat(loadedSurface,format,0);
	SDL_FreeSurface( loadedSurface );
	return optimizedSurface;
}
		
