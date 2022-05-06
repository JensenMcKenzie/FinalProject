//
// Created by Jensen's PC on 5/5/2022.
//

#ifndef FINALPROJECT_DEALER_H
#define FINALPROJECT_DEALER_H

#include "Player.h"

//************************************************
//*          REQUIREMENT A: Inheritance          *
//************************************************
class Dealer : public Player{
public:
    //Constructors and destructors
    Dealer();
    ~Dealer();

    //Custom methods
    //*************************************************
    //*          REQUIREMENT B: POLYMORPHISM          *
    //*************************************************
    void printAction();
    //*************************************************
    //*          REQUIREMENT B: POLYMORPHISM          *
    //*************************************************
    bool hit();
    void printFirstCard();
};


#endif //FINALPROJECT_DEALER_H
