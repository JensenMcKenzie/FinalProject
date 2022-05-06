//
// Created by Jensen's PC on 5/5/2022.
//

#ifndef FINALPROJECT_DECK_H
#define FINALPROJECT_DECK_H

#include "Card.h"

class Deck {
private:
    //Array of 52 cards
    Card * deck[52];
    //The pointer towards the current card, used for dealing new cards
    int currentCard;
public:
    //Constructors and destructors
    Deck();
    ~Deck();

    //Custom methods
    void printDeck();
    void shuffleDeck();
    Card drawCard();
    Card getCardAtIndex(int);

    //Setters
    void setCurrentIndex(int);

    //Getters
    int getCurrentIndex();
};


#endif //FINALPROJECT_DECK_H
