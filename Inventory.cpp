// CS1300 Fall 2020
// Author: Catherine Xiao, Jules Geneser 
// Recitation: 326- Sanskar Katiyar
// Project 3

#include "Inventory.h"
#include <string>
#include <iostream>
using namespace std;

Inventory::Inventory()//default constructor
{
    food_remaining = 0;
    cash_available = 1600;
    ammunition = 0;
    num_oxen = 0;
    medical_kits = 0;
    wagon_parts = 0;
    storeTotal=0;
    storePercentIncrease = 1;
}
Inventory::Inventory(int food_remaining, double cash_available, int ammunition, int num_oxen, int medical_kits, int wagon_parts)
{//parameterized constructor
    this-> food_remaining = food_remaining;
    this-> cash_available = cash_available;
    this-> ammunition = ammunition;
    this-> num_oxen = num_oxen;
    this-> medical_kits = medical_kits;
    this-> wagon_parts = wagon_parts;

}

//setters- setting values for all items in inventory
void Inventory::setFoodRemaining(int food_remaining)
{
    this-> food_remaining = food_remaining;
}
void Inventory::setCashAvailable(double cash_available)
{
    this-> cash_available = cash_available;
}
void Inventory::setAmmunition(int ammunition)
{
    this-> ammunition = ammunition;
}
void Inventory::setOxen(int num_oxen)
{
    this-> num_oxen = num_oxen;
}
void Inventory::setMedicalKits(int medical_kits)
{
    this-> medical_kits = medical_kits;
}
void Inventory::setWagonParts(int wagon_parts)
{
    this-> wagon_parts = wagon_parts;
}
void Inventory::setStoreTotal(string s, int quantity)
{
    double originalTotal = getStoreTotal();
    if (s == "oxen"){
        if (quantity < 3){
            storeTotal += 0;
            cout << "You must enter a higher number of Yokes to reach the minimum requirement." << endl;
        }
        else {
            storeTotal += (quantity * 40.0); //two oxen in each yoke so $20 for each oxen
        }
    }
    if (s == "food"){
        storeTotal += (quantity * 0.5);
    }
    if (s == "bullets"){
        storeTotal += (quantity * 2);
    }
    if (s == "wagonParts"){
        storeTotal += (quantity * 20);
    }
    if (s == "medKits"){
        storeTotal += (quantity * 25);
    }     
    //total cannot exceed 1600
    if (storeTotal >= 1600){ 
        cout << endl <<  "Your current store total is: $" << getStoreTotal() << endl;
        cout << "Purchase exceeds the money that you have. Please try again." << endl;
        storeTotal = originalTotal; //not added to storeTotal
    }
    else {
        cout << endl << "Your current store total is: $" << getStoreTotal() << endl;
        setCashAvailable(1600-(storeTotal));
        if (s == "oxen"){
            int num = quantity*2 + getOxen();
            setOxen(num );
        }
        if (s == "food"){
           setFoodRemaining(quantity + getFoodRemaining());
        }
        if (s == "bullets"){
           setAmmunition(quantity*20 + getAmmunition());
        }
        if (s == "wagonParts"){
           setWagonParts(quantity + getWagonParts());
        }
        if (s == "medKits"){
           setMedicalKits(quantity + getMedicalKits());
        }
   }
}
void Inventory :: setStorePercentIncrease (double storePercentIncrease)
{
   this -> storePercentIncrease = storePercentIncrease;
}

//getters- returns int value
double Inventory::getCashAvailable() const
{
    return cash_available;
}
int Inventory::getFoodRemaining() const
{
    return food_remaining;
}
int Inventory::getAmmunition() const
{
    return ammunition;
}
int Inventory::getOxen() const
{
    return num_oxen;
}
int Inventory::getMedicalKits() const
{
    return medical_kits; 
}
int Inventory::getWagonParts() const
{
    return wagon_parts;
}
double Inventory::getStoreTotal() const
{
    return storeTotal;
}
int Inventory :: getStorePercentIncrease()const
{
   return storePercentIncrease;
}
