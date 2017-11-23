#include "JgLoadTexture.h"
SDL_Texture *JagGame::loadTexture(std::string &path, SDL_Renderer *r) {
	return JagGame::loadTexture(path.c_str(), r);
}

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
