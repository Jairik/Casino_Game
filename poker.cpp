//JJ McCauley - poker.cpp
//Will hold all logic for poker functions, interacting with the card class

#include <iostream>
#include "card.h" //inherited from poker class
#include "poker.h"

//constructor to initialize variables and get initial amount
poker::poker() {
	setInitAmount();
}

//helper function for the constructor to retrieve initial amount
void poker::setInitAmount() {
	bool invalidAmount = true;
	printAsciiArt();//printing out ascii art welcome message
	std::cout << "How much money would you like to play with?: $";
	while (invalidAmount) {
		std::cin >> initBalance;
		invalidAmount = false;
		if (initBalance < 0) {
			std::cout << "Invalid starting amount- please try again" << std::endl;
			invalidAmount = true;
		}
	}
	currentBalance = initBalance;
	std::cout << "How much do you want to bet?: $";
        std::cin >> betAmount;
        while (betAmount > currentBalance || betAmount < 0) { //if this is not valid
                std::cout << "Incorrect bet amount-please try again: ";
                std::cin >> betAmount;
        }
        currentBalance -= betAmount;
}

/*Will call the appropriate functions to execute a player's turn, returning to main when the 
  player chooses not to play another game*/
void poker::playerTurn() {	
	int betMultiplier;
	card::shuffleCard();
	//Initialize the hand with nextCard values
	for (int i = 0; i < pHandSize; i++) {
		pokerHand[i] = card::getCard();
	}
	//execute the functions during a player's turn
	cardSelection(); //gets the final hand of cards for comparsion
	sortHand(); //sorts the hand to be able to find winning amount
	card::displayHand(pHandSize, pokerHand); //print's the new set of cards
	betMultiplier = getWinAmount(); //will retrieve the reward multiplier
	displayWinnings(betMultiplier); //displays winnings based on multiplier
	if (betAmount == -1) { //in the case that the user has exasuted all funds
		std::cout << "Total Winnings: $" << (currentBalance - initBalance) << std::endl; 
		return; //quit the program
	}
	setBetAmount(); //Now getting the bet for next turn
	std::cout << "Current Balance: " << currentBalance << std::endl;
	if (betAmount == -1) {
		endProgMessage();
		return;
	}
	playerTurn(); //recursively start a new turn
}

//Selection sort to sort cards based on value
void poker::sortHand() {
        int minIndex;
        for (int i = 0; i < pHandSize-1; i++) {
                minIndex = i;
                for (int j = i+1; j < pHandSize; j++) {
                        if (pokerHand[j].num < pokerHand[minIndex].num) {
                                minIndex = j;
                        }
                }
                if (minIndex != i) {
                        //swapping
			card::ACard tempCard = pokerHand[minIndex];
                        pokerHand[minIndex] = pokerHand[i];
                        pokerHand[i] = tempCard;
                }
        }
}

//Displays each card on the screen and asks the user if they would like to hold to card or redraw
void poker::cardSelection() {
	int cardValue, drawNewCard;
	bool validInput;
	for (int i = 0; i < pHandSize; i++) {
		validInput = false; //must be reset every iteration
		//Printing the card value (int or J/Q/K)
		cardValue = pokerHand[i].num;
		if (cardValue > 1 && cardValue < 11) { 
			std::cout << cardValue;
		}
		else if (cardValue == 1) {
			std::cout << "A";
		}
		else if (cardValue == 11) {
			std::cout << "J";
		}
		else if (cardValue == 12) {
			std::cout << "Q";
		}
		else { //if cardValue == 13
			std::cout << "K";
		}
		std::cout << pokerHand[i].pic << ": Hold (1) or Redraw(0)? ";
		while (!validInput) {
			std::cin >> drawNewCard;
			if (drawNewCard == 0) {
				pokerHand[i] = card::getCard(); //drawing a new card
				validInput = true; //will break out of the loop
			}
			else if (drawNewCard == 1) {
				validInput = true; //will not draw a new card & will break out of the loop
			}
			else {
				std::cout << "Invalid Input- Please try again" << std::endl;
			}
		}
	}
}

