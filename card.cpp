//JJ McCauley- card.cpp

#include <iostream> //for printing cards
#include <ctime> //will seed random number generator
#include <cstdlib> //for random number generator
#include "card.h" //header file

//Initialize the card deck (in order)
card::card() {
	for (int i = 0; i < 52; i++) {
		Cards[i].num = (i%13)+1;
		if (i < 13) {
			for(int j = 0; j < 4; j++) {
				Cards[i].pic[j] = spade[j];
			}
		}
		else if (i < 26) {
			for(int j = 0; j < 4; j++) {
                                Cards[i].pic[j] = club[j];
                        }
		}
		else if (i < 39) {
			for(int j = 0; j < 4; j++) {
				Cards[i].pic[j] = heart[j];
			}
		}
		else {
			for(int j = 0; j < 4; j++) {
				Cards[i].pic[j] = diamond[j];
			}
		}		
	}
}

//Will shuffle the card deck by swapping every card in the array with a random card (index)
void card::shuffleCard() {
	int rNum;
	ACard temp; //temporary card we will use to swap
	srand(time(0));
	srand((unsigned)time(NULL));
	for(int i = 0; i < 52; i++) {
		rNum = rand()%52;
		if(rNum != i) {
			//swap 
			temp = Cards[i];
			Cards[i] = Cards[rNum];
			Cards[rNum] = temp;
		}
	}
	nextCard = 0;
}

//Will return the next available card in the deck, changing nextCard accordingly
card::ACard card::getCard() {
	return Cards[nextCard++];
}

//Will call the appropriate function to print the given card
void card::displayHand(int numCards, ACard *tempHand) {
	for (int t = 0; t < 11; t++) { //will iterate through each row
		for (int i = 0; i < numCards; i++) { //will print the row for each card
			int cNum = tempHand[i].num; //current number card (for easier comparison)
			if (cNum == 0) {
				cardBlank(tempHand[i].pic, t);
			}
			else if(cNum == 1) {
				cardAce(tempHand[i].pic, t);
			}
			else if (cNum == 2) {
				cardTwo(tempHand[i].pic, t);
			}
			else if (cNum == 3) {
		       	        cardThree(tempHand[i].pic, t);
		        }
		        else if (cNum == 4) {
		                cardFour(tempHand[i].pic, t);
		        }
		        else if (cNum == 5) {
		                cardFive(tempHand[i].pic, t);
		        }
		        else if (cNum == 6) {
		                cardSix(tempHand[i].pic, t);
		        }
		        else if (cNum == 7) {
		                cardSeven(tempHand[i].pic, t);
		        }
		        else if (cNum == 8) {
		                cardEight(tempHand[i].pic, t);
		        }
		        else if (cNum == 9) {
		                cardNine(tempHand[i].pic, t);
		        }
		        else if (cNum == 10) {
		                cardTen(tempHand[i].pic, t);
		        }
		        else if (cNum == 11) {
		                cardJack(tempHand[i].pic, t);
		        }
		        else if (cNum == 12) {
		                cardQueen(tempHand[i].pic, t);
		        }
			else {
		                cardKing(tempHand[i].pic, t);
		        }
		}
		std::cout << "\n"; //make new line
	}	
}



//Below are all of the print card functions
void card::cardBlank(const char symbol[], int i) {
        if (i == 0) {
                std::cout << "---------";
        }
        else if (i == 1) {
                std::cout << "|       |";
        }
        else if (i == 2) {
                std::cout << "|       |";
        }
        else if (i == 3) {
                std::cout << "|       |";
        }
        else if (i == 4) {
                std::cout << "|       |";
        }
        else if (i == 5) {
                std::cout << "|   ?   |";
        }
        else if (i == 6) {
                std::cout << "|       |";
        }
        else if (i == 7) {
                std::cout << "|       |";
        }
        else if (i == 8) {
                std::cout << "|       |";
        }
        else if (i == 9) {
                std::cout << "|       |";
        }
        else {
                std::cout << "---------";
        }
}

void card::cardAce(const char symbol[], int i) {
	if (i == 0) {
		std::cout << "---------";
	}
	else if (i == 1) {
		std::cout << "|A      |";
	}
	else if (i == 2) {
		std::cout << "|       |";
	}
	else if (i == 3) {
		std::cout << "|       |";
	}
	else if (i == 4) {
		std::cout << "|       |";
	}
	else if (i == 5) {
		std::cout << "|   " << symbol << "   |";
	}
	else if (i == 6) {
		std::cout << "|       |";
	}
	else if (i == 7) {
                std::cout << "|       |";
        }
	else if (i == 8) {
                std::cout << "|       |";
        }
	else if (i == 9) {
                std::cout << "|      A|";
        }
	else {
		std::cout << "---------";	
	}
}

