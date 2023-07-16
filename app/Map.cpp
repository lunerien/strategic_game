//
// Created by lukasz.kala on 12.07.2023.
//

#include <stdexcept>
#include "Map.h"


bool Map::isObstacle(Coordinates coordinates) {
    if(coordinates.getX() < 0 || coordinates.getX() >= static_cast<int>(map.size()) ||
       coordinates.getY() < 0 || coordinates.getY() >= static_cast<int>(map[0].size())) {
        throw std::invalid_argument("Coordinates out of map: x: " + std::to_string(coordinates.getX()) + " y: " +
                                    std::to_string(coordinates.getY()));
    }

    if (coordinates == playerBaseCoordinates || coordinates == enemyBaseCoordinates ||
        map[coordinates.getX()][coordinates.getY()] != '0')
        return true;
    return false;
}



Map::Map(const std::vector<std::vector<char>> map) : playerBaseCoordinates(0, 0), enemyBaseCoordinates(0, 0),
                                                      map(map) {
    int x = 0;
    for (auto &row: map) {
        int y = 0;
        for (auto &sign: row) {
            if (sign == '1') {
                this->playerBaseCoordinates = {x, y};
            } else if (sign == '2') {
                this->enemyBaseCoordinates = {x, y};
            } else if (sign == '6') {
                this->mines.emplace_back(x, y);
            }
            y++;
        }
        x++;
    }
}

bool Map::isInMap(Coordinates coordinates) {
    if (coordinates.getX() >= 0 && coordinates.getX() < static_cast<int>(map.size()) &&
        coordinates.getY() >= 0 && coordinates.getY() < static_cast<int>(map[0].size()))
    {
        return true;
    }
    return false;
}

std::vector<Coordinates> Map::getMines() {
    return mines;
}
