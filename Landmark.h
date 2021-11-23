// CS1300 Fall 2020
// Author: Catherine Xiao, Jules Geneser 
// Recitation: 326- Sanskar Katiyar
// Project 3

#ifndef LANDMARK_H
#define LANDMARK_H
#include <string>
using namespace std;
class Landmark
{
    public: 
    Landmark();
    Landmark(string next_landmark, int distance);//parameterized constructor;
    
    //setters
    void setLandmarkName(string next_landmark);
    void setLandmarkDistance(int distance);

    //getters
    string getLandmarkName();
    int getLandmarkDistance();

    private:
    string next_landmark;
    int distance;

};
#endif
