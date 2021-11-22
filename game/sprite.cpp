#include "sprite.h"
#include "ImageHandler.h"



Sprite::Sprite(const char* sheet){

    sprite_sheet= ImageHandler::Load(sheet);
    x_pos = 512;
    y_pos = 512;
    sprite_x = 0;
    sprite_y = 0;
    x = 0;
    
    
}   


void Sprite::UpdateSprite(){
    if(x == 0){
        srcRect.h = 338;
        srcRect.w = 305;
        srcRect.x = sprite_x;
        srcRect.y = sprite_y;

        destRect.x = x_pos;
        destRect.y = y_pos;
        destRect.w = 305;
        destRect.h = 338;

        
    }
    if(x == 1){
        srcRect.h = 302;
        srcRect.w = 345;
        srcRect.x = sprite_x;
        srcRect.y = sprite_y;

        destRect.x = x_pos;
        destRect.y = y_pos;
        destRect.w = 345;
        destRect.h = 302;

        
    }
    if(x == 2){
        srcRect.h = 332;
        srcRect.w = 233;
        srcRect.x = sprite_x;
        srcRect.y = sprite_y;

        destRect.x = x_pos;
        destRect.y = y_pos;
        destRect.w = 233;
        destRect.h = 332;

        
    }
    if(x == 3){

        srcRect.h = 305;
        srcRect.w = 300;
        srcRect.x = sprite_x;
        srcRect.y = sprite_y;

        destRect.x = x_pos;
        destRect.y = y_pos;
        destRect.w = 300;
        destRect.h = 305;
        
    }
}

void Sprite::RenderSprite(){
  
    
    SDL_RenderCopy(Game::renderer, sprite_sheet, &srcRect, &destRect);
}

void Sprite::MoveLeft(){

    if(x_pos == 0){
        return;
    }
    if(x == 0){
        sprite_x += 330;
        x++;
    }else if(x == 1){
        sprite_x += 370;
        x++;
    }else if(x == 2){
        sprite_x += 320;
        x++;
    }else if(x == 3){
        sprite_x = 0;
        x = 0;
    }
    
    x_pos -= 20;
}
void Sprite::MoveRight(){

    if(x_pos >= 700){
        return;
    }
    if(x == 0){
        sprite_x += 330;
        x++;
    }else if(x == 1){
        sprite_x += 370;
        x++;
    }else if(x == 2){
        sprite_x += 320;
        x++;
    }else if(x == 3){
        sprite_x = 0;
        x  = 0;
    }
    
    x_pos += 20;
}
void Sprite::MoveUp(){

    if(y_pos == 0){
        return;
    }
        if(x == 0){
        sprite_x += 330;
        x++;
    }else if(x == 1){
        sprite_x += 370;
        x++;
    }else if(x == 2){
        sprite_x += 320;
        x++;
    }else if(x == 3){
        sprite_x = 0;
        x  = 0;
    }

    y_pos -= 20;
}
void Sprite::MoveDown(){
    if(y_pos >= 700){
        return;
    }
        if(x == 0){
        sprite_x += 330;
        x++;
    }else if(x == 1){
        sprite_x += 370;
        x++;
    }else if(x == 2){
        sprite_x += 320;
        x++;
    }else if(x == 3){
        sprite_x = 0;
        x  = 0;
    }

    y_pos += 20;
}


int Sprite::getPosX(){
    return x_pos;
}

int Sprite::getPosY(){
    return y_pos;

}