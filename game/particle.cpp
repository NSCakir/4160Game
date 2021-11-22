#include "particle.h"
#include "game.h"
#include "blip.h"
#include <cstdlib>
#include "ImageHandler.h"
#include <ctime>



Particle::Particle(){

    parType = ImageHandler::Load("rain.png");

    
}

void Particle::rend(int x,  int y){
    SDL_Rect source;
    SDL_Rect dest;

    source.x = 0;
    source.y = 0;
    source.h = 14;
    source.w = 32;

    dest.x = x;
    dest.y = y;
    dest.w = 32;
    dest.h = 14;

    
    ImageHandler::Create(parType, source, dest);


}
