//
// Created by Jensen's PC on 5/5/2022.
//

#ifndef FINALPROJECT_PLAYER_H
#define FINALPROJECT_PLAYER_H

#include <vector>
#include "Card.h"

//***************************************************
//*          REQUIREMENT F: ABSTRACT CLASS          *
//***************************************************
class Player {
protected:
    //The current count of all the cards in a player's hand
    int count;
    //The current hand of a player
    vector<Card> hand;
    //The bust status of a player, true means the player has bust
    bool isBust;
public:
    //Constructors and destructors
    Player();
    ~Player();

    //Pure virtual functions
    virtual void printAction() = 0;
    virtual bool hit() = 0;

    //Custom methods
    void deal(Card);
    void resetHand(Card, Card);
    void resetHand(Card);
    void printHand();

    //Setters
    void setCount(int);
    void setIsBust(bool);

    //Getters
    int getCount();
    bool getIsBust();
};

#endif //FINALPROJECT_PLAYER_H
