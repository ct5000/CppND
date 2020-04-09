#include "render.h"
#include <iostream>

Renderer::Renderer(const std::size_t screen_width, const std::size_t screen_height, 
                const std::size_t grid_width, const std::size_t grid_height) 
                :_screen_width(screen_width), _screen_height(screen_height),
                _grid_width(grid_width), _grid_height(grid_height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize \n";
        std::cout << "SDL_error: " << SDL_GetError() << std::endl; 
    }
    _window = SDL_CreateWindow("Capstone", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                _screen_width, _screen_height, SDL_WINDOW_SHOWN) ;
    if (_window == nullptr) {
        std::cout << "Window could not be create \n" ;
        std::cout << "SDL_error: " << SDL_GetError() << std::endl;
    }
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (_renderer == nullptr) {
        std::cout << "Renderer could not be create \n" ;
        std::cout << "SDL_error: " << SDL_GetError() << std::endl;
    }
}

Renderer::~Renderer() {
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Renderer::ClearScreen() {
    SDL_SetRenderDrawColor(_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(_renderer);
}

void Renderer::UpdateScreen() {
    SDL_RenderPresent(_renderer);
}

void Renderer::RenderSpaceship(Spaceship &ship) {
    SDL_Rect block;
    block.w = _screen_width / _grid_width;
    block.h = _screen_height / _grid_height;

    SDL_SetRenderDrawColor(_renderer, 0xFF, 0xCC, 0xFF, 0xFF);

    block.x = ship.XPos() * block.w;
    block.y = (ship.YPos() - 1) * block.h;
    SDL_RenderFillRect(_renderer, &block);


    block.x = ship.XPos() * block.w;
    block.y = ship.YPos() * block.h;
    SDL_RenderFillRect(_renderer, &block);

    block.x = (ship.XPos() - 1) * block.w;
    block.y = ship.YPos() * block.h;
    SDL_RenderFillRect(_renderer, &block);

    block.x = (ship.XPos() + 1) * block.w;
    block.y = ship.YPos() * block.h;
    SDL_RenderFillRect(_renderer, &block);

    block.x = (ship.XPos() - 1) * block.w;
    block.y = (ship.YPos() + 1) * block.h;
    SDL_RenderFillRect(_renderer, &block);

    block.x = (ship.XPos() + 1) * block.w;
    block.y = (ship.YPos() + 1) * block.h;
    SDL_RenderFillRect(_renderer, &block);

}

void Renderer::RenderAlien(Alien &alien) {
    SDL_Rect block;
    block.w = _screen_width / _grid_width;
    block.h = _screen_height / _grid_height;

    SDL_SetRenderDrawColor(_renderer, 0xFF, 0xCC, 0xFF, 0xFF);

    for (int i = -1; i <= 1; i++) {
        block.x = (alien.XPos() + i) * block.w;
        block.y = (alien.YPos() - 1) * block.h;
        SDL_RenderFillRect(_renderer, &block);
    }

    for (int i = -2; i <= 2; i++) {
        block.x = (alien.XPos() + i) * block.w;
        block.y = (alien.YPos()) * block.h;
        SDL_RenderFillRect(_renderer, &block);
    }

    block.x = (alien.XPos() - 2) * block.w;
    block.y = (alien.YPos() + 1) * block.h;
    SDL_RenderFillRect(_renderer, &block);

    block.x = (alien.XPos() + 2) * block.w;
    block.y = (alien.YPos() + 1) * block.h;
    SDL_RenderFillRect(_renderer, &block);
    
}
