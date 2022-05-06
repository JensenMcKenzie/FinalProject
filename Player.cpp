//
// Player is an abstract class meant to be derived from. It handles the player's hand, including dealing new cards, and
// resetting hand. It also stores a player's busts status, their count, and ace logic (when to choose 1 or 11)
//

#include "Player.h"
#include <iostream>

//Constructor initializes bust to false, and the count to 0
Player::Player() {
    isBust = false;
    count = 0;
}

//Destructor
Player::~Player(){};

//Clears the hand and deals it 2 new cards
void Player::resetHand(Card one, Card two) {
    //Clear the player's hand
    hand.clear();
    //Set bust to false
    isBust = false;
    //Set the count to 0
    count = 0;
    //Deal the two provided cards to the player
    deal(one);
    deal(two);
}

//Clears a hand and deals it 1 new card
void Player::resetHand(Card one) {
    //Clear the player's hand
    hand.clear();
    //Set bust to false
    isBust = false;
    //Set the count to 0
    count = 0;
    //Deal the provided card to the player
    deal(one);
}

//Prints the current hand
void Player::printHand() {
    cout << "Hand:" << endl;
    //Loop through each card in the hand, printing each one on a new line
    for (int i = 0; i < hand.size(); i++){
        cout << hand[i] << endl;
    }
    cout << endl;
}

//Deals the provided card to the player, handling ace logic
void Player::deal(Card card) {
    //Add the card's value to the count
    count += card.getValue();
    //Add the card to the hand
    hand.push_back(card);
    bool done = false;
    //Loop until there are no more aces to change in the hand, if our count is greater than 21
    while(count > 21 && !done) {
        //Set done to true
        done = true;
        //Loop through the player's hand
        for (int i = 0; i < hand.size(); i++) {
            //If we come across an ace with a value of 11, change it to 1, and break the loop
            if (hand[i].getValue() == 11) {
                hand[i].setValue(1);
                //Update the count to reflect an ace with a value of 1, instead of 11
                count -= 10;
                done = false;
                break;
            }
        }
    }
    //When new cards are drawn, print the following message
    if (hand.size() > 2)
        cout << "\nThe card " << card << " is drawn." << endl << endl;
    //Print the player's hand each turn
    if (hand.size() >= 2)
        printHand();
}

//Setters : uses the passed parameter to set the appropriate data member
void Player::setCount(int count) {
    this->count = count;
}

void Player::setIsBust(bool isBust) {
    this->isBust = isBust;
}

//Getters : returns the appropriate data member
int Player::getCount() {
    return count;
}

bool Player::getIsBust() {
    return isBust;
}