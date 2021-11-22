#pragma once

#include "game.h"

class Map{


    public:
        Map();
        ~Map();

        
        void DrawMap();


    private:

    SDL_Rect src, dest;
    SDL_Texture* blue;
    SDL_Texture* brown;
    SDL_Texture* red;
    

    int tileSet[32][32];
};