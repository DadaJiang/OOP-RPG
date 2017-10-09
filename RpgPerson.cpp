#include "RpgPerson.h"
#include "RpgCreature.h"
#include "Map.h"

using namespace std;
RpgPerson::RpgPerson(std::string name, int maxHp, int strength, int defence, int x, int y,int crits){
   this->name=name;
   this->maxHp=maxHp;
   this->strength=strength;
   this->defence=defence;
   this->x=x;
   this->y=y;
   this->level=1;
   this->experience=0;
//   this->job=job;
   this->crits=crits;
   this->currentHp=maxHp;
}

int RpgPerson::getX(){
return x;
}

int RpgPerson::getY(){
return y;
}
int RpgPerson::getLevel(){
	return this->level;
}
int RpgPerson::getExperience(){
 	return this->experience;
 }

void RpgPerson::setPosition(int x, int y){
this->x=x;
this->y=y;
}
void RpgPerson::moveUp(){
this->y=this->y-1;
}
void RpgPerson::moveDown(){
this->y=this->y+1;
}
void RpgPerson::moveLeft(){
this->x=this->x-1;
}
void RpgPerson::moveRight(){
this->x=this->x+1;
}
void RpgPerson::raiseExperience(int value){
experience=experience+value;
checkLevelUp();
}
bool RpgPerson::checkLevelUp(){
if(experience>=(7*(1/2+(level/2))))levelUp();
}
void RpgPerson::levelUp(){
experience-=(7*(1/2+(level/2)));
cout<<"Level up!!! You are level "<<++level<<endl;
statusUp();
}
void RpgPerson::statusUp(){
maxHp=maxHp+5;
strength=strength+1;
defence=defence+1;
}
void RpgPerson::printStatus(){
cout<<"Name:"<<name<<endl;
cout<<"Lv:"<<level<<endl;
cout<<"Hp:"<<maxHp<<endl;
cout<<"Strength:"<<strength<<endl;
cout<<"Defence:"<<defence<<endl;
cout<<"Crits: "<<crits<<endl;
cout<<"Exp:"<<experience<<"/"<<level<<endl;
}
void RpgPerson::loserExp(){
int lose=rand()%2+1;
experience-=lose;
if(experience<0)experience=0;
}
void RpgPerson::skill1(){
}
void RpgPerson::skill2(RpgCreature& enemy){
}
void RpgPerson::skill3(RpgCreature& enemy){
}
SwordMan::SwordMan(std::string name, int maxHp, int strength, int defence, int x, int y, int crits):RpgPerson(name,maxHp,strength,defence,x,y,crits){
}

void SwordMan::skill1(){
        int heal=0;
		if(currentHp<maxHp){
        heal=(maxHp-currentHp)*1/2;
        currentHp+=heal;
		}
		cout << "神聖治癒 You get a lose HP 1/2 " <<heal<< "Hp"<<endl;
		cout<<name<<"'s hp : "<<currentHp<<endl;
}

void SwordMan::skill2(RpgCreature& enemy){
		int value;
    	value = (strength-enemy.getDefence()) * 6;
    	enemy.loseHp(value);
    	cout << "滅龍一擊"<<endl;
    	cout<<name<<" attacked "<<enemy.getName()<<", caused "<<value<<"  damages!"<<endl;
    	cout<<enemy.getName()<<"'s hp:"<<enemy.getCurrentHp()<<endl;
}

void SwordMan::skill3(RpgCreature& enemy){
		int value;
		value=this->getLevel()+this->getExperience()+strength+defence;
		enemy.loseHp(value);
    	cout << "如來神掌"<<endl;
    	cout<<name<<" attacked "<<enemy.getName()<<", caused "<<value<<"  damages!"<<endl;
    	cout<<enemy.getName()<<"'s hp:"<<enemy.getCurrentHp()<<endl;
}

void SwordMan::printStatus(){
   cout<<"Name: "<<name<<endl;
   cout<<"Lv: "<<getLevel()<<endl;
   cout<<"Job: SwordMan"<<endl;
   cout<<"Hp: "<<maxHp<<endl;
   cout<<"Strength: "<<strength<<endl;
   cout<<"Defence: "<<defence<<endl;
   cout<<"Crits: "<<crits<<endl;
   cout<<"Exp: "<<getExperience()<<"/"<<(int)(7*(0.5+(float)getLevel()/2))<<endl;
}
void SwordMan::statusUp(){
maxHp=maxHp+5;
strength=strength+1;
defence=defence+2;
}

