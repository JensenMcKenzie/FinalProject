//
// Card.cpp is used to store various cards in a deck, each with its own value (1 or 11 for ace, 2 for 2, 10 for face
// value, ect.), suit, and faceValue
//

#include "Card.h"

//Constructor with vale, suit, and faceValue
Card::Card(int value, string suit, int faceValue) {
    this->value = value;
    this->suit = suit;
    this->faceValue = faceValue;
}

//Destructor
Card::~Card() {}

//Setters : uses the passed parameter to set the appropriate data member
void Card::setValue(int value) {
    this->value = value;
}

void Card::setSuit(string suit) {
    this->suit = suit;
}

void Card::setFaceValue(int faceValue) {
    this->faceValue = faceValue;
}

//Getters : returns the appropriate data member
int Card::getValue() {
    return value;
}

string Card::getSuit() {
    return suit;
}

int Card::getFaceValue() {
    return faceValue;
}

//Overloaded << (print) operator
ostream  & operator<<(ostream &out, const Card & c){
    //Convert the face value of each cart into its name (13 -> K, 1 -> A, 2 -> 2, ect.)
    //Print the name of the card, and its suit
    if (c.faceValue == 1){
        out << "A " + c.suit;
    }
    else if (c.faceValue == 11){
        out << "J " + c.suit;
    }
    else if (c.faceValue == 12){
        out << "Q " + c.suit;
    }
    else if (c.faceValue == 13){
        out << "K " + c.suit;
    }
    else{
        out << to_string(c.faceValue) + " " + c.suit;
    }
    return out;
}