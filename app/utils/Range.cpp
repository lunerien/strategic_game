//
// Created by lukasz.kala on 13.07.2023.
//

#include "Range.h"
#include <climits>
#include <algorithm>

Coordinates Range::closestToMove(Coordinates from, Coordinates to, int speed, Map *map, int distanceToOpponent,
                                 const std::vector<Unit *> &enemyUnits) {
    Coordinates minDistance = from;

    for (int movePoints = speed; movePoints >= 0; --movePoints) {
        minDistance = moveSingleField(to, movePoints, map, minDistance, distanceToOpponent, enemyUnits);
    }

    return minDistance;
}

Coordinates Range::moveSingleField(Coordinates &to, int movePoints, Map *map, Coordinates &minDistance, int attackRange,
                                   const std::vector<Unit *> &enemyUnits) {
    int minDistanceValue = INT_MAX;
    int actDistanceValue;
    Coordinates actMinDistance = minDistance;
    for (int x = actMinDistance.getX() - 1; x <= actMinDistance.getX() + 1; ++x) {
        for (int y = actMinDistance.getY() - 1; y <= actMinDistance.getY() + 1; ++y) {
            if (!map->isInMap(Coordinates(x, y)) || (x == minDistance.getX() && y == minDistance.getY())) {
                continue;
            }
            actDistanceValue = countDistance(Coordinates(x, y), to) - attackRange;
            actDistanceValue = actDistanceValue < 0 ? 0 : actDistanceValue;

            if (actDistanceValue < minDistanceValue &&
                ((!map->isObstacle(Coordinates(x, y)) && (!isEnemyInPosition(Coordinates(x, y), enemyUnits) ||
                  actDistanceValue > 0)) || movePoints > 1)) {
                minDistanceValue = actDistanceValue;
                minDistance = Coordinates(x, y);
            }

        }
    }
    return minDistance;
}

int Range::countDistance(Coordinates from, Coordinates to) {
    return abs(from.getX() - to.getX()) + abs(from.getY() - to.getY());
}

bool Range::isEnemyInPosition(Coordinates position, std::vector<Unit *> enemyUnits) {
    for (auto &enemyUnit: enemyUnits) {
        if (enemyUnit->getActualLocation() == position) {
            return true;
        }
    }
    return false;
}

Unit *Range::getClosestEnemy(Coordinates from, std::vector<Unit *> enemyUnits) {
    int minDistance = INT_MAX;
    Unit *closestEnemy = nullptr;
    for (auto &enemyUnit: enemyUnits) {
        int actDistance = countDistance(from, enemyUnit->getActualLocation());
        if (actDistance < minDistance) {
            minDistance = actDistance;
            closestEnemy = enemyUnit;
        }
    }
    return closestEnemy;
}

Coordinates Range::getClosestMine(Coordinates from, Map &map) {
    int minDistance = INT_MAX;
    Coordinates closestMine = from;
    for (auto &mine: map.getMines()) {
        int actDistance = countDistance(from, mine);
        if (actDistance < minDistance) {
            minDistance = actDistance;
            closestMine = mine;
        }
    }
    return closestMine;
}

bool Range::isMineInPosition(Coordinates position, Map &map) {
    std::any_of(map.getMines().begin(), map.getMines().end(), [&](Coordinates mine) {
        return mine == position;
    });
    return false;
}
