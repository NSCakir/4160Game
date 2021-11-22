#pragma once

#include "game.h"

#include "particle.h"

const int NUM_PARTICLES = 20;

class Blip{

    public:
        Blip();

        void inputs();

        void move();

        void present();

        void show_blip();


    private:
        int offX;
        int offY;

        int velocity_x;
        int velocity_y;

        Particle *particles [NUM_PARTICLES];
};