Thief::Thief(std::string name, int maxHp, int strength, int defence, int x, int y, int crits):RpgPerson(name,maxHp,strength,defence,x,y,crits){
}

void Thief::skill1(){
		int heal=0;
		if(currentHp<maxHp){
        heal=(maxHp-currentHp)*1/2;
        currentHp+=heal;
		}
		cout << "神聖治癒You get a lose HP 1/2 " <<heal<< "Hp"<<endl;
		cout<<name<<"'s hp : "<<currentHp<<endl;
}

void Thief::skill2(RpgCreature& enemy){
    	cout << "連續突刺<普通攻擊加上浮動傷害攻擊兩次>"<<endl;
    	int value;
    	value = strength - enemy.getDefence()+rand()%6;
    	for(int i=0 ; i<2 ; i++){
    	enemy.loseHp(value);
		cout<<name<<" attacked "<<enemy.getName()<<", caused "<<value<<"  damages!"<<endl;
		cout<<enemy.getName()<<"'s hp:"<<enemy.getCurrentHp()<<endl;
        }
}

void Thief::skill3(RpgCreature& enemy){
    	cout << "同歸於盡"<<endl;
    	currentHp-=5;
    	enemy.loseHp(10);
	}

void Thief::statusUp(){
maxHp=maxHp+5;
strength=strength+1;
defence=defence+1;
crits=crits+5;
}

void Thief::printStatus(){
   cout<<"Name: "<<name<<endl;
   cout<<"Lv: "<<getLevel()<<endl;
   cout<<"Job: Thief"<<endl;
   cout<<"Hp: "<<currentHp<<endl;
   cout<<"Strength: "<<strength<<endl;
   cout<<"Defence: "<<defence<<endl;
   cout<<"Crits: "<<crits<<endl;
   cout<<"Exp: "<<getExperience()<<"/"<<(int)(7*(0.5+(float)getLevel()/2))<<endl;
}

Magicion::Magicion(std::string name, int maxHp, int strength, int defence, int x, int y, int crits):RpgPerson(name,maxHp,strength,defence,x,y,crits){
}

void Magicion::skill1(){
		int heal=0;
		if(currentHp<maxHp){
        heal=(maxHp-currentHp)*1/2;
        currentHp+=heal;
		}
		cout << "神聖治癒You get a lose HP 1/2 " <<heal<< "Hp"<<endl;
		cout<<name<<"'s hp : "<<currentHp<<endl;
}

void Magicion::skill2(RpgCreature& enemy){
		cout << "爪爪<普通攻擊3次>"<<endl;
    	int value;
    	value = strength - enemy.getDefence();
    	for(int i=0 ; i<3 ; i++){
    	enemy.loseHp(value);
		cout<<name<<" attacked "<<enemy.getName()<<", caused "<<value<<"  damages!"<<endl;
		cout<<enemy.getName()<<"'s hp:"<<enemy.getCurrentHp()<<endl;
        }
}


void Magicion::skill3(RpgCreature& enemy){
        cout << "Go go lamigo<造成致命性傷害>"<<endl;
    	int value;
    	value =enemy.getCurrentHp()-1;
    	enemy.loseHp(value);
		cout<<name<<" attacked "<<enemy.getName()<<", caused "<<value<<"  damages!"<<endl;
		cout<<enemy.getName()<<"'s hp:"<<enemy.getCurrentHp()<<endl;

}

void Magicion::statusUp(){
	maxHp += 5;
	strength+=2;
 	defence+=1;
 	crits+=0;
}

void Magicion::printStatus(){
   cout<<"Name: "<<name<<endl;
   cout<<"Lv: "<<getLevel()<<endl;
   cout<<"Job: Magicion"<<endl;
   cout<<"Hp: "<<currentHp<<endl;
   cout<<"Strength: "<<strength<<endl;
   cout<<"Defence: "<<defence<<endl;
   cout<<"Crits: "<<crits<<endl;
   cout<<"Exp: "<<getExperience()<<"/"<<(int)(7*(0.5+(float)getLevel()/2))<<endl;
}





