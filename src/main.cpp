#include <iostream>
#include "SDL.h"
#include "controller.h"
#include "render.h"



int main() {
    constexpr std::size_t kScreenWidth{640};
    constexpr std::size_t kScreenHeight{640};
    constexpr std::size_t kGridWidth{32};
    constexpr std::size_t kGridHeight{32};
    
    bool running = true;
    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    while(running) {
        controller.HandleInput(running);

    }
    return 0;
}