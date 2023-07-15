//
// Created by lukasz on 10.07.23.
//

#ifndef STRATEGIC_GAME_WARUNIT_H
#define STRATEGIC_GAME_WARUNIT_H


#include "Unit.h"
#include "BaseUnit.h"

#include <utility>

class WarUnit : public BaseUnit {
public:

    enum class MeleState {
        ProtectingBase,
        GoingToAttack,
    };

    WarUnit(BaseUnit baseUnit, MeleState meleState): BaseUnit(baseUnit) , meleState(meleState)
    {}

    std::string dumpObject() override;

    void update(Map map, std::vector<Unit> units) override;
    ~WarUnit() override = default;


private:
    MeleState meleState;

};


#endif //STRATEGIC_GAME_WARUNIT_H