//asks user for betAmount, validate it, then return it
void poker::setBetAmount() {
	bool valid = false;
	char playAgain;
	std::cout << "Do you want to play again? (Y/N) ";
	while (!valid) {
		std::cin >> playAgain;
		if (playAgain == 'y' || playAgain == 'Y') {
			valid = true;
		}
		else if (playAgain == 'n' || playAgain == 'N') {
			betAmount = -1; //setting to signal value
			return;
		}
		else {
			std::cout << "Incorrect choice- please try again" << std::endl;
		}
	}
	std::cout << "How much do you want to bet? ";
	std::cin >> betAmount;
	while (betAmount > currentBalance || betAmount < 0) { //betAmount is not valid
		std::cout << "Incorrect bet amount-please try again: ";
		std::cin >> betAmount;
	}
	currentBalance -= betAmount;
}

//final message that displays initial amount, final amount, and total winnings
void poker::endProgMessage() {
	std::cout << "Initital Balance: $" << initBalance << std::endl;
	std::cout << "Final Balance: $" << currentBalance << std::endl;
	std::cout << "Total Winnings: $" << (currentBalance - initBalance) << std::endl;
	std::cout << "Thank you for playing, come back again soon!" << std::endl;
}	

//will call helper functions to return the multiplier to multiply the bet by to get winnings
int poker::getWinAmount() {
	int multiplier;
	if (royalStraightFlush()) {
		std::cout << "Straight Royal Flush!" << std::endl;
		multiplier = 50000;
	}
	else if (straightFlush()) {
		std::cout << "Straight Flush!" << std::endl;
		multiplier = 10000;
	}
	else if (fourCard()) {
		std::cout << "Four Card!" << std::endl;
		multiplier = 1000;
	}
	else if (fullHouse()) {
		std::cout << "Full House!" << std::endl;
		multiplier = 100;
	}	
	else if (flush()) {
		std::cout << "Flush!" << std::endl;
		multiplier = 10;
	}
	else if (straight()) {
		std::cout << "Straight!" << std::endl;
		multiplier = 6;
	}
	else if (triple()) {
		std::cout << "Triple!" << std::endl;
		multiplier = 4;
	}
	else if (twoPair()) {
		std::cout << "Two Pair!" << std::endl;
		multiplier = 2;
	}
	else if (jackOrBetter()) {
		std::cout << "Jack or Better!" << std::endl;
		multiplier = 1;
	}
	else { //did not meet any conditions
	       	std::cout << "Not a winner..." << std::endl;
		multiplier = 0;
	}	
	return multiplier;
}

//displays inital, current, and winning amounts to the console
void poker::displayWinnings(int multiplier) {
	currentBalance += (betAmount*multiplier); //determining new currentBalance
	if (currentBalance == 0) {
                std::cout << "Balance Exausted..." << std::endl;
                betAmount = -1; //setting to signal value to quit the game
		return; //moves back to playerTurn function
        }
	std::cout << "Your Initial Balance Was: $" << initBalance << std::endl;
	std::cout << "Your Current Balance Is: $" << currentBalance << std::endl;
	std::cout << "You Win: $" << (betAmount*multiplier) << std::endl;
}

//will iterate through the hand array and will return true if a cardValue is 11 or greater or if it is an ace (1)
bool poker::jackOrBetter() {
	bool found = false;
	for (int i = 0; i < pHandSize-1; i++) {
		if (pokerHand[i].num == pokerHand[i+1].num) {
			if ((pokerHand[i].num > 10 || pokerHand[i].num == 1) && (pokerHand[i+1].num > 10 || pokerHand[i+1].num == 1)) {
				found = true;
				break;
			}
		}
	}
	return found;
}

