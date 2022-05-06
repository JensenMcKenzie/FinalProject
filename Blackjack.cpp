/*
BlackJack.cpp -
Author: Jensen McKenzie
Module: FINAL PROJECT
Project: FINAL PROJECT
Problem Statement: Create the game Blackjack, with a player and dealer.

Algorithm/Plan:
  1. Open the userData file, and store the numbers on the first line as the player and dealer's scores, respectively
  2. Loop until the player wants to stop playing
   2a. Shuffle the deck, and ask the human for their bet, catching any InvalidBet exceptions.
   2b. Deal the cards, printing the player's hand, and the one card the dealer is showing.
   2c. Loop until the player busts or stands
    2ca. Ask the human if they would like to hit or stand
     2caa. If they hit, deal the human a new card, and print their new hand. Also print the one card the dealer is showing.
     2cab. Calculate the player's new score, if greater than 21, they bust, and the dealer wins, take the player's bet.
    2cd. If the player stands, print nothing.
   2d. If the human did not bust, play as the dealer, who will hit until his total is greater than or equal to 17.
    2da. Instead of asking for input, print the dealer's decisions. If their total is less than 17, the dealer must hit.
    If not, they must stand.
   2f. If the dealer busts, the player wins, pay out their bet.
   2g. If neither the player nor the dealer busts, check their scores.
    2ga. If the scores are equal, there is a push, bets are returned and scores stay the same.
    2gb. If the player has a greater score, the player wins. Pay out their bet.
    2gc. If the dealer has a greater score, the dealer wins. Take the player's bet.
   2h. Print the new scoreboard.
   2i. Ask the user if they want to play again, ensuring their input is valid.
  3. Print the new scoreboard to the first line of the file.
  4. Print the user's money to the second line of the file.
  5. Close the file, and close the application.
*/

#include <iostream>
#include <fstream>
#include "Deck.h"
#include "Dealer.h"
#include "Human.h"

using namespace std;

