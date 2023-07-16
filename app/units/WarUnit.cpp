//
// Created by lukasz on 10.07.23.
//

#include <vector>
#include "WarUnit.h"


void WarUnit::update() {

}

std::string WarUnit::dumpObjectAdditionalInfo() {
    return BaseUnit::dumpObjectAdditionalInfo() + " " + std::to_string(static_cast<int>(meleState));
}
