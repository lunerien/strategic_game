//
// Created by lukasz on 09.07.23.
//

#ifndef STRATEGIC_GAME_UNIT_H
#define STRATEGIC_GAME_UNIT_H
#include "../utils/Coordinates.h"

//Interface type for unit handling
class Unit {
public:
    virtual void move(Coordinates coordinates) = 0;
    virtual void attack(Coordinates coordinates, Unit& unit) = 0;
    virtual void takeHit(int attackPower) = 0;
public:
    virtual char getUnitSign() = 0;
    virtual int getActualStamina() = 0;
    virtual int getAttackRange() = 0;
    virtual int getSpeed() = 0;
    virtual int getId() = 0;
    virtual int getPrice() = 0;
    virtual int getBuildTime() = 0;
    virtual Coordinates getActualLocation() = 0;
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
