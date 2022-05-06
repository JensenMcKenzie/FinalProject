//
// Dealer.cpp represents the dealer in a game of Blackjack, it is a child of the player class. This class contains the
// logic for when to hit, vs when to stay, as well as a way to check if we have busted. The dealer also has a method
// used to print its face up card to the human.
//

#include <iostream>
#include "Dealer.h"

//The constructor calls its parent constructor
Dealer::Dealer() : Player(){}

//Destructor
Dealer::~Dealer() {}

//Check if the dealer has bust or not
void Dealer::printAction() {
    //If the dealer's score is greater than 21, print that the dealer bust, and set the dealer's bust status to true
    if (count > 21){
        cout << "The dealer's count is " << count <<  ". The dealer busts! The player wins!" << endl << endl;
        isBust = true;
    }
}

//Returns true if the dealer must hit, false otherwise
bool Dealer::hit() {
    //Only hit if we have not bust
    if (!isBust) {
        //If we must hit, print this message, along with the count
        if (count < 17) {
            cout << "The dealer's count is " << count << ". The dealer must hit." << endl;
            //If we must stay, print this message, along with the count
        } else {
            cout << "The dealer's count is " << count << ". The dealer stands." << endl;
        }
    }
    //Return true if the count is less than 17, indicating the dealer will hit
    return count < 17;
}

//Prints the first card in the dealer's hand
void Dealer::printFirstCard() {
    //Print the first card in the dealer's hand
    cout << "The dealer is showing a " << hand[0] << ".\n\n";
}