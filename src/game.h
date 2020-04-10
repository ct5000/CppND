#ifndef GAME_H
#define GAME_H

#include <string>

#include "alien.h"
#include "bullet.h"
#include "controller.h"
#include "render.h"
#include "spaceship.h"
#include <vector>
#include <memory>

class Game {
    public:
        Game(std::size_t gridWidth, std::size_t gridHeight, Renderer &renderer);
        void Run(Controller const &controller, Renderer &renderer, std::size_t targetFrameDuration);
        void CheckGameEnd(bool &running);


    private: 
        Spaceship _ship;
        std::vector<std::unique_ptr<Alien>> _aliens;
        std::vector<std::unique_ptr<Bullet>> _shipBullets;
        std::vector<std::unique_ptr<Bullet>> _alienBullets;

        int _score{0};
        int _rows{4};
        int _columns{6};

        void Update(std::string userInput, bool &running, int frameCount);
        void Render(Renderer &renderer);

};

#endif