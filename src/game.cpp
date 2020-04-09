#include "game.h"



Game::Game(std::size_t gridWidth, std::size_t gridHeight, Renderer &renderer) 
        : ship(gridWidth, gridHeight) {
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
        Update(userInput, running);
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

void Game::Update(std::string userInput, bool &running) {
    if(userInput == "quit") {
        running = false;
    }
    else {
        ship.UpdatePosition(userInput);
    }
}

void Game::Render(Renderer &renderer) {
    renderer.ClearScreen();
    renderer.RenderSpaceship(ship);
    renderer.UpdateScreen();
}

