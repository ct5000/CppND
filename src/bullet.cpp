#include "bullet.h"


Bullet::Bullet(int x, int y, int direction) : _xPos(x), _yPos(y), _direction(direction) { }

void Bullet::UpdatePosition() {
    _yPos += _direction;
}

