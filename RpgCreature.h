#ifndef RPGCREATURE_H_INCLUDED
#define RPGCREATURE_H_INCLUDED

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <vector>

class RpgCreature{
public:
    RpgCreature();
    RpgCreature(std::string name);
    RpgCreature(std::string name, int maxHp, int strength, int defence,int crits);
    std::string getName();
    int getMaxHp();
    int getCurrentHp();
    int getStrength();
     int getCrits();
    int getDefence();
    bool isDead();
    void loseHp(int value);
    void recoverHp();
    void attack(RpgCreature& enemy);
protected:
    std::string name;
    int maxHp;
    int currentHp;
    int strength;
    int defence;
    int crits;
};

#endif // RPGCREATURE_H_INCLUDED
