//
// Created by lukasz.kala on 15.07.2023.
//

#ifndef BASEBUILDINGUNIT_H_7F816E1BA28E4336A7CF17298E3F9E27
#define BASEBUILDINGUNIT_H_7F816E1BA28E4336A7CF17298E3F9E27


#include <utility>

#include "BaseUnit.h"

class BaseBuildingUnit : public BaseUnit{
public:
    enum class BaseBuildingState {
        CreatingUnit,
        Idle
    };

    BaseBuildingUnit(BaseUnit baseUnit, BaseBuildingState baseBuildingState, UnitType actualUnitBeingCreatedType, int timeLeftToCreateUnit ) :
    BaseUnit(std::move(baseUnit)), baseBuildingState(baseBuildingState), actualUnitBeingCreatedType(std::move(actualUnitBeingCreatedType)),
    timeLeftToCreateUnit(timeLeftToCreateUnit){}

    void update(Map map, std::vector<Unit> units) override;

    std::string dumpObject() override;
private:
    BaseBuildingState baseBuildingState;
    UnitType actualUnitBeingCreatedType;
    int timeLeftToCreateUnit;
};


#endif //BASEBUILDINGUNIT_H_7F816E1BA28E4336A7CF17298E3F9E27
