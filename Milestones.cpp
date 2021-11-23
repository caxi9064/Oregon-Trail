// CS1300 Fall 2020
// Author: Catherine Xiao, Jules Geneser 
// Recitation: 326- Sanskar Katiyar
// Project 3

#include "Milestones.h"
#include <string>
using namespace std;
Milestones::Milestones()
{
    total_mileage = 0;
    distance_remaining = 0;
    current_date = ""; 
    next_landmark = ""; 
}
Milestones::Milestones(string current_date, int total_mileage, int distance_remaining, string next_landmark)
{
    this-> total_mileage = total_mileage;
    this-> distance_remaining = distance_remaining;
    this-> current_date = current_date; 
    this-> next_landmark = next_landmark; 
}
//setters- setting values for date, total mileage, distance remaining ,next landmark
void Milestones::setCurrentDate(string current_date)
{
    this-> current_date = current_date; 
}
void Milestones::setTotalMileage (int total_mileage)
{
    this-> total_mileage = total_mileage;
}
void Milestones::setDistanceRemaining(int distance_remaining)
{
    this-> distance_remaining = distance_remaining;
}
void Milestones::setLandmark(string next_landmark)
{
    this-> next_landmark = next_landmark; 
}
    
//getters- returns date and landmark as string, distance traveled and distance remaining are int 
string Milestones::getCurrentDate() const
{
    return current_date;
}
int Milestones::getTotalMileage() const
{
    return total_mileage;
}
int Milestones::getDistanceRemaining() const
{
    return distance_remaining;
}
string Milestones::getLandmark() const
{
    return next_landmark;
}
