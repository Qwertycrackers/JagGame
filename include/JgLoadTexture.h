#ifndef __JGLOADTEXTURE__
#include <SDL2/SDL.h>
#include <string>
#include <SDL2/SDL_image.h> //initialize SDL_image before using this method

namespace JagGame {
SDL_Texture *loadTexture(std::string&, SDL_Renderer*);
SDL_Texture *loadTexture(const char*,SDL_Renderer*);
}

#define __JGLOADTEXTURE__
#endif
