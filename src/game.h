#ifndef GAME_H
#define GAME_H

#include <string>

#include "alien.h"
#include "bullet.h"
#include "controller.h"
#include "render.h"
#include "spaceship.h"

class Game {
    public:
        Game(std::size_t gridWidth, std::size_t gridHeight, Renderer &renderer);
        void Run(Controller const &controller, Renderer &renderer, std::size_t targetFrameDuration);


    private: 
        Spaceship ship;

        int score{0};

        void Update(std::string userInput, bool &running);
        void Render(Renderer &renderer);

};

#endif