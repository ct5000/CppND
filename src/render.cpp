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


/*
SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;
    
    else {
        
        else {
            screenSurface = SDL_GetWindowSurface(window) ;
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(window);
            SDL_Delay(2000);
        }
    }
    
*/