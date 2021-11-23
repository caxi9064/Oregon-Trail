// CS1300 Fall 2020
// Author: Catherine Xiao, Jules Geneser 
// Recitation: 326- Sanskar Katiyar
// Project 3

#include "Game.h"
#include "Player.h"
#include "Inventory.h"
#include "Milestones.h"
#include "Date.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;
Game::Game()
{
    for (int i = 0; i < players.size(); i++)
    {
        players[i].setUsername("");
        players[i].setScore(0);
        players[i].setHealth(100);
    }
}
Game::Game(vector<Player> players)
{
    for (int i = 0; i < players.size(); i++)
    {
        //setting vector of player objects
        this->players[i] = players[i];
    }
}

//getters
string Game::getNameAt(int index) const
{
    return players[index].getUsername(); //return player name at index
}
int Game::getPointsAt(int index) const
{
    return players[index].getScore(); //return # of points at index
}
int Game::getHealthAt(int index) const
{
    return players[index].getHealth(); //return health score
}
int Game::getNumPlayers() const
{
    return players.size(); //get # of players in vector
}
int Game::getRandomNum() const
{
    return random;
}

//setters
void Game::setPlayerNameAt(int index, string name)
{
    players[index].setUsername(name); //setting user name
}
void Game::setPointsAt(int index, int points)
{
    players[index].setScore(points); //setting score
}
void Game::setHealthAt(int index, int health)
{
    players[index].setHealth(health);//setting health
}

