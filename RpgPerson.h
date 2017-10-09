#ifndef RPGPERSON_H_INCLUDED
#define RPGPERSON_H_INCLUDED

#include <vector>
#include "RpgCreature.h"

class RpgPerson: public RpgCreature{
public:
    RpgPerson();
    RpgPerson(std::string name, int maxHp, int strength, int defence, int x, int y,int crits);
    int getX();
    int getY();
    void setPosition(int x, int y);
    void moveUp();
    int getLevel();
    int getExperience();
    void moveDown();
    void moveLeft();
    void moveRight();
    void raiseExperience(int value);
    bool checkLevelUp();
    void levelUp();
    virtual void statusUp();
    virtual void skill1();
	virtual void skill2(RpgCreature& enemy);
	virtual void skill3(RpgCreature& enemy);
    virtual void printStatus();
    void loserExp();
private:
    int level;
    int experience;
    int x;
    int y;
};
class SwordMan:public RpgPerson{
	public:
	SwordMan(std::string name, int maxHp, int strength, int defence, int x, int y, int crits);
	void skill1();
	void skill2(RpgCreature& enemy);
	void skill3(RpgCreature& enemy);
	void statusUp();
	void printStatus();
	private:
};
class Thief:public RpgPerson{
	public:
	Thief(std::string name, int maxHp, int strength, int defence, int x, int y, int crits);
	void skill1();
	void skill2(RpgCreature& enemy);
	void skill3(RpgCreature& enemy);
	void statusUp();
	void printStatus();
	private:
};
class Magicion:public RpgPerson{
	public:
	Magicion(std::string name, int maxHp, int strength, int defence, int x, int y, int crits);
	void skill1();
	void skill2(RpgCreature& enemy);
	void skill3(RpgCreature& enemy);
	void statusUp();
	void printStatus();
	private:
};

#endif // RPGPERSON_H_INCLUDED
