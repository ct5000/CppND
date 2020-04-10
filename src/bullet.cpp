#include "bullet.h"


Bullet::Bullet(int x, int y, int direction, int gridHeight) 
            : _xPos(x), _yPos(y), _direction(direction), _gridHeight(gridHeight) { }

void Bullet::UpdatePosition() {
    _yPos += _direction;
}

bool Bullet::OutOfBounds() {
    return _yPos < 0 || _yPos > _gridHeight;
}
