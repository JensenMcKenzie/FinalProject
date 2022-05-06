//
// Human.cpp represents the human in a game of Blackjack, it is a child of the player class. This class will ask
// for user input for when to hit, and how much to bet. It also checks if the human has bust, and calculates and
// distributes bet payouts.
//

#include "Human.h"
#include <iostream>
#include <cmath>

//The constructor calls its parent constructor
Human::Human() : Player(){}

//Destructor
Human::~Human() {}

//Check if the human has bust or not
void Human::printAction() {
    //If the human's score is greater than 21, print that the human bust, and set the human's bust status to true
    if (count > 21){
        cout << "The player's count is " << count <<  ". The player busts! The dealer wins!" << endl << endl;
        isBust = true;
    }
}

//Returns true if the human wants to hit, false otherwise
bool Human::hit() {
    //Only hit if we have not bust
    if (!isBust){
        //Ask the human if they want to hit or stay
        cout << "Your current count is: " << count << ". Would you like to hit (h) or stand (s):";
        string choice;
        getline(cin, choice);
        //Ensure the user entered only one character, that is either 'h' or 's'
        if (choice.length() > 1 || (choice[0] != 'h' && choice[0] != 's')){
            //If input is not valid, throw an input mismatch exception
            throw InputMismatchException();
        }
        //If the user wants to hit, return true
        if (choice == "h"){
            return true;
            //If the user wants to stand, return false
        }else{
            return false;
        }
    }
    return false;
}

//Prompts the user to enter a bet amount, returns that amount
double Human::getBet() {
    //Prompt the user to enter a bet amount
    cout << "You currently have $" << money << ". How much would you like to bet:";
    string bet;
    getline(cin, bet);
    //Make sure each character is either a digit, or a period
    for (char c : bet){
        if (!isdigit(c) && c != '.'){
            //If a character is not a digit nor a period, throw an invalid bet exception
            throw InvalidBet();
        }
    }
    //If the bet contains a period
    if (bet.find('.') != string::npos){
        //If there are more than 2 characters after the decimal point
        if (bet.find('.') != bet.length()-2 && bet.find('.') != bet.length()-3){
            //If there are more than 2 characters after the decimal point, throw an invalid bet exception
            throw InvalidBet();
        }
    }
    if (stod(bet) > money || stod(bet) < 0){
        //If the user tries to bet more money than they have, or negative money, throw an invalid bet exception
        throw InvalidBet();
    }
    //Print how much was bet, and return that amount
    cout << "You have bet $" << bet << ".\n\n";
    return stod(bet);
}

//Payout calculates the payout of a given win situation
void Human::payout(bool win, double bet) {
    //If the human won
    if (win){
        //Print how much was bet and the new total, and add it to the human's money
        cout << "The player won with their bet of $" << bet << ". Their new balance is $" << money + (ceil((bet*.5) * 100.0)/100.0) << ".\n\n";
        money += ceil((bet*.5) * 100.0)/100.0;
        //If the human lost
    }else{
        //Print how much was lost
        cout << "The player lost their bet of $" << bet << ".";
        //Pity system, if the human lost all or most of their money, reset their money to 5
        if (money - bet < 5) {
            cout << "\nPITY SYSTEM\nYou lost all or most of your money. Your money has been reset to $5\n\n";
            money = 5;
        }else{
            //Print the new balance, and subtract their bet from their money
            cout << " Their new balance is $" << money - bet << ".\n\n";
            money -= bet;
        }
    }
}

//Setters : uses the passed parameter to set the appropriate data member
void Human::setMoney(double money) {
    this->money = money;
}

//Getters : returns the appropriate data member
double Human::getMoney() {
    return money;
}