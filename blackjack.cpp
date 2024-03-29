//JJ McCauley - blackjack.cpp

#include <iostream>
#include "blackjack.h"
#include "card.h"

//Constructor, which will print initial ascii art and get seed money
blackjack::blackjack() {
	printAsciiArt();
	std::cout << "Enter seed money to play: $";
	std::cin >> seedMoney;
	currentBalance = seedMoney;
}

//Main function that calls the other functions in the program
void blackjack::playBlackjack() {
	bool hold, bust, endProg = false;
	int holdSelection;
	while (!endProg) {
		hold = false; 
		bust = false;
		card::shuffleCard();
		setBet();
		bool insurance = setupHands();
		//Player draws all necessary cards
		while (!hold) {
			std::cout << "Hit (0) or Hold (1)? " ;
			std::cin >> holdSelection;
			if (holdSelection == 1) {
				hold = true;
			}
			else if (holdSelection == 0) {
				drawCard('p');
				card::displayHand(playerHandSize, playerHand);
				if (playerHandTotal > 21) {
					std::cout << "Bust!" << std::endl;
					bust = true;
					hold = true; //to break out of the loop
				}
			}
			else {
				std::cout << "Incorrect input, please try again: ";
			}			
		}
		std::cout << "Player Hand: " << std::endl;
		card::displayHand(playerHandSize, playerHand);
		std::cout << "Total: " << playerHandTotal << std::endl;
		while (dealerDrawCard()) {
			drawCard('d');
		}
		std::cout << "Dealer Hand: " << std::endl;
		card::displayHand(dealerHandSize, dealerHand);
		std::cout << "Total: " << dealerHandTotal << std::endl;
		//determining win amounts
		winAmount = 0;
		if (insurance) {
			currentBalance -= (betAmount*.5);
			if (dealerHandTotal > 21) {
				std::cout << "Dealer busted, you win!" << std::endl;
				winAmount = 2*betAmount;
				currentBalance += winAmount;
			}
			else {
				std::cout << "You did not win anything" << std::endl;
			}
		}
		else { //if insurance was not used
			if (bust) {
				std::cout << "You did not win anything" << std::endl;	
			}
			else if (dealerHandTotal > 21) {
				std::cout << "Dealer busted, you win!" << std::endl;
				winAmount = (betAmount*2);
				currentBalance += winAmount;
			}
			else if (dealerHandTotal < 21 && playerHandTotal == 21 && playerHandSize == 2) {
				std::cout << "You had blackjack and dealer didn't, you win!" << std::endl;
				winAmount = (betAmount*2.5);
				currentBalance += winAmount;
			}
			else { 
				if (playerHandTotal == dealerHandTotal) {
					std::cout << "You and dealer had equal hand, you get your bet back" << std::endl;
					winAmount = betAmount;
					currentBalance += winAmount;
				}
				else if (playerHandTotal > dealerHandTotal) {
					std::cout << "You had a better hand then dealer, you win!" << std::endl;
					winAmount = (betAmount*2);
					currentBalance += winAmount;
				}
			}
		}
		displayWinnings();
		endProg = playAgain();
	}
	std::cout << "Total Winnings: $" << (currentBalance - seedMoney) << std::endl;
	std::cout << "Thank you for playing JJ's blackjack game!" << std::endl;
}

//Sets up the hands, prints the player's hand and dealer's first card, then asks if the user would like to use insurance if applicable
bool blackjack::setupHands() {
	char insuranceSelection;
	bool valid = false;
	playerHandSize = 0;
	playerHandTotal = 0;
	dealerHandSize = 0;
	dealerHandTotal = 0;
	for (int i = 0; i < 2; i++) {
		drawCard('p'); //player draws a card
               	drawCard('d'); //dealer draws a card
       	} 
	int temp = dealerHand[1].num; //Will hold the dealer's second card number so we may assign it to 0 (blank card)
	dealerHand[1].num = 0;
	std::cout << "Your Hand: " << std::endl;
        card::displayHand(playerHandSize, playerHand);
	std::cout << "Dealer's Hand: " << std::endl;        
	card::displayHand(2, dealerHand);
	dealerHand[1].num = temp; //reassigning card value
	if (dealerHand[0].num == 1) {
		std::cout << "Dealer drew an Ace!" << std::endl;
		std::cout << "Would you like to purchase insurance (Y/N)? ";
		while (!valid) {
        	        std::cin >> insuranceSelection;
        	        if (insuranceSelection == 'y' || insuranceSelection == 'Y') {
				currentBalance -= betAmount;
				std::cout << "Current Balance = " << currentBalance << std::endl;
				return true;
        	        }
        	        else if (insuranceSelection == 'n' || insuranceSelection == 'N') {
        	                valid = true;
        	        }
        	        else {
        	                std::cout << "Incorrect choice- please try again" << std::endl;
        	        }
        	}
	}
	return false;
}

