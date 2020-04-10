#include "bullet.h"

/*
Initializes the bullet with an x-coordinate, y-coordinate, the direction it flies and the grid height
*/
Bullet::Bullet(int x, int y, int direction, int gridHeight) 
            : _xPos(x), _yPos(y), _direction(direction), _gridHeight(gridHeight) { }

/*
Updates position of the bullet
*/
void Bullet::UpdatePosition() {
    _yPos += _direction;
}
/*
Checks if the bullet is outside the screen
*/
bool Bullet::OutOfBounds() {
    return _yPos < 0 || _yPos > _gridHeight;
}
