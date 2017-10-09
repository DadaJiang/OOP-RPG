#include "RpgCreature.h"
using namespace std;
RpgCreature::RpgCreature(){
//this->name = "Slime";
//this->maxHp=30;
//this->strength=10;
//this->defence=3;
//this->currentHp=maxHp;
//this->crits=20;
}
RpgCreature::RpgCreature(std::string name){
 this->name = "Slime";
    this->maxHp = 30;
    this->strength = 10;
    this->defence = 3;
    this->crits = 20;
	this->currentHp = maxHp;}
RpgCreature::RpgCreature(std::string name, int maxHp, int strength, int defence,int crits){
    this->name=name;
    this-> maxHp=maxHp;
    this->currentHp=maxHp;
    this->strength=strength;
    this->defence=defence;
    this->currentHp=maxHp;
    this->crits = crits;
}
std::string RpgCreature::getName(){
    return name;
}
int RpgCreature::getMaxHp(){
    return maxHp;
}
int RpgCreature::getCurrentHp(){
    return currentHp;
}
int RpgCreature::getStrength(){
    return strength;
}
int RpgCreature::getDefence(){
    return defence;
}
bool RpgCreature::isDead(){
    if(currentHp<=0){return true;}
    else return false;
}
void RpgCreature::loseHp(int value){
    currentHp=currentHp-value;
}
void RpgCreature::recoverHp(){
   currentHp=maxHp;
}
int RpgCreature::getCrits(){
    return this->crits;
}
void RpgCreature::attack(RpgCreature& enemy){
int rand_hurt=rand()%4;
int rand_crits=rand()%100;
int hurt;
if(rand_crits<=this->crits){
    srand(time(NULL));
    cout<<" Crits "<<endl;
    hurt=((this->strength-enemy.defence)+rand_hurt)*2;
}
else{
    srand(time(NULL));
    cout<<" No Crits "<<endl;
    hurt=this->strength-enemy.defence+rand_hurt;
}
if(hurt<0){hurt=1;}
enemy.loseHp(hurt);
cout<<this->name<<" attacked "<<enemy.getName()<<", caused "<<hurt<<" damages!"<<endl;
cout<<enemy.getName()<<" 's hp: "<<enemy.getCurrentHp()<<endl;

}