//Will draw a new card to the players hand and return the new handSize. will pass in the char c if the player is drawing and d if dealer is drawing
void blackjack::drawCard(char c) {
	if (c == 'p') { //players draws card
		playerHand[playerHandSize] = card::getCard();
		if (playerHand[playerHandSize].num > 9) {
			playerHandTotal += 10;
		}
		else if (playerHand[playerHandSize].num == 1) {
			playerHandTotal += 11;
		}
		else {
			playerHandTotal += playerHand[playerHandSize].num;
		}
	       	playerHandSize++;
	}
	else { //dealer draws card
		dealerHand[dealerHandSize] = card::getCard();
		if (dealerHand[dealerHandSize].num > 9) {
			dealerHandTotal += 10;
		}
		else if (dealerHand[dealerHandSize].num == 1) {
			dealerHandTotal += 11;
		}
		else {
			dealerHandTotal += dealerHand[dealerHandSize].num;
		}
		dealerHandSize++;
	}
}

//Will set the betAmount variable
void blackjack::setBet() {
        std::cout << "How much do you want to bet? $";
        std::cin >> betAmount;
        while (betAmount > currentBalance || betAmount < 0) { //betAmount is not valid
                std::cout << "Incorrect bet amount-please try again: ";
                std::cin >> betAmount;
        }
        currentBalance -= betAmount;
}
  
//Will return true if the dealer should draw an additional card
bool blackjack::dealerDrawCard() {
	bool draw = true;
	if (dealerHandTotal > 16) {
		draw = false;
	}
	return draw;
}

//Determines if the player would like to play again
bool blackjack::playAgain() {
	bool endP, valid = false;
        char playAgain;
	if (currentBalance == 0) {
		std::cout << "Balance has been exausted..." << std::endl;
		return true;
	}
        std::cout << "Do you want to play again? (Y/N) ";
        while (!valid) {
                std::cin >> playAgain;
                if (playAgain == 'y' || playAgain == 'Y') {
                        valid = true;
			endP = false;
                }
                else if (playAgain == 'n' || playAgain == 'N') {
                        valid = true;
			endP = true;
                }
                else {
                        std::cout << "Incorrect choice- please try again" << std::endl;
                }
        }
	return endP;
}

//Displays the winnings from that round
void blackjack::displayWinnings() {
	winAmount -= betAmount;
	std::cout << "Initial Amount: $" << seedMoney << std::endl;
	std::cout << "Current Amount: $" << currentBalance << std::endl;
	std::cout << "You won: $" << winAmount << std::endl;
}


void blackjack::printAsciiArt() {
const char* welcomeTo = R"( \ \        / / | |                          | |       
  \ \  /\  / /__| | ___ ___  _ __ ___   ___  | |_ ___  
   \ \/  \/ / _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \ 
    \  /\  /  __/ | (_| (_) | | | | | |  __/ | || (_) |
     \/  \/ \___|_|\___\___/|_| |_| |_|\___|  \__\___/
)";

const char* blackjackArt = R"(
██████╗ ██╗      █████╗  ██████╗██╗  ██╗     ██╗ █████╗  ██████╗██╗  ██╗
██╔══██╗██║     ██╔══██╗██╔════╝██║ ██╔╝     ██║██╔══██╗██╔════╝██║ ██╔╝
██████╔╝██║     ███████║██║     █████╔╝      ██║███████║██║     █████╔╝ 
██╔══██╗██║     ██╔══██║██║     ██╔═██╗ ██   ██║██╔══██║██║     ██╔═██╗ 
██████╔╝███████╗██║  ██║╚██████╗██║  ██╗╚█████╔╝██║  ██║╚██████╗██║  ██╗
╚═════╝ ╚══════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝ ╚════╝ ╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝
)";

std::cout << welcomeTo << blackjackArt << std::endl;
}

