//
// Created by lukasz on 09.07.23.
//

#ifndef STRATEGIC_GAME_UNIT_H
#define STRATEGIC_GAME_UNIT_H
#include "../utils/Coordinates.h"
#include "UnitType.h"
#include "Owner.h"
#include "../Map.h"
#include <string>

//Interface type for unit handling
class Unit {
public:
//    virtual void move(Coordinates coordinates) = 0;
//    virtual void attack(Coordinates coordinates, Unit& unit) = 0;
    virtual void takeHit(int attackPower) = 0;
    virtual void update() = 0;

    enum class UnitState
    {
        Standing,
        GoingToTarget,
        Fighting,
        Dead
    };
public:

    virtual int getActualStamina() = 0;
    virtual int getAttackRange() = 0;
    virtual int getAttackPower(Unit *unit) = 0;
    virtual int getSpeed() = 0;
    virtual int getId() = 0;
    virtual int getPrice() = 0;
    virtual int getBuildTime() = 0;
    virtual Owner getOwner() = 0;
    virtual Coordinates getActualLocation() = 0;
    virtual UnitType getType() = 0;
    virtual std::string dumpObject() = 0;
    virtual std::string dumpObjectAction() = 0;
    virtual std::string dumpObjectAdditionalInfo() = 0;
    virtual char getUnitSign() = 0;
    virtual void move(Coordinates coordinates) = 0;

    virtual void attack(Unit &unit) = 0;
    struct AttackStat
    {
        UnitType::Type unitType;
        int attackPower;
    };
    virtual UnitState getState() = 0;
public:
    virtual ~Unit() = default;


};

struct Stamina
{
    int stamina;
};

struct AttackRange
{
    int attackRange;
};

struct Speed
{
    int Speed;
};

struct Id
{
    int ID;
};

struct Price
{
    int price;
};

struct BuildTime
{
    int BuildTime;
};


#endif //STRATEGIC_GAME_UNIT_H
