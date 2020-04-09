#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <string>


class Spaceship {
    public:
        Spaceship(int gridWidth, int gridHeight);
        void UpdatePosition(std::string keyInput);
        int XPos() {return _xPos;}
        int YPos() {return _yPos;}

    private:
        int _xPos;
        int _yPos;
        int _gridWidth;
        int _gridHeight;
};



#endif