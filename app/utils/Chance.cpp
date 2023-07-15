//
// Created by lukasz.kala on 12.07.2023.
//

#include "Chance.h"
#include <random>

int Chance::draw(unsigned int chance) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,99);
    return dist6(rng) <= chance;
}
