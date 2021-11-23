// CS1300 Fall 2020
// Author: Catherine Xiao, Jules Geneser 
// Recitation: 326- Sanskar Katiyar
// Project 3

#include "Player.h"
#include <string>
using namespace std;

Player::Player()//default constructor
{
    name = "";
    score = 0;
    health = 0; 
}
Player::Player(string name, int score, int health)//parameterized constructor
{
    this-> name = name;
    this-> score = score;
    this-> health = health;
}
//setters
void Player::setUsername(string name)
{
    this-> name = name;//setting username
}
void Player::setScore(int score)
{
    this-> score = score;//setting score
}
void Player::setHealth(int health)
{
    this-> health = health;//setting health score
}
void Player::setTotalTravelers(int totalTravelers)
{
    this-> totalTravelers = totalTravelers;
}
//getters
string Player::getUsername() const
{
    return name; //returning player name
}
int Player::getScore() const
{
    return score;//returning score
}
int Player::getHealth() const
{
    return health;//returning health 
}
int Player::getTotalTravelers()const
{
    return totalTravelers;
}