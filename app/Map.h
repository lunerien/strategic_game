//
// Created by lukasz.kala on 12.07.2023.
//

#ifndef MAP_H_D478FABEAAEF494285D9F92ED56C7CB2
#define MAP_H_D478FABEAAEF494285D9F92ED56C7CB2


#include <string>
#include <vector>
#include "utils/Coordinates.h"

class Map{
public:
    explicit Map(std::vector<std::vector<char>> map);

    bool isObstacle(Coordinates coordinates);
    bool isInMap(Coordinates coordinates);
    Coordinates playerBaseCoordinates;
    Coordinates enemyBaseCoordinates;
private:
    const std::vector<std::vector<char>> map;



};



#endif //MAP_H_D478FABEAAEF494285D9F92ED56C7CB2
