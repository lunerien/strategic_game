//
// Created by lukasz on 10.07.23.
//

#ifndef STRATEGIC_GAME_WARUNIT_H
#define STRATEGIC_GAME_WARUNIT_H


#include "Unit.h"

class WarUnit : public Unit {
public:
    
    void move(Coordinates coordinates) override;

    void attack(Coordinates coordinates, Unit &unit) override;

    void takeHit(int attackPower) override;

    char getUnitSign() override;

    int getActualStamina() override;

    int getAttackRange() override;

    int getSpeed() override;

    int getId() override;

    int getPrice() override;

    int getBuildTime() override;

    Coordinates getActualLocation() override;

    ~WarUnit() override = default;
};


#endif //STRATEGIC_GAME_WARUNIT_H
