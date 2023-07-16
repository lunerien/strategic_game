//
// Created by lukasz.kala on 13.07.2023.
//

#ifndef RANGE_H_E2E6A2D4414C4F088964842992F159A4
#define RANGE_H_E2E6A2D4414C4F088964842992F159A4


#include "Coordinates.h"
#include "../Map.h"
#include "../units/Unit.h"
#include "../units/BaseUnit.h"

class Range {
public:
    static Coordinates closestToMove(Coordinates from, Coordinates to, int speed, Map *map, int distanceToOpponent=0 ,
                                     const std::vector <Unit*>& enemyUnits = {});

    static int countDistance(Coordinates from, Coordinates to);

    static Coordinates
    moveSingleField(Coordinates &to, int movePoints, Map *map, Coordinates &minDistance, int attackRange,
                    const std::vector <Unit*>& enemyUnits = {});

    static bool isEnemyInPosition(Coordinates position, std::vector <Unit*> enemyUnits);
    static Unit* getClosestEnemy(Coordinates from, std::vector <Unit*> enemyUnits);
    static Coordinates getClosestMine(Coordinates from, Map& map);
    static bool isMineInPosition(Coordinates position, Map& map);
};


#endif //RANGE_H_E2E6A2D4414C4F088964842992F159A4
