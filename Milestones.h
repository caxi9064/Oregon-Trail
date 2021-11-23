// CS1300 Fall 2020
// Author: Catherine Xiao, Jules Geneser 
// Recitation: 326- Sanskar Katiyar
// Project 3

#ifndef MILESTONES_H
#define MILESTONES_H
#include <string>
using namespace std;

class Milestones
{
    public:
    Milestones();//default constructor
    Milestones(string current_date, int total_mileage, int distance_remaining, string next_landmark);//parameterized constructor

    //setters
    void setCurrentDate(string current_date);
    void setTotalMileage (int total_mileage);
    void setDistanceRemaining(int distance_remaining);
    void setLandmark(string next_landmark);
    
    //getters
    string getCurrentDate() const;
    int getTotalMileage() const;
    int getDistanceRemaining() const;
    string getLandmark()const;

    private:
    int total_mileage; 
    int distance_remaining;
    string current_date; 
    string next_landmark; 
    

};
#endif