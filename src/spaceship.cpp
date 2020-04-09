#include "spaceship.h"



Spaceship::Spaceship(int screenWidth, int screenHeight, int gridWidth, int gridHeight) {
    _xPos = ( gridWidth) / 2;
    _yPos = (gridHeight) - 2;
}

void Spaceship::UpdatePosition(std::string keyInput) {
    if (keyInput == "left") {
        _xPos--;
    }
    else if(keyInput == "right") {
        _xPos++;
    }
}


