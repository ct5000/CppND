#include <iostream>
#include "SDL.h"

#include "controller.h"



std::string Controller::HandleInput() const {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            return "quit";
        }
        else if(e.type == SDL_KEYDOWN) {
            switch(e.key.keysym.sym) {
                case SDLK_UP:
                    return "up";
                    break;
                case SDLK_LEFT:
                    return "left";
                    break;
                case SDLK_RIGHT:
                    return "right";
                    break;
                default:
                    return "";
            }
        }
    }
    return "";
}

