#pragma once
#include "game.h"


class Sprite{

    public:
        Sprite(const char* sheet);
        ~Sprite();


       
        void UpdateSprite();
        void RenderSprite();

        void MoveLeft();
        void MoveRight();
        void MoveUp();
        void MoveDown();

        int getPosX();

        int getPosY();

    private:
 
        SDL_Texture* sprite_sheet;
        SDL_Rect srcRect;
        SDL_Rect destRect;

        int x_pos;
        int y_pos;
        int sprite_x;
        int sprite_y;
        int x;
        

};