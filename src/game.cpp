#include "game.h"



Game::Game(std::size_t gridWidth, std::size_t gridHeight, Renderer &renderer) 
        : _ship(gridWidth, gridHeight) {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _columns; j++) {
            _aliens.emplace_back(new Alien(gridWidth, gridHeight, i, j, _rows, _columns));
        }
    }
    Render(renderer);
}

void Game::Run(Controller const &controller, Renderer &renderer, std::size_t targetFrameDuration) {
    Uint32 titleTimestamp = SDL_GetTicks();
    Uint32 frameStart;
    Uint32 frameEnd;
    Uint32 frameDuration;
    int frameCount = 0;
    bool running = true;
    while(running) {
        std::string userInput;
        frameStart = SDL_GetTicks();
        userInput = controller.HandleInput();
        Update(userInput, running, frameCount);
        Render(renderer);

        frameEnd = SDL_GetTicks();
        frameCount++;
        frameDuration = frameEnd - frameStart;

        //Opdater så titel bliver ændret med score og framerate

        if (frameDuration < targetFrameDuration) {
            SDL_Delay(targetFrameDuration - frameDuration);
        }
    }
}

void Game::Update(std::string userInput, bool &running, int frameCount) {
    if(userInput == "quit") {
        running = false;
    }
    else if(userInput == "up") {
        _shipBullets.emplace_back(new Bullet(_ship.ShootBullet()));
    }
    else {
        _ship.UpdatePosition(userInput);
    }
    if (frameCount % 5 == 0) {
        for (int i = 0; i < _aliens.size(); i++) {
            (*_aliens[i]).UpdatePosition();
        }
    }
    for (int i = 0; i < _shipBullets.size(); i++) {
        (*_shipBullets[i]).UpdatePosition();
    }
    std::vector<int> alienIndex;
    std::vector<int> bulletIndex;
    for (int i = _aliens.size() - 1; i >= 0; i--) {
        for (int j = _shipBullets.size() - 1; j >= 0; j--) {
            if((*_aliens[i]).Hit(*_shipBullets[j])) {
                alienIndex.emplace_back(i);
                bulletIndex.emplace_back(j);
            }
        }
    }
    for (int i = 0; i < alienIndex.size(); i++) {
        _aliens.erase(_aliens.begin() + alienIndex[i]);
    }
    for (int i = 0; i < bulletIndex.size(); i++) {
        _shipBullets.erase(_shipBullets.begin() + bulletIndex[i]);
    }
}

void Game::Render(Renderer &renderer) {
    renderer.ClearScreen();
    renderer.RenderSpaceship(_ship);
    
    for (int i = 0; i < _aliens.size(); i++) {
        renderer.RenderAlien(*_aliens[i]);
    }
    for (int i = 0; i < _shipBullets.size(); i++) {
        renderer.RenderBullet(*_shipBullets[i]);
    }
    renderer.UpdateScreen();
}

