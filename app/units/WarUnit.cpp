//
// Created by lukasz on 10.07.23.
//

#include <vector>
#include "WarUnit.h"
#include "../utils/Range.h"


void WarUnit::update() {
    switch (meleState) {
        case MeleState::ProtectingBase:
            break;
        case MeleState::GoingToAttack:
            auto *nearestEnemy = Range::getClosestEnemy(BaseUnit::getActualLocation(), unitsEnemy);
            if(nearestEnemy == nullptr)
            {
                if(Range::countDistance(BaseUnit::getActualLocation(), map.enemyBaseCoordinates) > BaseUnit::getAttackRange())
                {
                    BaseUnit::attack(*Range::getClosestEnemy(map.enemyBaseCoordinates, unitsEnemy));
                }
                BaseUnit::move(map.enemyBaseCoordinates);
            }

            break;
    }
}

std::string WarUnit::dumpObjectAdditionalInfo() {
    return BaseUnit::dumpObjectAdditionalInfo() + " " + std::to_string(static_cast<int>(meleState));
}
