//
// Created by lukasz.kala on 12.07.2023.
//

#ifndef OWNER_H_91448D76A9054379BEDF6ACE41633E68
#define OWNER_H_91448D76A9054379BEDF6ACE41633E68


class Owner {
public:
    enum class OwnerType
    {
        Player,
        Enemy
    };

    Owner(OwnerType type, char ownerSign):type(type),ownerSign(ownerSign){}

    OwnerType getOwner(){return type;}
    char getOwnerSign() const{return ownerSign;}

private:
    OwnerType type;
    char ownerSign;
};


#endif //OWNER_H_91448D76A9054379BEDF6ACE41633E68
