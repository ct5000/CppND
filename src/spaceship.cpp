#include "spaceship.h"


/*
Initializes the spaceship. Takes grid width and grid height as input
*/
Spaceship::Spaceship(int gridWidth, int gridHeight) : _gridWidth(gridWidth), _gridHeight(gridHeight)
            , _xPos(( gridWidth) / 2), _yPos((gridHeight) - 2) { }

/*
Upates the position og the spaceship according to the keyInput string
*/
void Spaceship::UpdatePosition(std::string keyInput) {
    if (keyInput == "left") {
        if (_xPos > 1) {
            _xPos--;
        }
    }
    else if(keyInput == "right") {
        if (_xPos < _gridWidth - 2) {
            _xPos++;
        }
    }
}

/*
Initializes a bullet shot from the spaceship
*/
Bullet Spaceship::ShootBullet() {
    return Bullet(_xPos, _yPos - 1, -1, _gridHeight);
}

/*
Checks if the spaceship is hit by a bullet. It takes a reference to a bullet as input
*/
bool Spaceship::Hit(Bullet &bullet) {
    bool xBox = bullet.XPos() >= _xPos - 1 && bullet.XPos() <= _xPos + 1;
    bool yBox = bullet.YPos() >= _yPos - 2 && bullet.YPos() <= _yPos + 2;
    if (xBox && yBox) {
        _lives--;
        return true;
    }
    return false;
}

