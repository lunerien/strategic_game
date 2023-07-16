//
// Created by lukasz.kala on 15.07.2023.
//

#ifndef BASEBUILDINGUNIT_H_7F816E1BA28E4336A7CF17298E3F9E27
#define BASEBUILDINGUNIT_H_7F816E1BA28E4336A7CF17298E3F9E27


#include <utility>

#include "BaseUnit.h"
#include "UnitFactory.h"

class BaseBuildingUnit : public BaseUnit {
public:
    enum class BaseBuildingState {
        CreatingUnit,
        Idle
    };

    BaseBuildingUnit(BaseUnit baseUnit, BaseBuildingState baseBuildingState, UnitType actualUnitBeingCreatedType,
                     int timeLeftToCreateUnit, UnitFactory &unitFactory) :
            BaseUnit(std::move(baseUnit)), unitFactory(unitFactory), baseBuildingState(baseBuildingState),
            actualUnitBeingCreatedType(std::move(actualUnitBeingCreatedType)),
            timeLeftToCreateUnit(timeLeftToCreateUnit) {}

    void update() override;

    std::string dumpObject() override;

    std::string dumpObjectAction() override;

    std::string dumpObjectAdditionalInfo() override;

private:
    UnitFactory &unitFactory;
    BaseBuildingState baseBuildingState;
    UnitType actualUnitBeingCreatedType;
    int timeLeftToCreateUnit;
};


#endif //BASEBUILDINGUNIT_H_7F816E1BA28E4336A7CF17298E3F9E27