void card::cardTwo(const char symbol[], int i) {
        if (i == 0) {
                std::cout << "---------";
        }
        else if (i == 1) {
                std::cout << "|2      |";
        }
        else if (i == 2) {
                std::cout << "|       |";
        }
        else if (i == 3) {
                std::cout << "|   " << symbol << "   |";
        }
        else if (i == 4) {
                std::cout << "|       |";
        }
        else if (i == 5) {
                std::cout << "|       |";
        }
        else if (i == 6) {
                std::cout << "|       |";
        }
        else if (i == 7) {
                std::cout << "|       |";
        }
        else if (i == 8) {
                std::cout << "|   " << symbol << "   |";
        }
        else if (i == 9) {
                std::cout << "|      2|";
        }
        else {
                std::cout << "---------";
        }
}

void card::cardThree(const char symbol[], int i) {
        if (i == 0) {
                std::cout << "---------";
        }
        else if (i == 1) {
                std::cout << "|3      |";
        }
        else if (i == 2) {
                std::cout << "|   " << symbol << "   |";
        }
        else if (i == 3) {
                std::cout << "|       |";
        }
        else if (i == 4) {
                std::cout << "|       |";
        }
        else if (i == 5) {
                std::cout << "|   " << symbol << "   |";
        }
        else if (i == 6) {
                std::cout << "|       |";
        }
        else if (i == 7) {
                std::cout << "|       |";
        }
        else if (i == 8) {
                std::cout << "|   " << symbol << "   |";
        }
        else if (i == 9) {
                std::cout << "|      3|";
        }
        else {
                std::cout << "---------";
        }
}

void card::cardFour(const char symbol[], int i) {
        if (i == 0) {
                std::cout << "---------";
        }
        else if (i == 1) {
                std::cout << "|4      |";
        }
        else if (i == 2) {
                std::cout << "| " << symbol << "   " << symbol << " |";
        }
        else if (i == 3) {
                std::cout << "|       |";
        }
        else if (i == 4) {
                std::cout << "|       |";
        }
        else if (i == 5) {
                std::cout << "|       |";
        }
        else if (i == 6) {
                std::cout << "|       |";
        }
        else if (i == 7) {
                std::cout << "|       |";
        }
        else if (i == 8) {
                std::cout << "| " << symbol << "   " << symbol << " |";
        }
        else if (i == 9) {
                std::cout << "|      4|";
        }
        else {
                std::cout << "---------";
        }
}

void card::cardFive(const char symbol[], int i) {
        if (i == 0) {
                std::cout << "---------";
        }
        else if (i == 1) {
                std::cout << "|5      |";
        }
        else if (i == 2) {
                std::cout << "| " << symbol << "   " << symbol << " |";
        }
        else if (i == 3) {
                std::cout << "|       |";
        }
        else if (i == 4) {
                std::cout << "|       |";
        }
        else if (i == 5) {
                std::cout << "|   " << symbol << "   |";
        }
        else if (i == 6) {
                std::cout << "|       |";
        }
        else if (i == 7) {
                std::cout << "|       |";
        }
        else if (i == 8) {
                std::cout << "| " << symbol << "   " << symbol << " |";
        }
        else if (i == 9) {
                std::cout << "|      5|";
        }
        else {
                std::cout << "---------";
        }
}

void card::cardSix(const char symbol[], int i) {
        if (i == 0) {
                std::cout << "---------";
        }
        else if (i == 1) {
                std::cout << "|6      |";
        }
        else if (i == 2) {
                std::cout << "| " << symbol << "   " << symbol << " |";
        }
        else if (i == 3) {
                std::cout << "|       |";
        }
        else if (i == 4) {
                std::cout << "|       |";
        }
        else if (i == 5) {
                std::cout << "| " << symbol  << "   " << symbol << " |";
        }
        else if (i == 6) {
                std::cout << "|       |";
        }
        else if (i == 7) {
                std::cout << "|       |";
        }
        else if (i == 8) {
                std::cout << "| " << symbol << "   " << symbol << " |";
        }
        else if (i == 9) {
                std::cout << "|      6|";
        }
        else {
                std::cout << "---------";
        }
}

void card::cardSeven(const char symbol[], int i) {
        if (i == 0) {
                std::cout << "---------";
        }
        else if (i == 1) {
                std::cout << "|7      |";
        }
        else if (i == 2) {
                std::cout << "| " << symbol << "   " << symbol << " |";
        }
        else if (i == 3) {
                std::cout << "|   " << symbol << "   |";
        }
        else if (i == 4) {
                std::cout << "|       |";
        }
        else if (i == 5) {
                std::cout << "| " << symbol  << "   " << symbol << " |";
        }
        else if (i == 6) {
                std::cout << "|       |";
        }
        else if (i == 7) {
                std::cout << "|       |";
        }
        else if (i == 8) {
                std::cout << "| " << symbol << "   " << symbol << " |";
        }
        else if (i == 9) {
                std::cout << "|      7|";
        }
        else {
                std::cout << "---------";
        }
}

