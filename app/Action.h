//
// Created by lukasz.kala on 12.07.2023.
//

#ifndef ACTION_H_4232C1FDADB24B989BEA5DB49D3B4BDD
#define ACTION_H_4232C1FDADB24B989BEA5DB49D3B4BDD


class Action {
public:
    enum class Type
    {
        Move,
        Attack,
        TakeHit,
        GetUnitSign,
        GetActualStamina,
        GetAttackRange,
        GetSpeed,
        GetId,
        GetPrice,
        GetBuildTime,
        GetActualLocation,
        GetType
    };

    Action(Action::Type type):type(type){}

    Type getType(){return type;}
private:
    Type type;
    int chance;
};


#endif //ACTION_H_4232C1FDADB24B989BEA5DB49D3B4BDD
