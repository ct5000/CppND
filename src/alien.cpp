#include "alien.h"



Alien::Alien(int gridWidth, int gridHeight, int row, int column, int totalRows, int totalColumns) 
            : _gridWidth(gridWidth), _gridHeight(gridHeight), _row(row), _column(column),
            _totalRows(totalRows), _totalColumns(totalColumns) {
    _xPos = column * 7 + 3;
    _yPos = row * 4 + 3;
}

void Alien::UpdatePosition() {
    if (_direction == Direction::kRight) {
        if (_xPos > _gridWidth - 7 * (_totalColumns - _column - 1) -  + 4) {
            _yPos += 2;
            _direction = Direction::kLeft;
        }
        else {
            _xPos++;
        }
    }
    else {
        if (_xPos < _column * 7 + 3) {
            _yPos += 2;
            _direction = Direction::kRight;
        }
        else {
            _xPos--;
        }
    }
}

bool Alien::Hit(Bullet &bullet) {
    bool xBox = bullet.XPos() >= _xPos - 1 && bullet.XPos() <= _xPos + 1;
    bool yBox = bullet.YPos() >= _yPos - 2 && bullet.YPos() <= _yPos + 2;
    return xBox && yBox;
}

Bullet Alien::ShootBullet() {
    return Bullet(_xPos, _yPos + 1, 1, _gridHeight);
}


