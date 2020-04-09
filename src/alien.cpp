#include "alien.h"


Alien::Alien(int gridWidth, int gridHeight, int row, int column, int totalRows, int totalColumns) 
            : _gridWidth(gridWidth), _gridHeight(gridHeight), _row(row), _column(column),
            _totalRows(totalRows), _totalColumns(totalColumns) {
    _xPos = column * 7 + 3;
    _yPos = row * 5 + 3;
}

void Alien::UpdatePosition() {
    if (_direction == Direction::kRight) {
        if (_xPos > _gridWidth - (_totalRows - _row) - 3) {
            _yPos += 5;
            _direction = Direction::kLeft;
        }
        else {
            _xPos++;
        }
    }
    else {
        if (_xPos < _row * 7 + 3) {
            _yPos += 5;
            _direction = Direction::kRight;
        }
        else {
            _xPos--;
        }
    }
}