int main() {
    //Variables for the deck, the human player, and the dealer player
    Deck deck;
    Human human;
    Dealer dealer;

    //**************************************************
    //*          REQUIREMENT C: TEXT FILE I/O          *
    //**************************************************
    //Open the input file
    ifstream inFile;
    inFile.open("userData.txt");
    string line;

    //Read the first line of the userData file, storing the first number before the colon in playerScore, and the number
    //after the colon in dealerScore
    getline(inFile, line);
    int playerScore = stoi(line.substr(0, line.find(":")));
    int dealerScore = stoi(line.substr(line.find(":")+1, line.size()-1));

    //Read the second line of the userData file, storing the double in the human's money
    getline(inFile, line);
    human.setMoney(stod(line));
    //Close the input file
    inFile.close();

    //Storage for user response to play again question
    string replay;
    //Print the current scoreboard
    cout << "The player's running score is " << playerScore << ". The dealer's running score is " << dealerScore << ".\n\n";

    //Loop until the user does not want to play anymore
    while (replay != "n") {
        //Shuffle the deck
        deck.shuffleDeck();

        //Variable to store the current bet
        double bet;

        //Variable to store the validity of various inputs
        bool valid = false;
        //Loop until the input is considered valid
        while(!valid) {
            //Set valid to true
            valid = true;
            try {
                //Ask the human for their bet
                bet = human.getBet();

                //***********************************************
                //*          REQUIREMENT E: Exceptions          *
                //***********************************************
            } catch (exception &e) {
                //If an InvalidBet exception is thrown, set valid to false, and print the error
                valid = false;
                cout << endl << e.what() << endl << endl;
            }
        }

        //Deal 2 cards to the human
        cout << "PLAYERS'S TURN" << endl;
        human.resetHand(deck.drawCard(), deck.drawCard());
        //Deal 1 card to the dealer, so we can see what their face up card is. Their second card will be dealt later
        dealer.resetHand(deck.drawCard());
        //Print the dealer's first card
        dealer.printFirstCard();

        //Reset the input validity variable
        valid = false;
        //Loop until input is considered valid
        while (!valid) {
            //Set valid to true
            valid = true;
            try {
                //Loop until the human elects to stand
                while (human.hit()) {
                    //Deal a new card
                    human.deal(deck.drawCard());
                    //Print the first card of the dealer
                    dealer.printFirstCard();
                    //See if the human has bust
                    human.printAction();
                }

                //***********************************************
                //*          REQUIREMENT E: Exceptions          *
                //***********************************************
            } catch (exception &e) {
                //If an InputMismatchException is thrown, set valid to false, and print the error
                valid = false;
                cout << e.what() << endl << endl;
            }
        }

        //Only loop through dealer logic if the player has not bust
        if (!human.getIsBust()) {
            cout << "\nDEALER'S TURN" << endl;
            //Deal the dealer their 2nd card
            dealer.deal(deck.drawCard());

            //Loop until the dealer busts or stands
            while (dealer.hit()) {
                //Deal a new card
                dealer.deal(deck.drawCard());
                //See if the dealer has bust
                dealer.printAction();
            }

            //If the dealer did not bust, compare scores between the player and the dealer
            if (!dealer.getIsBust()) {
                //If the scores are equal
                if (human.getCount() == dealer.getCount()) {
                    //Do not increment either score count, and do not change the player's money
                    cout << "\nThe counts are equal. The player and dealer push! Bet has been returned to the player."
                         << endl << endl;
                }
                //If the human has a greater score
                else if (human.getCount() > dealer.getCount()) {
                    //Increment the player's score
                    playerScore++;
                    //Print the final counts
                    cout << "\nThe player wins with a count of " << human.getCount()
                         << ", against the dealer's count of " << dealer.getCount() << "." << endl << endl;
                    //Calculate the human's bet payout, passing in true since the human won the game
                    human.payout(true, bet);
                }
                else if (human.getCount() < dealer.getCount()) {
                    //Increment the dealer's score
                    dealerScore++;
                    //Print the final counts
                    cout << "\nThe dealer wins with a count of " << dealer.getCount()
                         << ", against the player's count of " << human.getCount() << "." << endl << endl;
                    //Calculate the human's bet payout, passing in false since the human lost the game
                    human.payout(false, bet);
                }
                //If the dealer busts during their turn
            } else {
                //Increment the player's score
                playerScore++;
                //Calculate the human's bet payout, passing in true since the human won the game
                human.payout(true, bet);
            }
            //If the player busts during their turn
        } else {
            //Increment the dealer's score
            dealerScore++;
            //Calculate the human's bet payout, passing in false since the human lost the game
            human.payout(false, bet);
        }

        //Print the new scoreboard
        cout << "The player's new score is " << playerScore << ". The dealer's new score is " << dealerScore << ".\n\n";

        //Reset the input validity variable
        valid = false;
        //Loop until input is considered valid
        while (!valid) {
            //Set valid to true
            valid = true;
            cout << "Would you like to play again (y for yes, n for no):";
            getline(cin, replay);
            //Ensure the user entered only one character, that is either 'y' or 'n'
            if (replay.length() > 1 || (replay != "y" && replay != "n")){
                //Print an error message if the input is invalid, and set the validity to false
                cout << "Invalid input. Please try again." << endl << endl;
                valid = false;
            }
        }
    }

    //**************************************************
    //*          REQUIREMENT C: TEXT FILE I/O          *
    //**************************************************
    //Once the user is done playing, open the output file
    ofstream outFile;
    outFile.open("userData.txt");
    //Write the player score and the dealer score, separated by a :, to the first line. Write the player's money to the
    //second line
    outFile << to_string(playerScore) + ":" + to_string(dealerScore) << endl << to_string(human.getMoney());
    //Close the output file
    outFile.close();

    //Print a final success message, and exit the application
    cout << "Scores saved. Exiting application.";
    return 1;
}
