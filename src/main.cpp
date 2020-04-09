#include <iostream>
#include "SDL.h"
#include "controller.h"
#include "render.h"
#include "spaceship.h"



int main() {
    constexpr std::size_t kScreenWidth{640};
    constexpr std::size_t kScreenHeight{640};
    constexpr std::size_t kGridWidth{80};
    constexpr std::size_t kGridHeight{40};
    
    bool running = true;
    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Spaceship ship(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    renderer.ClearScreen();
    renderer.RenderSpaceship(ship);
    renderer.UpdateScreen();

    while(running) {
        controller.HandleInput(running);

    }
    return 0;
}