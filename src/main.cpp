#include <iostream>
#include "SDL.h"
#include "controller.h"
#include "render.h"
#include "game.h"



int main() {
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kFrameDuration{1000 / 60};
    constexpr std::size_t kScreenWidth{640};
    constexpr std::size_t kScreenHeight{640};
    constexpr std::size_t kGridWidth{80};
    constexpr std::size_t kGridHeight{40};
    
    bool running = true;
    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth,kGridHeight, renderer);
    game.Run(controller, renderer, kFrameDuration);
    
    return 0;
}