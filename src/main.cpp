#include <iostream>
#include "SDL.h"
#include "controller.h"

//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;

int main() {
    Controller controller;
    while(true) {
        controller.HandleInput();
        
    }
    return 0;
}