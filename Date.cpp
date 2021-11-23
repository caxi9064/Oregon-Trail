 
// CS1300 Fall 2020
// Author: Catherine Xiao, Jules Geneser 
// Recitation: 326- Sanskar Katiyar
// Project 3

#include "Date.h"
#include <string>
#include <iostream>
using namespace std;
 
Date :: Date (){ // default constructor
   day = 28;
   month = 3;
   year = 1847;
}
 
Date :: Date (int m, int d, int y){ // parameterized constructor
   day = d;
   month = m;
   year = y;
    
}
 
// getters

int Date :: getDay()const{
   return day;
}
int Date :: getMonth () const{
   return month;
}
int Date :: getYear()const{
    return year;
}
 
//setters
void Date :: setDay(int d){
    day = d;
   getMonth();
   switch (month){
   case 1:
       if (day > 31){
           setMonth (2);
           setDay(day - 31);
       }
       break;
  
   case 2:
       if (day > 28){
           setMonth (3);
           setDay(day - 28);
       }
       break;
   case 3:
       if (day > 31){
           setMonth(4);
           setDay(day - 31);
       }
       break;
   case 4:
       if (day > 30){
           setMonth(5);
           setDay(day- 30);
       }
       break;
   case 5:
       if (day > 31){
           setMonth(6);
           setDay(day - 31);
       }
       break;
   case 6:
       if (day > 30){
           setMonth(7);
           setDay(day - 30);
       }
       break;
   case 7:
       if (day > 31){
           setMonth(8);
           setDay(day - 31);
       }
       break;
   case 8:
       if (day>31){
           setMonth(9);
           setDay(day - 31);
       }
       break;
   case 9:
       if (day > 30){
           setMonth(10);
           setDay(day - 30);
       }
       break;
   case 10:
       if (day > 31){
           setMonth(11);
           setDay(day - 31);
       }
       break;
   case 11:
       if (day > 30){
           setMonth(12);
           setDay(day - 30);
       }
       break;
   case 12:
       if (day > 31){
           setMonth(1);
           setDay(day - 31);
           setYear(1848);
       }
       break;
   }
}
void Date :: setMonth (int m){
   month = m;
   if (month > 12){
       setMonth(1);
       setYear(1848);
   }
}
void Date::setYear (int y){
   year = y;
}