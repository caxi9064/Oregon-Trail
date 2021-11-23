// CS1300 Fall 2020
// Author: Catherine Xiao, Jules Geneser 
// Recitation: 326- Sanskar Katiyar
// Project 3

#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>
#include "Player.h"
#include "Inventory.h"
#include "Milestones.h"
#include "Date.h"
#include "Landmark.h"
using namespace std;
class Game
{
    public:
    Game();
    Game(vector<Player> players);

    //getters
    string getNameAt(int index)const;//return player name at index
    int getPointsAt(int index)const;//return # of points at index
    int getHealthAt(int index)const; 
    int getNumPlayers()const;//get # of players in vector
    int getRandomNum()const;
    int getNumLandmarks() const;
    
    //setters
    void setPlayerNameAt(int index, string name); 
    void setPointsAt(int index, int points);
    void setHealthAt(int index, int health);

    void printTurnsMenu();//print menu of options at each turn
    void printStoreMenu();//prints store menu 
    void readStoreInfo();//read store_info.txt
    void printInventory();//prints amount of items in the inventory
    void StartingInfo();//prompts user for name and date 
    void printStatusUpdate(); ///prints the date and other milestones at each turn
    void randomNumGenerator(int a, int b);//generates random num 
    bool Misfortunes();
    void RaiderAttack();
    void Hunt();
    void choiceToHunt(int animal);
    bool Puzzle();
    void readMilestonesFile();//reads milestones.txt and store in a vector 
    void LandmarkCheck();//this function will allow us to set distance to the next landmark 
    void FinalStats();//function prints final stats for the player
    void run();//includes all other functions
    bool endGameCheck();//checks end game conditions
    private:
    //declaring objects of other classes
    Inventory inv;
    Date d; 
    Milestones m;
    Landmark L;
    Player p;
    
    vector<Player> players; //vector of player objects
    vector<Landmark> landmarks; //vector of landmark objects

    int random;//what the randomNumGenerator() function returns
};
#endif