#include "JgLoadTexture.h"
/*! Load an `SDL_Texture` from an asset found at a particular path.
	\param path The string representing the path to the asset.
	\param r a pointer to the rendering context to use.
	\returns a pointer to the loaded texture. */
SDL_Texture *JagGame::loadTexture(std::string &path, SDL_Renderer *r) {
	return JagGame::loadTexture(path.c_str(), r);
}
/*! \param path a C-style string representing the path to the asset.
	\param r the rendering context for the texture.
	\returns the loaded `SDL_Texture`. */
SDL_Texture *JagGame::loadTexture(const char* path, SDL_Renderer *r) {
	SDL_Texture *texture; //the texture to be returned
	SDL_Surface *surface; //the surface which will hold the intermediate data
	surface = IMG_Load(path); //get the image from hard memory, as an SDL_Surface*
	if(surface == NULL) //check if there was a problem
		throw std::string("Couldn't load image at path ") + path;
	texture = SDL_CreateTextureFromSurface(r, surface); //create the texture in this rendering context
	if(texture == NULL)
		throw std::string("Couldn't create texture from image at path ") + path;
	SDL_FreeSurface(surface);
	return texture;
}
