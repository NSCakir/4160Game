#include "game.h"
#include "ImageHandler.h"
#include "sprite.h"
#include "Map.h"

#include "GameObject.h"
#include <cstdlib>
#include <ctime>
#include "particle.h"



Map* game_map;
Sprite *player;
GameObject* one;
GameObject* two;
GameObject* three;

SDL_Renderer* Game::renderer = nullptr;
Game::Game(){}
Game::~Game(){}

//SDL_Rect camera = {512, 512, 512, 512};




void Game::init(const char *name, int x_pos, int y_pos, int w, int h, int flag){

    
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) { 

        window = SDL_CreateWindow(name, x_pos, y_pos, w, h, flag);
        renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
        
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        run = true;

    } else{
        run = false;
    }

    game_map = new Map();


    srand(time(0));
    
    //set up particles
    
    
  

    player = new Sprite("spidey.png");

    one = new GameObject("coin1.png", (rand() % 750), (rand() % 750));
    two = new GameObject("coin1.png", (rand() % 750), (rand() % 750));
    three = new GameObject("coin1.png", (rand() % 750), (rand() % 750));
      
}
void Game::handler(){

    while (this->running()){
      Uint32 ticks = SDL_GetTicks();
      Uint32 seconds = ticks / 100;
      Uint32 spin = seconds % 6;
    
    SDL_Event event;
    const Uint8* keyState = SDL_GetKeyboardState(nullptr);

    while(SDL_PollEvent(&event)){

      if(event.type == SDL_QUIT){

        run = false;
        break;
      }

      this->keyPress(keyState);
    }


    this->updateGame(spin);
    this->renderGame();
  }
}


void Game::updateGame(Uint32 spin){
    
    player->UpdateSprite();
    one->update(spin);
    two->update(spin);
    three->update(spin);


}


void Game::renderGame(){
    SDL_RenderClear(renderer);
    
    
    game_map->DrawMap();
  
    player->RenderSprite();
    one->Render();
    two->Render();
    three->Render();

    //particleGen();
    
    SDL_RenderPresent(renderer);

}

void Game::particleGen(){
    //Particle Generator
    Particle *particle;
    particle = new Particle();

    for(int i = 0; i <32; i++){
      for(int j = 0; j < 32; j++){
         particle->rend(i*32, j*32);
         j++;
      }
      SDL_RenderPresent(renderer);
    }
}

void Game::cleanGame(){

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

}

void Game::keyPress(const Uint8* keyState){

    if(keyState[SDL_SCANCODE_RIGHT]){
        player->MoveRight();
      }
      if(keyState[SDL_SCANCODE_LEFT]){
        player->MoveLeft();
      }
      if(keyState[SDL_SCANCODE_UP]){
        player->MoveUp();
      }      
      if(keyState[SDL_SCANCODE_DOWN]){
        player->MoveDown();
      }
      if(keyState[SDL_SCANCODE_D]){
        player->MoveRight();
      }
      if(keyState[SDL_SCANCODE_A]){
        player->MoveLeft();
      }
      if(keyState[SDL_SCANCODE_W]){
        player->MoveUp();
      }      
      if(keyState[SDL_SCANCODE_S]){
        player->MoveDown();
      }
      return;
}

