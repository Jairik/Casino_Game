//JJ McCauley - blackjack.h
#include <iostream>
#include "card.h"

#ifndef BLACKJACK_H
#define BLACKJACK_H
class blackjack: public card {
	private:
		ACard playerHand[20]; //store all of the player's cards
		ACard dealerHand[20]; //store all of the dealer's cards
		int playerHandSize; //current card count for player
		int dealerHandSize; //current card count for dealer
		int playerHandTotal; //will act as a running total for the value of the player's hand
		int dealerHandTotal; //will act as a running total for the value of the dealer's hand
		int betAmount; //will hold the bet amount
		int seedMoney; //initial balance that the player has
		int winAmount; 
		int currentBalance; //current remaining balance
		void drawCard(char); //will draw a new card, add it to the hand, and make neccessary changes to adhere to blackjack rules.
	public:
		blackjack(); //constructor that draws the first two cards
		void playBlackjack(); //Will act as a hub that calls all functions
		void setBet(); //will set the bet amount
		void insurance(); //will offer the user insurance
		bool checkForBust(ACard *, int); //Will return true if the given hand has a bust
		bool dealerDrawCard(); //will return true if the dealer hand value is less than 17
		bool setupHands(); //utility function to clean playBlackjack function
		bool playAgain(); //Asks the user if they want to play again and validates the data
		void displayWinnings(); //Will print initial, final, and winnings to the screen
		void printAsciiArt(); //Prints the ascii art found in the welcome message

};
#endif
