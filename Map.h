#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include "RpgPerson.h"
#include<vector>


using namespace std;
class Map{
public:
    Map();
    Map(string name,string nextMapName, int initialPositionX, int initialPositionY, int width, int height, vector<string> mapData);
    ~Map();
    std::string getName();
    std::string getNextMapName();
    int getWidth();
    int getHeight();
    int getinitialPositionX();
    int getinitialPositionY();
    char getMapData(int x, int y);
    bool canMove(int x, int y);
    void printMap();
    void addPlayer(RpgPerson& player);
    void removePlayer();
private:
    std::string name;
    std::string nextMapName;
    int width;
    int height;
    int initialPositionX;
    int initialPositionY;
    vector<string> mapData;

    RpgPerson* player;
};

#endif // MAP_H_INCLUDED
