#pragma once

#include "game.h"

class ImageHandler {

    public:
        static SDL_Texture* Load(const char* filename);
        static void Create(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);

};