// CS1300 Fall 2020
// Author: Catherine Xiao, Jules Geneser 
// Recitation: 326- Sanskar Katiyar
// Project 3

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class Player
{
    public:
    Player();
    Player(string name, int score, int health);

    //setters
    void setUsername(string name);
    void setScore(int score);
    void setHealth(int health);
    void setTotalTravelers(int totalTravelers);

    //getters
    string getUsername() const;
    int getScore() const;
    int getHealth() const; 
    int getTotalTravelers() const;

    private: 
    int score; 
    string name;  
    int health; 
    int totalTravelers;
};

#endif