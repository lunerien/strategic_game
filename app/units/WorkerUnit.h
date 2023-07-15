//
// Created by lukasz.kala on 13.07.2023.
//

#ifndef WORKERUNIT_H_C82A6D645515446E93A03397A620F9C9
#define WORKERUNIT_H_C82A6D645515446E93A03397A620F9C9


#include "../Map.h"
#include "BaseUnit.h"
#include <utility>

class WorkerUnit : public BaseUnit {
    enum class WorkerState {
        GoingToMine,
        InMine,
        FightingMine,
        FightingBase
    };

    WorkerUnit(BaseUnit baseUnit, WorkerState workerState) : BaseUnit(baseUnit), workerState(workerState) {}

    void update(Map map, std::vector<Unit> units) override;

public:

    std::string dumpObject() override;

    int getAttackPower(Unit *unit) override;

private:
    WorkerState workerState;
};


#endif //WORKERUNIT_H_C82A6D645515446E93A03397A620F9C9
