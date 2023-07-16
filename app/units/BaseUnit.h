//
// Created by lukasz.kala on 15.07.2023.
//

#ifndef BASEUNIT_H_03FC5B71258B4CB4BA456992EE01C35A
#define BASEUNIT_H_03FC5B71258B4CB4BA456992EE01C35A

#include <map>
#include "Unit.h"

class BaseUnit : public Unit {
public:
    BaseUnit(Id ID, Stamina stamina, AttackRange attackRange, Speed speed, Price price, BuildTime buildTime,
             Coordinates actualLocation, Owner owner, UnitType type, Coordinates targetedLocationGlobalState,
             Coordinates targetLocation, Map &map, std::map<UnitType::Type, int> attackPowers,
             std::vector<Unit *> &unitsPlayer, std::vector<Unit *> &unitsEnemy, UnitState state = UnitState::Standing) :
            ID(ID.ID), stamina(stamina.stamina), attackRange(attackRange.attackRange), speed(speed.Speed),
            movesLeft(speed.Speed), price(price.price), buildTime(buildTime.BuildTime), actualLocation(actualLocation),
            owner(owner), type(std::move(type)), targetedLocationGlobalState(targetedLocationGlobalState),
            targetLocation(targetLocation), state(state), attackPowers(std::move(attackPowers)), map(map),
            unitsEnemy(unitsEnemy), unitsPlayer(unitsPlayer)
            {}

    void update() override;

    Owner getOwner() override;

    UnitType getType() override;

    void move(Coordinates coordinates) override;

    void attack(Unit &unit) override;

    void takeHit(int attackPower) override;

    char getUnitSign() override;

    int getActualStamina() override;

    int getAttackRange() override;

    int getSpeed() override;

    int getId() override;

    int getPrice() override;

    int getBuildTime() override;

    Coordinates getActualLocation() override;

    UnitState getState() override;

    int getAttackPower(Unit *unit) override;

    std::string dumpObject() override;

    std::string dumpObjectAction() override;

    std::string dumpObjectAdditionalInfo() override;

    int getDistanceToTarget() override;

private:

    int ID;
    int stamina;
    int attackRange;
    int speed;
    int movesLeft;
    int price;
    int buildTime;
    Coordinates actualLocation;
    Owner owner;
    UnitType type;
    Coordinates targetedLocationGlobalState;
    Coordinates targetLocation;
    UnitState state;
    std::map<UnitType::Type, int> attackPowers;
    std::vector<std::string> actions;

protected:
    Map &map;
    std::vector<Unit *> &unitsEnemy;
    std::vector<Unit *> &unitsPlayer;
};


#endif //BASEUNIT_H_03FC5B71258B4CB4BA456992EE01C35A
