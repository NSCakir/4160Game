using namespace std;
#include <iostream>
#include <string>

#include <SDL2/SDL.h> 

#include "game.h"

Game *myGame = nullptr;

int main(int argc, const char *argv[]){


  myGame = new Game();

  myGame->init("myGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 1024, 0);

  myGame->handler();

  myGame->cleanGame();



  return 0;
}