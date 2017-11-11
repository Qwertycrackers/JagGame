#ifndef __JGLOADSURFACE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
namespace JagGame {
SDL_Surface* LoadSurface(std::string path, Uint32 format);
}

#define __JGLOADSURFACE__
#endif
