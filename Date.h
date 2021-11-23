// CS1300 Fall 2020
// Author: Catherine Xiao, Jules Geneser 
// Recitation: 326- Sanskar Katiyar
// Project 3

#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;
 
class Date{
   private:
       int day;
       int month;
       int year;

   public:
       Date (); // default constructor
       Date (int m, int d, int y); // parameterized constructor
 
       // getters
       int getDay() const;
       int getMonth() const;
       int getYear() const;
       
       // setters
       void setDay(int d);
       void setMonth(int m);
       void setYear(int y);
};
#endif