//
// Deck.cpp is used to hold and create a full deck of 52 cards. It can also deal cards, print the deck, and be shuffled.
//

#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include "Deck.h"

//Empty constructor
Deck::Deck(){
    //Set the currentCard counter to 0
    currentCard = 0;
    //Loop through each possible card value
    for (int val = 1; val <= 13; val++){
        //Loop through each possible card suit
        for (int i = 1; i <= 4; i++){
            //String for the current suit
            string suit;
            //Set the suit string to the appropriate value based on the value of i
            if (i == 1){
                suit = "of clubs";
            }
            else if (i == 2){
                suit = "of spades";
            }
            else if (i == 3){
                suit = "of hearts";
            }
            else{
                suit = "of diamonds";
            }
            //Int for the current value
            int value;
            //Set aces to a value of 11 by default
            if (val == 1){
                value = 11;
            }
            //Set all face card's value to 10
            else if (val > 10){
                value = 10;
            }
            //Set all other cards value to its face value
            else{
                value = val;
            }
            //Add a new card to the deck, at the current position
            deck[currentCard++] = new Card(value, suit, val);
        }
    }
}

//Prints all cards in the deck
void Deck::printDeck() {
    //Loop through each card in the deck
    for (int i = 0; i <= 51; i++){
        //Print each card, separated by a space
        cout << *deck[i] << " ";
    }
    cout << endl << endl;
}

//Destructor
Deck::~Deck() {
    //Delete the deck pointer
    delete * deck;
}

//Shuffles the deck randomly
void Deck::shuffleDeck() {
    //Reset the currentCard counter to the top of the deck
    currentCard = 52;
    //Shuffle the deck, from beginning to end, seeded with the time
    shuffle(begin(deck), end(deck), default_random_engine(time(0)));
}

//Returns a card from the deck
Card Deck::drawCard() {
    //Return the next card that has not been drawn, decrement the currentCard counter
    return * deck[--currentCard];
}

//Returns a card at a certain index
Card Deck::getCardAtIndex(int index) {
    //Check the passed index for validity
    if (index >= 0 && index < 52){
        //Return the card at the index
        return *deck[index];
    }
    return Card(0, "", 0);
}

//Setters : uses the passed parameter to set the appropriate data member
void Deck::setCurrentIndex(int currentCard) {
    this->currentCard = currentCard;
}


//Getters : returns the appropriate data member
int Deck::getCurrentIndex() {
    return currentCard;
}