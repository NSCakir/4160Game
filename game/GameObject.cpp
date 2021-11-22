#include "game.h"
#include "ImageHandler.h"
#include "GameObject.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

GameObject::GameObject(const char* texture, int x, int y){
    objTexture = ImageHandler::Load(texture);
    xpos = x;
    ypos = y;

}


void GameObject::Render(){

    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);

}



void GameObject::update(Uint32 spin){
    srcRect.h = 142;
    srcRect.w = 160;
    srcRect.x = spin * 160;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = 160;
    destRect.h = 142;

}