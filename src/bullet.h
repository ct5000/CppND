#ifndef BULLET_H
#define BULLET_H

class Bullet {
    public:
        Bullet(int x, int y, int direction, int gridHeight);
        void UpdatePosition();
        int XPos() {return _xPos;}
        int YPos() {return _yPos;}
        bool OutOfBounds();

    private:
        int _direction;
        int _xPos;
        int _yPos;
        int _gridHeight;

};



#endif