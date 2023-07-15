//
// Created by lukasz.kala on 13.07.2023.
//

#include "Range.h"
#include <climits>

Coordinates Range::closestToMove(Coordinates from, Coordinates to, int speed, Map *map, int distanceToOpponent) {
    Coordinates minDistance = from;

    for (int i = 0; i < speed; ++i) {
        minDistance = moveSingleField(to, speed, map, minDistance, distanceToOpponent);
    }

    return minDistance;
}

Coordinates Range::moveSingleField(Coordinates &to, int speed, Map *map, Coordinates &minDistance, int distanceToOpponent) {
    int minDistanceValue = INT_MAX;
    int actDistanceValue;
    Coordinates actMinDistance = minDistance;
    for (int x = actMinDistance.getX() - 1 ; x <= actMinDistance.getX() + 1; ++x) {
        for (int y = actMinDistance.getY() - 1; y <= actMinDistance.getY() + 1; ++y) {
            if(!map->isInMap(Coordinates(x,y)) || (x == minDistance.getX() && y == minDistance.getY()))
            {
                continue;
            }
            actDistanceValue = countDistance(Coordinates(x,y), to);
            if(actDistanceValue <= distanceToOpponent)
            {
                return {x,y};
            }
            if (actDistanceValue < minDistanceValue && (!map->isObstacle(Coordinates(x,y)) || speed > 1) ) {
                minDistanceValue = actDistanceValue;
                minDistance = Coordinates(x,y);
            }

        }
    }
    return minDistance;
}

int Range::countDistance(Coordinates from, Coordinates to) {
    return abs(from.getX() - to.getX()) + abs(from.getY() - to.getY());
}