//iterates through the hand array and returns true if two subsequent cardValues are the same
bool poker::twoPair() {
	bool found = false;
	int pairCount = 0;
	for (int i = 0; i < pHandSize-1; i++) {
		for (int j = i+1; j < pHandSize; j++) {
			if (pokerHand[i].num == pokerHand[j].num) {
				pairCount++;
			}
		}
	}
	if (pairCount > 1) {
		found = true;
	}
	return found;
}

//iterates through the hand array and, if three subsequent cardValues are the same, will return true
bool poker::triple() {
        bool found = false;
        for (int i = 0; i < pHandSize-2; i++) {
                if (pokerHand[i].num == pokerHand[i+1].num && pokerHand[i+1].num == pokerHand[i+2].num) {
                        found = true;
                        break;
                }
        }
        return found;
}

//will check to see if the next card is one more than the last one
bool poker::straight() {
	bool found = true;
	for (int i = 0; i < pHandSize-1; i++) {
		if (pokerHand[i].num != (pokerHand[i+1].num)-1) {
			found = false;
			break;
		}
	}
	        //checking for the case of 10, J, Q, K, A since A can act as both 1 and 14.
        if (!found && pokerHand[0].num == 1 && pokerHand[1].num == 10 && pokerHand[2].num == 11 && pokerHand[3].num == 12 && pokerHand[4].num == 13) {
                found = true;
        }
	return found;
}

//will assume that flush is true, and if any two cards are not the same suit, will return false
bool poker::flush() {
	bool found = true;
	for (int i = 0; i < pHandSize-1; i++) {
		for(int j = 0; j < 4; j++) {
			if(pokerHand[i].pic[j] != pokerHand[i+1].pic[j]) {
				found = false;
				break;
			}
		}
	}
	return found;
}

//checks if the first two and last three or the first three and last two cards are the same. twoPair and triple cannot be called because they could use the same values
bool poker::fullHouse() {
	bool found = false;
	if (pokerHand[0].num == pokerHand[1].num && pokerHand[1].num == pokerHand[2].num && pokerHand[3].num == pokerHand[4].num) {
		found = true;
	}
	else if (pokerHand[0].num == pokerHand[1].num && pokerHand[2].num == pokerHand[3].num && pokerHand[3].num == pokerHand[4].num) {
		found = true;
	}
	return found;
}

//iterates through the hand and checks the next four cards, checking to see if they are equal
bool poker::fourCard() {
	bool found = false;
	for(int i = 0; i < pHandSize-3; i++) {
		if(pokerHand[i].num == pokerHand[i+1].num && pokerHand[i+1].num == pokerHand[i+2].num && pokerHand[i+2].num == pokerHand[i+3].num) {
			found = true;
		}	
	}
	return found;	
}

//if both straight and flush are true, then return true
bool poker::straightFlush() {
	bool found = false;
	if (straight() && flush()) {
		found = true;
	}
	return found;
}

//will check if straightflush is true, and if it is, will check to see if the cardValues of the cards meet the requirements
bool poker::royalStraightFlush() {
	int i = 0;
	bool found = false;;
	if (flush() && pokerHand[0].num == 1 && pokerHand[1].num == 10 && pokerHand[2].num == 11 && pokerHand[3].num == 12 && pokerHand[4].num == 13) {
		found = true;
	}
	return found;
}

