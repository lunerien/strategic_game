//
// Created by lukasz.kala on 12.07.2023.
//

#ifndef ACTION_H_4232C1FDADB24B989BEA5DB49D3B4BDD
#define ACTION_H_4232C1FDADB24B989BEA5DB49D3B4BDD


class Action {
public:
    static std::string createMoveAction(Id id, Coordinates coordinates){
        return std::to_string(id.ID) + " " + 'M' + " " + std::to_string(coordinates.getX()) + " " + std::to_string(coordinates.getY());
    }

    static std::string createAttackAction(Id id, Id idTarget){
        return std::to_string(id.ID) + " " +'A' + " " + std::to_string(idTarget.ID);
    }

    static std::string createBuildAction(Id id, UnitType unitType){
        return std::to_string(id.ID) + " " +  'B' + " " + unitType.getUnitSign();
    }


};


#endif //ACTION_H_4232C1FDADB24B989BEA5DB49D3B4BDD
