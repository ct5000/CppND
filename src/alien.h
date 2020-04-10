#ifndef ALIEN_H
#define ALIEN_H

#include "bullet.h"



class Alien {
    public:
        enum class Direction { kLeft, kRight};

        Alien(int gridWidth, int gridHeight, int row, int column, int totalRows, int totalColumns);
        void UpdatePosition();
        int YPos() { return _yPos;}
        int XPos() { return _xPos;}
        bool Hit(Bullet &bullet);

    private:
        int _xPos;
        int _yPos;
        int _row;
        int _column;
        int _totalRows;
        int _totalColumns;
        int _gridWidth;
        int _gridHeight;
        Direction _direction = Direction::kRight;
};


#endif