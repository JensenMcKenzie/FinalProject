//
// Created by Jensen's PC on 5/5/2022.
//

#ifndef FINALPROJECT_CARD_H
#define FINALPROJECT_CARD_H

#include <string>
using namespace std;

class Card {
private:
    //Stores the point value of a card, as well as its face value
    int faceValue, value;
    //Stores the suit of a card
    string suit;
public:
    //Constructors and destructors
    Card(int, string, int);
    ~Card();

    //Setters
    void setFaceValue(int);
    void setSuit(string);
    void setValue(int);


    //Getters
    int getFaceValue();
    string getSuit();
    int getValue();

    //Overloaded operators
    friend ostream &operator<<(ostream &, const Card &);
};


#endif //FINALPROJECT_CARD_H