//these functions will all be included in run() function at the end
void Game::printTurnsMenu() //prints menu of options to user during each turn
{
    cout << "Would you like to...\n"
         << "(1) Continue on trail\n"
         << "(2) Stop to rest\n"
         << "(3) Hunt\n"
         << "(4) Check inventory\n"
         << "(5) Quit" << endl;
}
void Game::printStoreMenu() //prompts user to shop and prints total bill using function setStoreTotal() in inventory class
{
    string s;
    int option = 0;
    int num;

    while (option != 6)
    {
        cout << endl << "Would you like to buy..\n"
             << "1. Oxen\n"
             << "2. Food\n"
             << "3. Box of Bullets\n"
             << "4. Wagon parts\n"
             << "5. Medical kits\n" 
             << "6. Finish" << endl;
        getline(cin, s);
        option = stoi(s);

        if (option < 1 || option > 6)
        {
            cout << "Invalid input. Try again." << endl;
        }
        if (option == 1)
        {
            cout << "You must be between $100 - $200 dollars worth of oxen. Each yoke (2 oxen) costs $40.\n"
                 << "Enter the number of yokes you would like to purchase: " << endl;
            getline(cin, s);
            num = stoi(s);
            inv.setStoreTotal("oxen", num);
        }
        if (option == 2)
        {
            cout << "It is recommended that you buy at least 200 lbs of food. Each lb of food costs $0.50\n"
                 << "How many lbs of food would you like to buy?" << endl;
            getline(cin, s);
            num = stoi(s);
            inv.setStoreTotal("food", num);
        }
        if (option == 3)
        {
            cout << "A box of 20 bullets cost $2. You will need bullets for hunting along the way. \n"
                 << "How many boxes would you like to purchase?" << endl;
            getline(cin, s);
            num = stoi(s);
            inv.setStoreTotal("bullets", num);
        }
        if (option == 4)
        {
            cout << "How many wagon parts do you wish to purchase?" << endl;
            getline(cin, s);
            num = stoi(s);
            inv.setStoreTotal("wagonParts", num);
        }
        if (option == 5)
        {
            cout << "How many medical kits do you wish to purchase?" << endl;
            getline(cin, s);
            num = stoi(s);
            inv.setStoreTotal("medKits", num);
        }
        inv.setCashAvailable(1600-inv.getStoreTotal());
        cout << "Cash Remaining: " << inv.getCashAvailable() << endl;

    }
}
void Game::printInventory() //prints amount of items available in the inventory
{
    cout << endl << "---CURRENT INVENTORY---" << endl<< "Total cash available: " << inv.getCashAvailable() 
    << "\nTotal food remaining: " << inv.getFoodRemaining() << "\nTotal Oxen: " << inv.getOxen()
    << "\nTotal Medical Kits: " << inv.getMedicalKits() << "\nTotal Wagon Parts: " << inv.getWagonParts()
    << "\nTotal Ammunition: " << inv.getAmmunition() << endl << endl;
}
void Game::readStoreInfo()//read store_info.txt 
{
    string line;
    ifstream storeInfo;
    storeInfo.open("store_info.txt");
    cout << endl;
    while(getline(storeInfo, line))
    {
        cout << line << endl;
    }
    cout << endl;
}
void Game::StartingInfo() //prompts user for player names/starting date- stores names in vector
{
    string s;
    cout << "ENTER YOUR NAME:" << endl;
    getline(cin, s);
    Player player1(s, 0, 100);
    players.push_back(player1);
    p.setUsername(s);//setting the username of the player

    cout << "ENTER THE NAMES OF YOUR TEAM: \n"
         << "p2: \n"
         << "p3: \n"
         << "p4: \n"
         << "p5: \n"
         << endl;
    getline(cin, s);
    Player player2(s, 0, 100);
    players.push_back(player2);
    getline(cin, s);
    Player player3(s, 0, 100);
    players.push_back(player3);
    getline(cin, s);
    Player player4(s, 0, 100);
    players.push_back(player4);
    getline(cin, s);
    Player player5(s, 0, 100);
    players.push_back(player5);

    //prompting user for the starting date of their choosing
    cout << "Would you like to start on the default date? Y/N" << endl;
    getline(cin, s);
    while (s != "Y" && s != "N") //Must enter Y or N
    {
        cout << "Invalid input. Please enter Y or N" << endl;
        getline(cin, s);
    }
    if (s == "Y")
    {
        Date d; //set date to 3/28/1847
        cout << "You will be starting on: " << d.getMonth() << "/" << d.getDay() << "/" << d.getYear() << endl;
    }
    else if (s == "N")
    {
        int month;
        int day;
        cout << "Which month would you like to start? Enter a month btw 3 and 5:" << endl;
        getline(cin, s);
        month = stoi(s);
        cout << "Which date would you like to start?" << endl;
        getline(cin, s);
        day = stoi(s);

        Date d(month, day, 1847); //set date to user specified date
        cout << "You will be starting on: " << d.getMonth() << "/" << d.getDay() << "/" << d.getYear() << endl;
    }
}
void Game::printStatusUpdate() //prints the date and other milestones
{
    cout << endl << "----STATUS UPDATE---- " << endl
        << "Leader Name: " << getNameAt(0) << endl
        << "Current Date: " << d.getMonth() << "/" << d.getDay() << "/" << d.getYear() << endl
        << "Total Miles Traveled: " << m.getTotalMileage() << endl
        << "Distance Until Next Milestone: " << m.getDistanceRemaining() << endl
        << "Food Available (lbs): " << inv.getFoodRemaining() << endl
        << "Total Ammunition: " << inv.getAmmunition() << endl
        << "Cash Available: " << inv.getCashAvailable() << endl << "----STATUS UPDATE----"  << endl << endl;
}
void Game::randomNumGenerator(int a, int b) //generates a random number
{                                           // int a is the start and int b is the end value
    int difference = b - a + 1;
    srand(time(0));
    random = rand() % difference + a;
}
bool Game::Misfortunes()//occurs at end of every turn- also checks end condition for wagon parts 
{ 
    randomNumGenerator(1,100);
    int num = getRandomNum();
    if (num >= 1 && num <= 40)//40% chance misfortune will occur
    {
        cout << endl << "YOU HAVE ENCOUNTERED A MISFORTUNE: ";
        randomNumGenerator(1,2);
        num = getRandomNum();
        switch(num)
        {
            case 1://player gets sick
            {
                randomNumGenerator(1, 5);
                int playerNum = getRandomNum(); 
                string player_name = getNameAt(playerNum-1);//get player name
                int medical_kits = inv.getMedicalKits();//get Med kits
                cout << player_name << " has typhoid." << endl;
                if(medical_kits > 0)//if med kit available
                {
                    inv.setMedicalKits(medical_kits - 1);//delete one med kit from inventory
                    randomNumGenerator(1,100);
                    num = getRandomNum();
                    if (num >=1 && num <= 50){//50% chance of dying
                        setHealthAt(playerNum-1, 0);
                        p.setTotalTravelers(p.getTotalTravelers()-1);//player dies
                        cout << "unfortunately, " << player_name << " died." << endl;
                    }
                    else{
                        setHealthAt(playerNum-1, 50);
                        cout << player_name << " survived!" << endl;
                    } 
                }
                else//no med kits
                {
                    string s;
                    cout << "Would you like to rest? Resting takes 3 days. Please enter Y/N." << endl;
                    getline(cin, s);
                    if (s == "N")//player chooses to press on
                    {
                        randomNumGenerator(1,100);
                        num = getRandomNum();
                        if (num >=1 && num <= 70){
                            setHealthAt(playerNum-1, 0);
                            p.setTotalTravelers(p.getTotalTravelers()-1);
                            cout << "unfortunately, " << player_name << " died." << endl;
                        }
                        else {
                            setHealthAt(playerNum-1, 50);
                            cout << player_name << " survived!" << endl;
                        }
                        d.setDay(d.getDay()+14);
                    }
                    else//player chooses to rest
                    {
                        randomNumGenerator(1,100);
                        num = getRandomNum();
                        if (num >=1 && num <= 30)
                        {
                            setHealthAt(playerNum-1, 0);
                            p.setTotalTravelers(p.getTotalTravelers()-1);
                            cout << "unfortunately, " << player_name << " died." << endl;
                        }
                        else 
                        {
                            setHealthAt(playerNum-1, 50);
                            cout << player_name << " survived!" << endl;
                        }
                        d.setDay(d.getDay()+3);//adding 3 days 
                    } 
                }
                if (getHealthAt(0) == 0)//if player 1 dies game ends
                {
                    cout << endl << "UNFORTUNATELY YOU HAVE DIED. GAME OVER" << endl;
                    return true;
                }
            } break;
            case 2://oxen dies
            {
                inv.setOxen(inv.getOxen()-1);
                if (inv.getOxen() > 0)
                {
                    cout << "one of your oxen is dead. you now have " << inv.getOxen() << " oxen." << endl; 
                }  
                else //if no oxen remain game ends
                {
                    cout << endl << "ALL YOUR OXEN DIED. GAME OVER" << endl;
                    return true;
                }
            } break;
            case 3://broken wagon
            {
                cout << "part of the wagon is broken. spare supplies will be used to fix it." << endl; 
                if (inv.getWagonParts() > 0)
                {
                    inv.setWagonParts(inv.getWagonParts() - 1);
                    cout << "wagon fixed! you now have " << inv.getWagonParts() << " spare supplies." << endl;
                }
                else//no parts left game over
                { 
                    inv.setWagonParts(0);
                    cout << "YOUR WAGON IS BROKEN. GAME OVER." << endl;
                    return true;
                }
            } break;
            default: break;
        }
    }
    if (num > 40 && num <= 65)//25% positive events
    {
        randomNumGenerator(1,3);
        num = getRandomNum();
        switch(num)
        {
            case 1: {
                int cash = inv.getCashAvailable() + 500;
                inv.setCashAvailable(cash); 
                cout << "YOU DISCOVERED MONEY ON THE GROUND. +$500" << endl;
            } break;
            case 2:{
                int food = inv.getFoodRemaining() + 500;
                inv.setFoodRemaining(food);
                cout << "YOU DISCOVERED AN ABANDONED WAGON. +500 LBS OF FOOD " << endl;
            } break;
            case 3:{
                int mileage = m.getTotalMileage() + 100; 
                m.setTotalMileage(mileage);
                int food = inv.getFoodRemaining() + 100;
                inv.setFoodRemaining(food);
                cout << "YOU DISCOVERED AN ABANDONED WAGON. +100 LBS OF FOOD " << endl
                << "WEATHER IS ALSO NICE. YOU TRAVELED AN EXTRA 50 MILES. +100 miles" << endl;
            } break;
            default: break;
        }
    }
    printStatusUpdate();
    return false;
}
void Game::RaiderAttack() 
{
    double n = (m.getTotalMileage()/100.0 - 4.0);
    double probability = ( ((pow(n, 2.0) + 72)/(pow(n, 2.0) + 12)) - 1 ) / 0.10;
    randomNumGenerator(1,100);
    int num = getRandomNum();
    
    if (num >= 1 && num <= probability)
    {
        string s;
        cout << endl << "RIDERS AHEAD! THEY LOOK HOSTILE!" << endl;
        cout << "you have 3 options: " << endl << "(1) run" << endl << "(2) attack"  << endl << "(3) surrender" << endl;
        getline(cin, s);
        //if they do not enter valid input
        int choice = stoi(s);
        while (choice != 1 && choice != 2 && choice != 3)
        {
            cout << endl << "Invalid Input." << endl << "you have 3 options: " << endl << "(1) run" << endl << "(2) attack"  << endl << "(3) surrender" << endl;
        }
        switch(choice)
        {
            case 1://run
            {
                inv.setOxen(inv.getOxen()-1);
                inv.setFoodRemaining(inv.getFoodRemaining()-10);
                inv.setWagonParts(inv.getWagonParts()-1);
                cout << endl << "YOU ESCAPED BUT LEFT BEHIND" << endl << "-1 OXEN" << endl << "-10 LBS OF FOOD" << endl << "-1 WAGON PARTS" << endl;
            } break;
            case 2://attack
            {
                bool result = Puzzle();
                if (result == true)//they guessed correctly
                {
                    inv.setAmmunition(inv.getAmmunition()+50);
                    inv.setFoodRemaining(inv.getFoodRemaining()+50);
                    cout << endl << "YOU WON THE BATTLE. " << endl << "+$50 LBS OF FOOD" << endl << "+50 bullets" << endl;
                }
                else//guessed wrong
                {
                    inv.setAmmunition(inv.getAmmunition()-50);
                    int cash = inv.getCashAvailable()* 0.75;
                    inv.setCashAvailable(cash);
                    cout << endl << "YOU LOST THE BATTLE. " << endl << "-1/4 * CASH RESERVES" << endl << "-50 bullets" << endl;
                }
            }
            break;
            case 3://surrender
            {
                int cash = inv.getCashAvailable()* 0.75;
                inv.setCashAvailable(cash);
                cout << endl << "YOU ESCAPED BUT LOST 1/4 OF YOUR CASH RESERVES" << endl;
            }
            break;
            default: break;
        }
    printStatusUpdate();
    }
}
void Game::Hunt()
{
    d.setDay(d.getDay() + 1); // hunting takes one day so increase the day by one
 
    int randNum, option, animal;
    string s;

    randomNumGenerator(1,100); // generate random number to figure out what the animal will be
    randNum = getRandomNum();
   
    if (randNum >=1 && randNum <= 50){ // 50% chance it’s a rabbit = 5 lbs
       cout << "You got lucky! You have encountered a rabbit. Do you want to hunt?" << endl << "1. Yes     2. No" << endl;
       getline(cin, s);
       option = stoi (s);
       animal = 1;
       if (option != 2){ // if they choose to hunt
           choiceToHunt(animal);
       }
    } 
    if (randNum >=51 && randNum <= 75){ // 25 % chance it’s a fox = 10 lbs
       cout << "You got lucky! You have encountered a fox. Do you want to hunt?" << endl << "1. Yes     2. No" << endl;
       getline(cin, s);
       option = stoi (s);
       animal = 2;
       if (option != 2){ // if the choose to hunt
           choiceToHunt(animal);
       }

    } if (randNum >= 76 && randNum <= 88){ // 13 % chance it’s a deer = 60 lbs
       cout << "You got lucky! You have encountered a deer. Do you want to hunt?" << endl << "1. Yes     2. No" << endl;
       getline(cin, s);
       option = stoi (s);
       animal = 3;
       if (option != 2){ // if they choose to hunt
           choiceToHunt(animal);
       }
 
    } if (randNum >= 89 && randNum <= 95){ // 7% chance it’s bear = 200 lbs
       cout << "You got lucky! You have encountered a deer. Do you want to hunt?" << endl << "1. Yes     2. No" << endl;
       getline(cin, s);
       option = stoi (s);
       animal = 4;
       if (option != 2){ // if they choose to hunt
           choiceToHunt(animal);
       }
 
    } if (randNum >= 96 && randNum >= 100){ // 5% chance it’s a moose = 500 lbs
       cout << "You got lucky! You have encountered a moose. Do you want to hunt?" << endl << "1. Yes     2. No" << endl;
       getline(cin, s);
       option = stoi (s);
       animal = 5;
       if (option != 2){ // if they choose to hunt
           choiceToHunt(animal);
       }
    } 

   if (inv.getFoodRemaining() > 1000){// if the player has more than 1000 lbs of food
       inv.setFoodRemaining(1000);// set there food reaming to 1000
       cout << "You had to leave some food behind because the weight was going to break your wagon wheels." << endl; // cout statement
   }
//    if (inv.getFoodRemaining()<= 0){ // if they have no food left
//        cout << "You have no food left. Game Over." << endl; // end the game
//        // Add end game here
//    }
}
void Game::choiceToHunt(int animal)
{
    bool result;
    if(inv.getAmmunition() < 10){ // if they have less than 10 bullets
       cout << "Your hunting attempt was unsuccessful." << endl;
    } else {// if they have more than 10 bullets
       cout << "Complete this puzzle in order to secure the kill!" << endl;
       result = Puzzle(); // complete the puzzle
       if (result == true){ // if the successful completed if
           if (animal == 1){
               inv.setAmmunition(inv.getAmmunition() - 10); // subtract the ammunition needed for the bunny
               inv.setFoodRemaining(inv.getFoodRemaining() + 5); // add the food gained
           }
           if (animal == 2){
               inv.setAmmunition(inv.getAmmunition() - 8); // subtract the ammunition needed for the fox
               inv.setFoodRemaining(inv.getFoodRemaining() + 10); // add the food gained
           }
           if (animal == 3){
               inv.setAmmunition(inv.getAmmunition() - 5); // subtract the ammunition needed for the deer
               inv.setFoodRemaining(inv.getFoodRemaining() + 60); // add the food gained
           }
           if (animal == 4){
               inv.setAmmunition(inv.getAmmunition() - 10); // subtract the ammunition needed for the bear
               inv.setFoodRemaining(inv.getFoodRemaining() + 200); // add the food gained
           }
           if (animal == 5){
               inv.setAmmunition(inv.getAmmunition() - 12); // subtract the ammunition needed for the moose
               inv.setFoodRemaining(inv.getFoodRemaining() + 500); // add the food gained
           }
       } else if (result == false){
           cout << "Your hunt was unsuccessful. Better luck next time." << endl; // if they didn't complete the puzzle, display error message
       }
    }
    string y; 
    int foodConsumed;

    cout << endl << "Choose how much you and the rest of your party get to eat:" << endl;
    cout << "1. Poorly (2 lbs per person)" << endl << "2. Moderately (3 lbs per person)" << endl << "3. Well (5 lbs per person)" << endl;
    getline(cin, y);
    int option = stoi (y);

    if (option == 1){ 

        foodConsumed = p.getTotalTravelers() * 2; // total food consumed equals the number of people alive * 2 lbs
        inv.setFoodRemaining(inv.getFoodRemaining() - foodConsumed); // set the amount of food remaining to the food stored - what was eaten

    }
    else if (option == 2){
        foodConsumed = p.getTotalTravelers() * 3;// total food consumed equals the number of people alive * 3 lbs
        inv.setFoodRemaining(inv.getFoodRemaining() - foodConsumed); // set the amount of food remaining to the food stored - what was eaten
    }
    else if (option == 3){
        foodConsumed = p.getTotalTravelers() * 5; // total food consumed equals the number of people alive * 5 lbs
        inv.setFoodRemaining(inv.getFoodRemaining() - foodConsumed); // set the amount of food remaining to the food stored - what was eaten
    }
    else {
        cout << "Invalid input. Try again." << endl; // accounts for user error
    }
    cout << endl;
}
bool Game::Puzzle ()
{
    randomNumGenerator(1,10);//set the answer equal to a number between 1 and 10 (randomly generated)
    int answer = getRandomNum(); 
    cout << "Guess a number between 1 and 10. You have 3 tries so choose wisely!" << endl;
    for (int i = 1; i < 4; i++) // they have three tries to guess the number correctly
    {
        string s;
        getline(cin, s);
        int guess = stoi(s);
        if (guess == answer){ // if they guess correctly return true
            cout << "You guessed correctly!" << endl;
            return true;
        } else {
            cout << "Incorrect. You have " << 3-i << " tries remaining" << endl; // state how many tries they have left
        }
    }
    return false; // if they don't guess in time, return false
}
void Game::readMilestonesFile()//this function will read milestones.txt and store the values in a vector 
{
    ifstream milestoneFile;
    string line;
    string array[2];

    milestoneFile.open("milestones.txt");
    while(getline(milestoneFile, line, ','))//get the first line
    {
        array[0] = line;
        getline(milestoneFile, line); 
        array[1] = line;
        Landmark L(array[0], stoi(array[1]));
        landmarks.push_back(L);
    }
    Landmark L("Oregon City", 2400);
    landmarks.push_back(L); 
}
void Game::FinalStats()//reads results to results.txt and sorting algorithm
{
    // variables used!!!
    string line, username, resultSt;
    int max, indx, result;
    
    // vectors
    vector <int> resultNum;
    vector <string> resultUsername;
    vector <int> sortedNum;
    vector <string> sortedUsername;

    //score is how many resources you have left after successfully completing the game
    result = inv.getAmmunition() + inv.getFoodRemaining() + inv.getFoodRemaining() + inv.getMedicalKits() + inv.getOxen() + inv.getWagonParts();
    
    //READING TO RESULTS.TXT
    fstream resultsFile;
    resultsFile.open ("results.txt", ios :: app); // ios :: app writes to the end of the file so that it keeps its previous content
    resultsFile << p.getUsername() << " " << result << endl; // add the username and their score to the end of the file
    resultsFile.close(); // make sure to close the file
 
    //adding the user and their scores to vectors
    resultsFile.open("results.txt"); // open the file
    
    while (getline (resultsFile, line) && line != ""){ // while you can still get a line and the line isn't empty
        username = ""; // set the username to an empty string
        resultSt = ""; // set the result to an empty string
        for (int i = 0; i < line.length(); i++) // for the length of the line
        {
            if (isalpha(line[i]) || line[i] == ' ') // if the character is a letter or a space add it to the username
            {
                username = username + line [i];
            }
            else // if it was a number add it to the number string
            {
                resultSt = resultSt + line [i];
            }
        }
        resultNum.push_back(stoi(resultSt)); //add the score to the score vector 
        resultUsername.push_back(username); //add the username to the username vector
    }

    //SORTING ALGORITHM
    cout << "THE SORTED LIST: " << endl;

    for (int i = 0; i < resultNum.size(); i++) // for the number of elements in the vector
    {
        max = resultNum.at(0); // set the max equal to the first number in the vector
        indx = 0; // set the index = 0
    
        for (int j = 1; j < resultNum.size(); j++) // find the total max of the vector
        {
            if (resultNum.at(j) > max){
                max = resultNum.at(j);
                indx = j;
            }
        }
        sortedNum.push_back(resultNum.at(indx)); // add the number to the sorted vector
        sortedUsername.push_back(resultUsername.at(indx)); // add the corresponding username
        resultNum.at(indx) = 0; // set the number equal to 0 so that it can no longer be a max value
    }

    // print out the top 5
    cout << endl << "Top Five Scores: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". ";
        cout << sortedUsername.at(i) << " " << sortedNum.at(i) << endl;
    } 
}
bool Game::endGameCheck()//checks end game conditions
{
    //Conditions for ending game 
    if (inv.getFoodRemaining()<=0 || inv.getOxen()<=0)//run out of supplies
    {
        if (inv.getOxen()<=0)
        {
            cout << endl << "NO OXEN REMAINING. GAME OVER" << endl;
        }
        if (inv.getFoodRemaining() <= 0)
        {
            cout << endl << "NO FOOD REMAINING. GAME OVER" << endl;
        }
        return true;
    }
    if (d.getMonth() == 11 && d.getDay() == 30)//did not reach oregon cit by deadline
    {
        cout << "YOU DID NOT REACH OREGON BY 11/30" << endl; 
        return true;
    }
    if (getHealthAt(0) == 0)//if player 1 dies game ends
    {
        cout << endl << "UNFORTUNATELY YOU HAVE DIED. GAME OVER" << endl;
        return true;
    }
    else return false;
}
void Game::run()//all the function calls will be in here
{
    int option;
    string s;

    StartingInfo(); //prompt user for names and starting date
    readStoreInfo();//reading store info to the user 
    
    cout << "Would you like to visit the store? Y/N" << endl;
    getline(cin, s);
    while (s != "Y" && s != "N")
    {
        cout << "Invalid input. Please enter Y/N" << endl;
        getline(cin, s);
    }
    if (s == "Y")
    {
        printStoreMenu(); //prompt user to choose items from store menu to buy
    }

    printInventory();//prints quantity of all items in inventory

    readMilestonesFile();//read milestones file and store landmark/distance in a vector

    int count = 0;//count keeps track of the landmarks reached 
    bool result = endGameCheck();
    while (option != 5 && result != true) 
    {   
        //While user does not choose option quit continue prompting user to choose from menu
        //end game conditions: if either Misfortunes() or endGameConditions() returns true
        result = endGameCheck();
        if (result == true) {
            break;
        }
        printTurnsMenu(); 
        getline(cin, s);
        option = stoi(s);
        switch (option)
        {
            case 1: //continue on trail option
            {                               
                d.setDay(d.getDay() + 14);//setting date

                randomNumGenerator(70, 140);
                int totalMiles = getRandomNum() + m.getTotalMileage();//finding total miles traveled

                int landmarkDistance = landmarks[count].getLandmarkDistance(); 
                string landmarkName = landmarks[count].getLandmarkName();

                //LANDMARK CHECK 
                if (totalMiles < landmarkDistance) //total mileage has not surpassed landmark
                {    
                    m.setTotalMileage(totalMiles);
                    m.setDistanceRemaining(landmarkDistance- totalMiles);

                    int foodRemaining = inv.getFoodRemaining() - (p.getTotalTravelers() * 3 * 14);
                    inv.setFoodRemaining(foodRemaining);

                    //checking end conditions
                    result = endGameCheck();
                    if (result != true)
                    {
                        result = Misfortunes();//checks if wagon is broken
                        if (result != true)
                        RaiderAttack(); 
                    }
                }
                else if (totalMiles >= 2400)//they reached Oregon city
                {
                    result = true;
                    cout << endl << "CONGRAGULATIONS! YOU HAVE REACHED " << landmarks[15].getLandmarkName() << endl; break;
                }
                else //if total mileage exceeds that of the next milestone's distance
                {
                    cout << endl << "YOU WERE PREPARED TO TRAVEL: " << totalMiles << " miles" << endl
                    << "BUT YOU ARRIVED AT: " << landmarkName << endl
                    << "INSTEAD YOU TRAVELED: " << landmarkDistance << "miles" << endl;
                    m.setTotalMileage(landmarkDistance);
                    count++;//count increments so next landmark in vector is accessed
                    int distanceRemaining = (landmarks[count].getLandmarkDistance()-landmarkDistance);
                    m.setDistanceRemaining(distanceRemaining);

                    string input; 
                    int num = 0;
                    //forts are at indexes 2, 4, 7, 10, 12, 14 in the vector 
                    if (count == 2 || count == 4 || count == 7 || count == 10 || count == 12 || count == 14)
                    {
                        inv.setStorePercentIncrease(inv.getStorePercentIncrease() + 0.25);//price increases at each fort
                        cout << endl << "You have reached a fort. " << endl;
                        while(num != 3)//player does not choose to continue
                        {
                            cout << "Would you like to (1)rest (2)visit store (3) continue" << endl;
                            getline(cin,input);
                            num = stoi(input);
                            
                            if (num == 1)//rest
                            {
                                cout << endl << "You have chosen to rest." << endl;
                                randomNumGenerator(1, 3);
                                int daysRested = getRandomNum();//adding days stopped (randomly generated)
                                d.setDay(daysRested + d.getDay());

                                //subtracting food consumed
                                int foodRemaining = (inv.getFoodRemaining() - (p.getTotalTravelers()* 3 * daysRested));
                                inv.setFoodRemaining(foodRemaining);
                            }
                            else if (num == 2)//visit store
                            {
                                cout << endl << "You have chosen to shop." << endl;
                                printStoreMenu();
                            }
                            else if (num != 3)
                            {
                                cout << endl << "Invalid option. Try Again." << endl;
                            }
                            //end game check
                            result = endGameCheck();
                            if (result == true){
                                break;
                            }
                        }
                        //choose to continue
                        cout << endl << "You have chosen to continue on your journey." << endl;
                        printStatusUpdate();
                    }
                    else//not a fort
                    {
                        while (num != 2)//does not choose to continue
                        {
                            cout << endl << "Would you like to (1)rest (2) continue" << endl;
                            getline(cin, input);
                            num = stoi(input);
                            if (num == 1)//rest
                            {
                                cout << endl << "You have chosen to rest." << endl;
                                randomNumGenerator(1, 3);
                                int daysRested = getRandomNum();
                                d.setDay(daysRested + d.getDay());//adding days stopped (randomly generated)

                                //subtracting food consumed
                                int foodRemaining = (inv.getFoodRemaining() - (p.getTotalTravelers() * 3 * daysRested));
                                inv.setFoodRemaining(foodRemaining);
                            }
                            else if (num != 2)
                            {
                                cout << endl << "Invalid option. Try Again." << endl;
                            }
                            //end game check
                            result = endGameCheck();
                            if (result == true){
                                break;
                            }
                        }
                        //continue
                        cout << endl << "You have chosen to continue on your journey." << endl;
                        printStatusUpdate();
                    }
                }
            } break;

            case 2://stop to rest option
            { 
                //adding days stopped (randomly generated)
                randomNumGenerator(1, 3);
                int daysRested = getRandomNum();
                d.setDay(daysRested + d.getDay()); //new date after stopping to rest

                //subtracting food consumed
                int foodRemaining = inv.getFoodRemaining() - (p.getTotalTravelers() * 3 * daysRested); //entire party consumes 15 lbs per day
                inv.setFoodRemaining(foodRemaining);

                //checking end conditions
                result = endGameCheck();
                if (result != true)
                {
                    result = Misfortunes();//misfortunes checks if wagon is broken
                    if (result != true)
                    RaiderAttack(); 
                }
            } break;
            case 3: //hunt option
            {
                Hunt();

                //checking end conditions
                result = endGameCheck();
                if (result != true)
                {
                    result = Misfortunes();//misfortunes checks if wagon is broken
                    if (result != true)
                    RaiderAttack(); 
                }
            }  break;
            case 4://check inventory
            printInventory(); break; 
            case 5: cout << "GAME HAS ENDED" << endl; break;
            default: cout << "Invalid option. Enter a number btw 1-4" << endl;break;
        }
    }
    printStatusUpdate();
    FinalStats();//this will store results in results.txt 
}
