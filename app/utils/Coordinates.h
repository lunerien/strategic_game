//
// Created by lukasz on 09.07.23.
//

#ifndef STRATEGIC_GAME_COORDINATES_H
#define STRATEGIC_GAME_COORDINATES_H


class Coordinates {
public:
    Coordinates():x(0),y(0){}
    Coordinates( int x,   int y):x(x),y(y){}
    int getX() const{return x;}
    int getY() const{return y;}
    bool operator==(const Coordinates& rhs) const{
        return x == rhs.x &&
               y == rhs.y;
    }
private:
     int x;
     int y;
};


#endif //STRATEGIC_GAME_COORDINATES_H
