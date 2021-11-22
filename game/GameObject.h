#pragma once
#include "game.h"

class GameObject{

    public:
        GameObject(const char* texture, int x, int y);
        ~GameObject();

        void Render();


        void update(Uint32 spin);


    private:
        int xpos;
        int ypos;

        SDL_Texture* objTexture;
        SDL_Rect srcRect, destRect;
        

};