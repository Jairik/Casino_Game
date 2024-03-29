//JJ McCauley- card.h

#include <iostream>
#ifndef CARD_H
#define CARD_H
const char spade[4] = "\xe2\x99\xa0"; //unicode character for spade
const char club[4] = "\xe2\x99\xa3"; //unicode character for club
const char heart[4] = "\xe2\x99\xa5"; //unicode character for heart
const char diamond[4] = "\xe2\x99\xa6"; //unicode character for diamond

class card {
	public:
		struct ACard{
                        int num;
                        char pic[4]; //will store unicode character for card type
                };
		ACard Cards[52]; //an array to store all the cards
                int nextCard = 0; //an index for the next available card
		card(); //will initialize with all cards in the deck
		void shuffleCard(); //will shuffle the cards in the deck prior to each game
		ACard getCard(); //will return the next available card from the deck
		//14 void functions to display each card
		void cardBlank (const char [4], int);
		void cardAce(const char [4], int);
                void cardTwo(const char [4], int);
                void cardThree(const char [4], int);
                void cardFour(const char [4], int);
                void cardFive(const char [4], int);
                void cardSix(const char [4], int);
                void cardSeven(const char [4], int);
                void cardEight(const char [4], int);
                void cardNine(const char [4], int);
                void cardTen(const char [4], int);
                void cardJack(const char [4], int);
                void cardQueen(const char [4], int);
                void cardKing(const char [4], int);
		void displayHand(int, ACard []);
};

#endif
