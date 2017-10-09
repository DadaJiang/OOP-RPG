#include <iostream>
#include<string>
#include "Map.h"
#include<time.h>
#include<stdlib.h>
#include<vector>
#include<fstream>
#include "RpgCreature.h"
#include "RpgPerson.h"
#include "Monster.h"
using namespace std;
//void load(vector<RpgPerson>)
int fight(RpgPerson&);
int main()
 {  srand(time(NULL));
    vector<Map>maps;
    vector<string>mapData;
    string character;
    string mapname;
    string temp;
    string line;
    string nextmap;
    char option;
    string garbege;
    int chose;
    int ox,oy,mx,my,number=0,youfuck=0;
    int probability=0;
    cout<<"--------------------------------------"<<endl;
	cout<<"  | Welcome to oop assignment3 rpg. | "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"Enter your name:";
    cin>>character;
    cout<<"Enter your job(1-3):(1.SwordMan 2.Thief 3.Magicion)"<<endl;
    cin>>chose;
    ifstream fin("map.txt");
    for(int mapnumber=0;mapnumber<3;mapnumber++){
            fin>>line;
            mapname=line;
         //   cout<<mapname<<endl;
            fin>>line;
            nextmap=line;
         //   cout<<nextmap<<endl;
            fin>>line;
            ox=atoi(line.c_str());
           //  cout<<ox<<endl;
            fin>>line;
            oy=atoi(line.c_str());
          //  cout<<oy<<endl;
            fin>>line;
            mx=atoi(line.c_str());
          //   cout<<mx<<endl;
            fin>>line;
            my=atoi(line.c_str());
         //    cout<<my<<endl;
             for(int line1=0;line1<10;line1++){
            fin>>line;
            //cout<<line<<endl;
            mapData.push_back(line);
          //  cout<<mapData[line1]<<endl;
          }
            fin>>garbege;
         //   cout<<garbege<<endl;
            Map *tep=new Map(mapname,nextmap,ox,oy,mx,my,mapData);
            maps.push_back(*tep);
            mapData.clear();
        }
        fin.close();
        RpgPerson* person;
        if(chose==1){person=new SwordMan(character,100,7,2,maps[0].getinitialPositionX(),maps[0].getinitialPositionY(),20);
        maps[number].addPlayer(*person);}
        if(chose==2){person=new Thief(character,100,7,2,maps[0].getinitialPositionX(),maps[0].getinitialPositionY(),20);
        maps[number].addPlayer(*person);}
        if(chose==3){person=new Magicion(character,100,7,2,maps[0].getinitialPositionX(),maps[0].getinitialPositionY(),20);
        maps[number].addPlayer(*person);}

        maps[0].printMap();
               cout<<"*****"<<endl;
               cout<<"Use w/s/a/d to move up/down/left/right."<<endl;
	           cout<<"Enter i to show your status."<<endl;
               cout<<"Enter exit to leave game."<<endl;
               cout<<"*****"<<endl;
        while(cin>>option){
             //   cout<<option<<endl;
                int probability=rand()%4;

            if(option=='e'){
                break;
            }
          if(option=='w'){
            if(maps[number].canMove(person->getX(),person->getY()-1)){
                    if(maps[number].getMapData(person->getX(),person->getY()-1)=='@'){
	     for(int k=0;k<3;k++){
		if(maps[number].getNextMapName() == maps[k].getName()){
			number=k;
			person->setPosition(maps[number].getinitialPositionX() , maps[number].getinitialPositionY());
			maps[number].addPlayer(*person);
			maps[number].printMap();
			youfuck=1;
			break;
		}}}
                    else{  person->moveUp();
                    if(probability==0)fight(*person);}
                }

            else {cout<<"Can't move up, try another direction."<<endl;}
          }
     else if(option=='s'){
            if(maps[number].canMove(person->getX(),person->getY()+1)){
                       if(maps[number].getMapData(person->getX(),person->getY()+1)=='@'){
	     for(int k=0;k<3;k++){
		if(maps[number].getNextMapName() == maps[k].getName()){
			number=k;
			person->setPosition(maps[number].getinitialPositionX() , maps[number].getinitialPositionY());
			maps[number].addPlayer(*person);
			maps[number].printMap();
			youfuck=1;
			break;
		}}}


                   else{ person->moveDown();
                    if(probability==0)fight(*person);}
                }

            else{ cout<<"Can't move down, try another direction."<<endl;}
     }
     else if(option=='a'){
            if(maps[number].canMove(person->getX()-1,person->getY())){
                       if(maps[number].getMapData(person->getX()-1,person->getY())=='@'){
	     for(int k=0;k<3;k++){
		if(maps[number].getNextMapName() == maps[k].getName()){
			number=k;
			person->setPosition(maps[number].getinitialPositionX() , maps[number].getinitialPositionY());
			maps[number].addPlayer(*person);
			maps[number].printMap();
			youfuck=1;
			break;
		}}}
               else{     person->moveLeft();
                    if(probability==0)fight(*person);}


                }

            else{ cout<<"Can't move Left, try another direction."<<endl;}
          }
        else  if(option=='d'){
            if(maps[number].canMove(person->getX()+1,person->getY())){
                       if(maps[number].getMapData(person->getX()+1,person->getY())=='@'){
	     for(int k=0;k<3;k++){
		if(maps[number].getNextMapName() == maps[k].getName()&&number!=k){
			number=k;
			break;}}
			person->setPosition(maps[number].getinitialPositionX() , maps[number].getinitialPositionY());
			maps[number].addPlayer(*person);
			maps[number].printMap();
			youfuck=1;

		}

                  else{  person->moveRight();
                    if(probability==0)fight(*person);}
                }
            else {cout<<"Can't move Right, try another direction."<<endl;}
          }
         else if(option=='i'){
            person->printStatus();
            cout<<"Map: "<<maps[number].getName()<<endl;
         }

  else if (option!='i'&&option!='w'&&option!='s'&&option!='d'&&option!='a'){cout<<"No such option"<<endl;}

              if(youfuck==0){ maps[number].printMap();}
               cout<<"*****"<<endl;
               cout<<"Use w/s/a/d to move up/down/left/right."<<endl;
	           cout<<"Enter i to show your status."<<endl;
               cout<<"Enter exit to leave game."<<endl;
               cout<<"*****"<<endl;
               youfuck=0;
        }
    return 0;
}
int fight(RpgPerson& person){
string inin;
RpgCreature ACreature("slime");
cout<<"You meet a Slime!!! The fight starts!!!"<<endl;
cout<<"-----"<<endl;
cout<<"Enter '1' to attack,'2' to use skill , '3' to escape."<<endl;
cout<<"-----"<<endl;
while(cin>>inin){
    if(inin=="3"){
    if(rand()%10<3){
        cout<<"You successfully escaped from the fight!"<<endl;
        return 0;
    }
    else{
        cout<<"Escape failed!!!"<<endl;

        ACreature.attack(person);
        if(person.isDead())
            {    person.loserExp();
                cout<<"Your hero is dead. Game Over."<<endl;
     break;
            }
    person.attack(ACreature);
    if(ACreature.isDead()){
                int exp=rand()%2+1;
                cout<<"You beat slime, add"<<exp<<"exp."<<endl;
                person.raiseExperience(exp);
                person.recoverHp();
                cout<<"HP recovered"<<endl;
                break;
            }
    }
   }
    if(inin=="1"){
            person.attack(ACreature);
            if(ACreature.isDead()){
                int exp=rand()%2+1;
                cout<<"You beat slime, add "<<exp<<"exp."<<endl;
                person.raiseExperience(exp);
                person.recoverHp();
                cout<<"HP recovered"<<endl;
             break;
            }
            ACreature.attack(person);
            if(person.isDead())
            {   person.loserExp();
                cout<<"Your hero is dead. Game Over."<<endl;
                break;
            }

    }
    if(inin=="2"){
            int skilllevel=0;
            int lv=0;
            lv=person.getLevel();
            cout<<"-----"<<endl<<"Enter '1' to use skill1, '2'to use skill2, '3' to use skill3."<<"-----"<<endl;
			cin>>skilllevel;
			if(skilllevel==1){
                    if(lv>=1){
                person.skill1();
                ACreature.attack(person);
            if(person.isDead())
            {   person.loserExp();
                cout<<"Your hero is dead. Game Over."<<endl;
                break;
            }
                }
                else{cout<<"Can¡¦t use this skill! Your Level is too low!"<<endl;}
			}
			if(skilllevel==2){
                    if(lv>=2){
                person.skill2(ACreature);
                 if(ACreature.isDead()){
                int exp=rand()%2+1;
                cout<<"You beat slime, add "<<exp<<"exp."<<endl;
                person.raiseExperience(exp);
                person.recoverHp();
                cout<<"HP recovered"<<endl;
             break;
            }
            ACreature.attack(person);
            if(person.isDead())
            {   person.loserExp();
                cout<<"Your hero is dead. Game Over."<<endl;
                break;
            }}
                else{cout<<"Can¡¦t use this skill! Your Level is too low!"<<endl;}
			}
			if(skilllevel==3){
                    if(lv>=3){
                person.skill3(ACreature);
                 if(ACreature.isDead()){
                int exp=rand()%2+1;
                cout<<"You beat slime, add "<<exp<<"exp."<<endl;
                person.raiseExperience(exp);
                person.recoverHp();
                cout<<"HP recovered"<<endl;
             break;
            }
            ACreature.attack(person);
            if(person.isDead())
            {   person.loserExp();
                cout<<"Your hero is dead. Game Over."<<endl;
                break;
            }}
                else{cout<<"Can¡¦t use this skill! Your Level is too low!"<<endl;}
			}




    }
cout<<"Enter '1' to attack,'2' to use skill , '3' to escape."<<endl;
//else cout<<"wrong input!"<<endl;
}

}








