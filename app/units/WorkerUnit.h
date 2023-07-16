//
// Created by lukasz.kala on 13.07.2023.
//

#ifndef WORKERUNIT_H_C82A6D645515446E93A03397A620F9C9
#define WORKERUNIT_H_C82A6D645515446E93A03397A620F9C9


#include "../Map.h"
#include "BaseUnit.h"
#include <utility>

class WorkerUnit : public BaseUnit {
public:
    enum class WorkerState {
        GoingToMine,
        InMine,
        FightingMine,
        FightingBase
    };

    WorkerUnit(BaseUnit baseUnit, WorkerState workerState) : BaseUnit(baseUnit), workerState(workerState) {}

    void update() override;


    std::string dumpObjectAdditionalInfo() override;

    int getAttackPower(Unit *unit) override;

private:
    WorkerState workerState;
};


#endif //WORKERUNIT_H_C82A6D645515446E93A03397A620F9C9
