// CS1300 Fall 2020
// Author: Catherine Xiao, Jules Geneser 
// Recitation: 326- Sanskar Katiyar
// Project 3

#include "Landmark.h"
#include <string>
using namespace std;
Landmark::Landmark()
{
    string next_landmark = "";
    int distance = 0;  
}
Landmark::Landmark(string next_landmark, int distance)//parameterized constructor
{
    this-> next_landmark = next_landmark;
    this-> distance = distance; 
}
//setters
void Landmark::setLandmarkName(string next_landmark)
{
    this-> next_landmark = next_landmark;
}
void Landmark::setLandmarkDistance(int distance)
{
    this-> distance = distance;
}

//getters
string Landmark::getLandmarkName()
{
    return next_landmark;
}
int Landmark::getLandmarkDistance()
{
    return distance;
}