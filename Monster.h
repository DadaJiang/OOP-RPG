#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include "RpgCreature.h"

class Monster: public RpgCreature{
public:
    Monster(std::string name, int maxHp, int strength, int defence, int crits);
   // void loseHp(int value);
private:
   // std::string name;
  //  int maxHp;
   // int currentHp;
  //  int strength;
  //  int defence;
};

#endif // MONSTER_H_INCLUDED
