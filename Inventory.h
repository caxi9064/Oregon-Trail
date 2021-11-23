// CS1300 Fall 2020
// Author: Catherine Xiao, Jules Geneser 
// Recitation: 326- Sanskar Katiyar
// Project 3

#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
using namespace std;

class Inventory
{
    public: 
    Inventory();
    Inventory(int food_remaining, double cash_available, int ammunition, int num_oxen, int medical_kits, int wagon_parts);

    //setters
    void setCashAvailable(double cash_available);
    void setFoodRemaining(int food_remaining);
    void setAmmunition(int ammunition);
    void setOxen(int num_oxen);
    void setMedicalKits(int medical_kits);
    void setWagonParts(int wagon_parts);
    void setStoreTotal(string s, int quantity);
	void setStorePercentIncrease(double storePercentIncrease);

    //getters
    double getCashAvailable() const;
    int getFoodRemaining() const;
    int getAmmunition() const;
    int getOxen() const;
    int getMedicalKits() const;
    int getWagonParts() const;
    double getStoreTotal() const;
    int getStorePercentIncrease()const;

    private: 
    int food_remaining; 
    double cash_available;
    int ammunition;
    int num_oxen;
    int medical_kits; 
    int wagon_parts; 
    double storeTotal;
    double storePercentIncrease;
};

#endif