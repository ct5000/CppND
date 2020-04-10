#include "game.h"
#include <cstdlib>
#include <iostream>

/*
Initializes the game with the grid width, grid height and the renderer. Also initializez
the spaceship and the aliens
*/
Game::Game(std::size_t gridWidth, std::size_t gridHeight, Renderer &renderer) 
        : _ship(gridWidth, gridHeight) {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _columns; j++) {
            _aliens.emplace_back(new Alien(gridWidth, gridHeight, i, j, _rows, _columns));
        }
    }
    Render(renderer);
}

/*
Runs the game. Takes a controller, a renderer, and the target frame rate as input
*/
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

        CheckGameEnd(running);

        frameEnd = SDL_GetTicks();
        frameCount++;
        frameDuration = frameEnd - frameStart;

        //Opdater så titel bliver ændret med score, liv og framerate
        if (frameEnd - titleTimestamp >= 500) {
            renderer.UpdateWindowTitle(_score, _ship.Lives(), frameCount);
            frameCount = 0;
            titleTimestamp = frameEnd;
        }

        if (frameDuration < targetFrameDuration) {
            SDL_Delay(targetFrameDuration - frameDuration);
        }
    }
}

/*
Updates the game for positions and if a new bullet has been fired from either spaceship or alien.
It takes a string as user input, a boolen for running and the frameCout
*/
void Game::Update(std::string userInput, bool &running, int frameCount) {
    if(userInput == "quit") {
        running = false;
    }
    else if(userInput == "up") {
        if (_shipBullets.size() < 6) {
            _shipBullets.emplace_back(new Bullet(_ship.ShootBullet()));
        }
    }
    else {
        _ship.UpdatePosition(userInput);
    }
    // Updates the position of the aliens every 5 frames
    if (frameCount % 5 == 0) {
        for (int i = 0; i < _aliens.size(); i++) {
            (*_aliens[i]).UpdatePosition();
            if (rand() % 100 == 0) {
                _alienBullets.emplace_back(new Bullet((*_aliens[i]).ShootBullet()));
            }
        }
    }
    //Updates position for the bullets shot from the spaceship and checks if inbound
    std::vector<int> bulletIndexBoundsShip;
    for (int i = _shipBullets.size() - 1; i >= 0; i--) {
        (*_shipBullets[i]).UpdatePosition();
        if ((*_shipBullets[i]).OutOfBounds()) {
            bulletIndexBoundsShip.emplace_back(i);
        }
    }
    for (int i = 0; i < bulletIndexBoundsShip.size(); i++) {
        _shipBullets.erase(_shipBullets.begin() + bulletIndexBoundsShip[i]);
    }
    //Updates position for the bullets shot from the aliens and checks if inbound
    std::vector<int> bulletIndexBoundsAlien;
    for (int i = _alienBullets.size() - 1; i >= 0; i--) {
        (*_alienBullets[i]).UpdatePosition();
        if ((*_alienBullets[i]).OutOfBounds()) {
            bulletIndexBoundsAlien.emplace_back(i);
        }
    }
    for (int i = 0; i < bulletIndexBoundsAlien.size(); i++) {
        _alienBullets.erase(_alienBullets.begin() + bulletIndexBoundsAlien[i]);
    }
    //Checks if bullets hit aliens and deletes both aliens and bullets
    std::vector<int> alienIndex;
    std::vector<int> bulletIndexAlien;
    for (int i = _aliens.size() - 1; i >= 0; i--) {
        for (int j = _shipBullets.size() - 1; j >= 0; j--) {
            if((*_aliens[i]).Hit(*_shipBullets[j])) {
                alienIndex.emplace_back(i);
                bulletIndexAlien.emplace_back(j);
                _score++;
                break;
            }
        }
    }
    for (int i = 0; i < alienIndex.size(); i++) {
        _aliens.erase(_aliens.begin() + alienIndex[i]);
    }
    for (int i = 0; i < bulletIndexAlien.size(); i++) {
        _shipBullets.erase(_shipBullets.begin() + bulletIndexAlien[i]);
    }
    //Check if the bullets hits the spaceship and deletes bullet. 
    std::vector<int> bulletIndexShip;
    for (int j = _alienBullets.size() - 1; j >= 0; j--) {
        if(_ship.Hit(*_alienBullets[j])) {
            bulletIndexShip.emplace_back(j);
        }
    }
    for (int i = 0; i < bulletIndexShip.size(); i++) {
        _alienBullets.erase(_alienBullets.begin() + bulletIndexShip[i]);
    }
}

/*
Renders all the objects on the screen. Takes a renderer as input
*/
void Game::Render(Renderer &renderer) {
    renderer.ClearScreen();
    renderer.RenderSpaceship(_ship);
    for (int i = 0; i < _aliens.size(); i++) {
        renderer.RenderAlien(*_aliens[i]);
    }
    for (int i = 0; i < _shipBullets.size(); i++) {
        renderer.RenderBullet(*_shipBullets[i]);
    }
    for (int i = 0; i < _alienBullets.size(); i++) {
        renderer.RenderBullet(*_alienBullets[i]);
    }
    renderer.UpdateScreen();
}

/*
Checks if the game end conditions has been met. Takes a reference to a boolean. 
*/
void Game::CheckGameEnd(bool &running) {
    if (_aliens.size() <= 0) {
        running = false;
        std::cout << "No more aliens you win! Score: " << _score << std::endl;
    }
    if (_ship.Lives() < 0) {
        running = false;
        std::cout << "No more lives you lose. Score: " << _score << std::endl;
    }
}