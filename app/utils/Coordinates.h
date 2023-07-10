//
// Created by lukasz on 09.07.23.
//

#ifndef STRATEGIC_GAME_COORDINATES_H
#define STRATEGIC_GAME_COORDINATES_H


class Coordinates {
public:
    Coordinates(int x, int y):x(x),y(y){}
    int getX() const{return x;}
    int getY() const{return y;}
private:
    const int x;
    const int y;
};


#endif //STRATEGIC_GAME_COORDINATES_H
