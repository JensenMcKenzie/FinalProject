//
// Created by Jensen's PC on 5/5/2022.
//

#ifndef FINALPROJECT_HUMAN_H
#define FINALPROJECT_HUMAN_H

#include "Player.h"

//************************************************
//*          REQUIREMENT A: Inheritance          *
//************************************************
class Human : public Player{
private:
    //Storage for the human's money used in betting
    double money;
public:
    //Custom exception classes
    //***********************************************
    //*          REQUIREMENT E: Exceptions          *
    //***********************************************
    //InputMismatchException, called when input is not valid
    class InputMismatchException : public exception
    {
        virtual const char* what() const throw()
        {
            return "Invalid input. Please try again.";
        }
    };

    //***********************************************
    //*          REQUIREMENT E: Exceptions          *
    //***********************************************
    //InvalidBet, called when bet input is not valid
    class InvalidBet : public exception
    {
        virtual const char* what() const throw()
        {
            return "Invalid bet. Please try again.";
        }
    };

    //Constructors and destructors
    Human();
    ~Human();

    //Custom methods
    //*************************************************
    //*          REQUIREMENT B: POLYMORPHISM          *
    //*************************************************
    void printAction();
    //*************************************************
    //*          REQUIREMENT B: POLYMORPHISM          *
    //*************************************************
    bool hit();
    double getBet();
    void payout(bool, double);

    //Setters
    void setMoney(double);

    //Getters
    double getMoney();
};


#endif //FINALPROJECT_HUMAN_H
