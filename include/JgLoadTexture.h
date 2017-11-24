#ifndef __JGLOADTEXTURE__
#include <SDL2/SDL.h>
#include <string>
#include <SDL2/SDL_image.h> //initialize SDL_image before using this method
//!\file Header for `JagGame::loadTexture` functions.
namespace JagGame {
SDL_Texture *loadTexture(std::string&, SDL_Renderer*); //!<\brief Load a texture from resource found at a path.
SDL_Texture *loadTexture(const char*,SDL_Renderer*); //!<\brief C-style string path for `loadTexture`.
}

#define __JGLOADTEXTURE__
#endif