//will print out a welcome ascii art message to the console
void poker::printAsciiArt() {
	const char* welcomeTo = R"( \ \        / / | |                          | |       
  \ \  /\  / /__| | ___ ___  _ __ ___   ___  | |_ ___  
   \ \/  \/ / _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \ 
    \  /\  /  __/ | (_| (_) | | | | | |  __/ | || (_) |
     \/  \/ \___|_|\___\___/|_| |_| |_|\___|  \__\___/
)";
	const char* casinoPokerGame = R"(  /$$$$$$                      /$$                           /$$$$$$$           /$$                                  /$$$$$$                                    /$$
 /$$__  $$                    |__/                          | $$__  $$         | $$                                 /$$__  $$                                  | $$
| $$  \__/  /$$$$$$   /$$$$$$$ /$$ /$$$$$$$   /$$$$$$       | $$  \ $$ /$$$$$$ | $$   /$$  /$$$$$$   /$$$$$$       | $$  \__/  /$$$$$$  /$$$$$$/$$$$   /$$$$$$ | $$
| $$       |____  $$ /$$_____/| $$| $$__  $$ /$$__  $$      | $$$$$$$//$$__  $$| $$  /$$/ /$$__  $$ /$$__  $$      | $$ /$$$$ |____  $$| $$_  $$_  $$ /$$__  $$| $$
| $$        /$$$$$$$|  $$$$$$ | $$| $$  \ $$| $$  \ $$      | $$____/| $$  \ $$| $$$$$$/ | $$$$$$$$| $$  \__/      | $$|_  $$  /$$$$$$$| $$ \ $$ \ $$| $$$$$$$$|__/
| $$    $$ /$$__  $$ \____  $$| $$| $$  | $$| $$  | $$      | $$     | $$  | $$| $$_  $$ | $$_____/| $$            | $$  \ $$ /$$__  $$| $$ | $$ | $$| $$_____/    
|  $$$$$$/|  $$$$$$$ /$$$$$$$/| $$| $$  | $$|  $$$$$$/      | $$     |  $$$$$$/| $$ \  $$|  $$$$$$$| $$            |  $$$$$$/|  $$$$$$$| $$ | $$ | $$|  $$$$$$$ /$$
 \______/  \_______/|_______/ |__/|__/  |__/ \______/       |__/      \______/ |__/  \__/ \_______/|__/             \______/  \_______/|__/ |__/ |__/ \_______/|__/
)";
	std::cout << welcomeTo << casinoPokerGame << std::endl;
	
/*Finished Product:
 __          __  _                            _        
 \ \        / / | |                          | |       
  \ \  /\  / /__| | ___ ___  _ __ ___   ___  | |_ ___  
   \ \/  \/ / _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _   
    \  /\  /  __/ | (_| (_) | | | | | |  __/ | || (_) |
     \/  \/ \___|_|\___\___/|_| |_| |_|\___|  \__\___/ 
                                                       
  /$$$$$$                      /$$                           /$$$$$$$           /$$                                  /$$$$$$                                    /$$
 /$$__  $$                    |__/                          | $$__  $$         | $$                                 /$$__  $$                                  | $$
| $$  \__/  /$$$$$$   /$$$$$$$ /$$ /$$$$$$$   /$$$$$$       | $$  \ $$ /$$$$$$ | $$   /$$  /$$$$$$   /$$$$$$       | $$  \__/  /$$$$$$  /$$$$$$/$$$$   /$$$$$$ | $$
| $$       |____  $$ /$$_____/| $$| $$__  $$ /$$__  $$      | $$$$$$$//$$__  $$| $$  /$$/ /$$__  $$ /$$__  $$      | $$ /$$$$ |____  $$| $$_  $$_  $$ /$$__  $$| $$
| $$        /$$$$$$$|  $$$$$$ | $$| $$  \ $$| $$  \ $$      | $$____/| $$  \ $$| $$$$$$/ | $$$$$$$$| $$  \__/      | $$|_  $$  /$$$$$$$| $$ \ $$ \ $$| $$$$$$$$|__/
| $$    $$ /$$__  $$ \____  $$| $$| $$  | $$| $$  | $$      | $$     | $$  | $$| $$_  $$ | $$_____/| $$            | $$  \ $$ /$$__  $$| $$ | $$ | $$| $$_____/    
|  $$$$$$/|  $$$$$$$ /$$$$$$$/| $$| $$  | $$|  $$$$$$/      | $$     |  $$$$$$/| $$ \  $$|  $$$$$$$| $$            |  $$$$$$/|  $$$$$$$| $$ | $$ | $$|  $$$$$$$ /$$
 \______/  \_______/|_______/ |__/|__/  |__/ \______/       |__/      \______/ |__/  \__/ \_______/|__/             \______/  \_______/|__/ |__/ |__/ \_______/|__/
*/}
