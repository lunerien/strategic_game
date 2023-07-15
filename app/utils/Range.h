//
// Created by lukasz.kala on 13.07.2023.
//

#ifndef RANGE_H_E2E6A2D4414C4F088964842992F159A4
#define RANGE_H_E2E6A2D4414C4F088964842992F159A4


#include "Coordinates.h"
#include "../Map.h"

class Range {
public:
    static Coordinates closestToMove(Coordinates from, Coordinates to, int speed, Map *map, int distanceToOpponent=0);

    static int countDistance(Coordinates from, Coordinates to);

    static Coordinates
    moveSingleField(Coordinates &to, int speed, Map *map, Coordinates &minDistance, int distanceToOpponent);
};


#endif //RANGE_H_E2E6A2D4414C4F088964842992F159A4
