//JJ McCauley - poker.h

#include <iostream>
#include "card.h"

#ifndef POKER_H
#define POKER_H

class poker: public card {
	private:
		const int pHandSize = 5; //constant hand size in a poker game
		int initBalance; //initial balance put into the Poker game
		int currentBalance; //will hold the current balance won by the player
		int betAmount; //will hold how much the player wants to bet during each game. -1 is signal value to quit the game
		card::ACard pokerHand[5];
		void sortHand(); //Will sort the hand based on poker rules, implented to assist in getWinAmount();
                void cardSelection(); //displays each card and asks user if they would like to draw or hold. if parameter is "T", wil allow the user to select their own cards for testing purposes
                int getWinAmount(); //calls helper functions to set win amount after each game. Returns multipler to the original bet amount
                void displayWinnings(int); //prints the initial, current, and winning balance to the screen
                void setInitAmount(); //displays a message and return initBalance
                void setBetAmount(); //display a message and return amount user wants to bet
                void endProgMessage(); //displays a player's current totals before exiting the game
                //The following functions check if the win conditions are met, returning true if they are
                bool jackOrBetter();
                bool twoPair();
                bool triple();
                bool straight();
                bool flush();
                bool fullHouse();
                bool fourCard();
                bool straightFlush();
                bool royalStraightFlush();
                void printAsciiArt();
	public:
		poker(); //constructor to make new poker game
		void playerTurn(); //Will call appropraite functions to execute a player's turn. Used to clean main. Takes in a char, which determines if the current game isin test mode
};

#endif
