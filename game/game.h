#ifndef game_h
#define game_h

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_rect.h>

#include <stdio.h>

class Game {

    public:
        Game();
        ~Game();
        void init(const char* name, int x_pos, int y_pos, int w, int h, int flag);
        void handler();
        void updateGame(Uint32 spin);
        void renderGame();
        void cleanGame();
        void particleGen();



        bool running() { return run; }

        void keyPress(const Uint8* keyState);

        static SDL_Renderer *renderer;

        

    private:
        bool run;
        SDL_Window *window;
       
        

};

#endif