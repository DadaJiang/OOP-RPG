#include "Map.h"
#include<fstream>
#include<vector>
Map::Map(){}
Map::Map(std::string name, std::string nextMapName, int initialPositionX, int initialPositionY, int width, int height, vector<string> mapData){
this->name=name;
this->nextMapName=nextMapName;
this->initialPositionX=initialPositionX;
this->initialPositionY=initialPositionY;
this->width=width;
this->height=height;
this->mapData=mapData;
}
Map::~Map(){
delete [] player;
}
std::string Map::getName(){
return name;
}
std::string Map::getNextMapName(){
return nextMapName;
}
int Map::getWidth(){
return width;
}
int Map::getHeight(){
return height;
}
int Map::getinitialPositionX(){
return initialPositionX;
}
int Map::getinitialPositionY(){
 return initialPositionY;
}
char Map::getMapData(int x,int y){
return mapData[y][x];
}
bool Map::canMove(int x, int y){
if((y>height||y<0)||(x>width||x<0))return false;
else if (mapData[y][x]=='1')return false;
else return true;
}
void Map::printMap(){
for(int i=0;i<height;i++){
for(int j=0;j<width;j++){
  if(i==player->getY()&&j==player->getX()){
            cout<<"#";
    }
   else if(mapData[i][j]=='1') {cout<<"1";}
   else if(mapData[i][j]=='0') {cout<<" ";}
   else if(mapData[i][j]=='@') {cout<<"@";}

}
cout<<endl;
}
}
void Map::addPlayer(RpgPerson& player){
this->player=&player;
}
void Map::removePlayer(){
this->player=NULL;
}
//void Map::setName(string name){
//this->name=name;
//}
 //void nextmapName(std::string Name){
//
//}