void card::cardEight(const char symbol[], int i) {
        if (i == 0) {
                std::cout << "---------";
        }
        else if (i == 1) {
                std::cout << "|8      |";
        }
        else if (i == 2) {
                std::cout << "| " << symbol << "   " << symbol << " |";
        }
        else if (i == 3) {
                std::cout << "|   " << symbol << "   |";
        }
        else if (i == 4) {
                std::cout << "|       |";
        }
        else if (i == 5) {
                std::cout << "| " << symbol  << "   " << symbol << " |";
        }
        else if (i == 6) {
                std::cout << "|       |";
        }
        else if (i == 7) {
                std::cout << "|   " << symbol << "   |";
        }
        else if (i == 8) {
                std::cout << "| " << symbol << "   " << symbol << " |";
        }
        else if (i == 9) {
                std::cout << "|      8|";
        }
        else {
                std::cout << "---------";
        }
}

void card::cardNine(const char symbol[], int i) {
	if (i == 0) {
		std::cout << "---------";
	}
	else if (i == 1) {
                std::cout << "|9      |";
        }
        else if (i == 2) {
                std::cout << "| " << symbol << "   " << symbol << " |";
        }
        else if (i == 3) {
                std::cout << "|   " << symbol <<  "   |";
        }
        else if (i == 4) {
                std::cout << "| " << symbol << "   " << symbol << " |";
        }
        else if (i == 5) {
                std::cout << "|       |";
        }
        else if (i == 6) {
                std::cout << "| " << symbol << "   " << symbol << " |";
        }
        else if (i == 7) {
                std::cout << "|       |";
        }
        else if (i == 8) {
                std::cout << "| " << symbol << "   " << symbol << " |";
        }
        else if (i == 9) {
                std::cout << "|      9|";
        }
        else {
                std::cout << "---------";
        }
}

void card::cardTen(const char symbol[], int i) {
        if (i == 0) {
                std::cout << "---------";
        }
        else if (i == 1) {
                std::cout << "|10     |";
        }
        else if (i == 2) {
                std::cout << "| " << symbol << "   " << symbol << " |";
        }
        else if (i == 3) {
                std::cout << "|   " << symbol <<  "   |";
        }
        else if (i == 4) {
                std::cout << "| " << symbol << "   " << symbol << " |";
        }
        else if (i == 5) {
                std::cout << "|       |";
        }
        else if (i == 6) {
                std::cout << "| " << symbol << "   " << symbol << " |";
        }
        else if (i == 7) {
                std::cout << "|   " << symbol << "   |";
        }
        else if (i == 8) {
                std::cout << "| " << symbol << "   " << symbol << " |";
        }
        else if (i == 9) {
                std::cout << "|     10|";
        }
        else {
                std::cout << "---------";
        }
}

void card::cardJack(const char symbol[], int i) {
        if (i == 0) {
                std::cout << "---------";
        }
        else if (i == 1) {
                std::cout << "|" << symbol << "J     |";
        }
        else if (i == 2) {
                std::cout << "|       |";
        }
        else if (i == 3) {
                std::cout << "|       |";
        }
        else if (i == 4) {
                std::cout << "|       |";
        }
        else if (i == 5) {
                std::cout << "|       |";
        }
        else if (i == 6) {
                std::cout << "|       |";
        }
        else if (i == 7) {
                std::cout << "|       |";
        }
        else if (i == 8) {
                std::cout << "|       |";
        }
        else if (i == 9) {
                std::cout << "|     " << symbol << "J|";
        }
        else {
                std::cout << "---------";
        }
}

void card::cardQueen(const char symbol[], int i) {
        if (i == 0) {
                std::cout << "---------";
        }
        else if (i == 1) {
                std::cout << "|" << symbol << "Q     |";
        }
        else if (i == 2) {
                std::cout << "|       |";
        }
        else if (i == 3) {
                std::cout << "|       |";
        }
        else if (i == 4) {
                std::cout << "|       |";
        }
        else if (i == 5) {
                std::cout << "|       |";
        }
        else if (i == 6) {
                std::cout << "|       |";
        }
        else if (i == 7) {
                std::cout << "|       |";
        }
        else if (i == 8) {
                std::cout << "|       |";
        }
        else if (i == 9) {
                std::cout << "|     " << symbol << "Q|";
        }
        else {
                std::cout << "---------";
        }
}

void card::cardKing(const char symbol[], int i) {
        if (i == 0) {
                std::cout << "---------";
        }
        else if (i == 1) {
                std::cout << "|" << symbol << "K     |";
        }
        else if (i == 2) {
                std::cout << "|       |";
        }
        else if (i == 3) {
                std::cout << "|       |";
        }
        else if (i == 4) {
                std::cout << "|       |";
        }
        else if (i == 5) {
                std::cout << "|       |";
        }
        else if (i == 6) {
                std::cout << "|       |";
        }
        else if (i == 7) {
                std::cout << "|       |";
        }
        else if (i == 8) {
                std::cout << "|       |";
        }
        else if (i == 9) {
                std::cout << "|     " << symbol << "K|";
        }
        else {
                std::cout << "---------";
        }
}

