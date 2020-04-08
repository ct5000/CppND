#include <iostream>
#include "SDL.h"

#include "controller.h"



void Controller::HandleInput(bool &running) const {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            running = false;
        }
        else if(e.type == SDL_KEYDOWN) {
            switch(e.key.keysym.sym) {
                case SDLK_UP:
                    std::cout << "Up tast \n";
                    break;
                case SDLK_LEFT:
                    std::cout << "Venstre tast \n";
                    break;
                case SDLK_RIGHT:
                    std::cout << "Højre tast \n";
                    break;
            }
        }
    }
}

