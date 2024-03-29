//JJ McCauley- main.cpp

#include <iostream>
#include <iomanip>
#include "card.h"
#include "poker.h"
#include "blackjack.h"

void printAsciiArt(); 

int main() {
	char choice;
	printAsciiArt();
	std::cout << "Poker (P) or Blackjack (B)? ";
	std::cin >> choice;
	if (choice == 'P') {
		poker poker;
		poker.playerTurn();
	}
	else {
		blackjack blackjack;
		blackjack.playBlackjack();
	}
}

void printAsciiArt() {
	const char* welcomeMessage = R"(
 ___       __   _______   ___       ________  ________  _____ ______   _______           _________  ________     
|\  \     |\  \|\  ___ \ |\  \     |\   ____\|\   __  \|\   _ \  _   \|\  ___ \         |\___   ___\\   __  \    
\ \  \    \ \  \ \   __/|\ \  \    \ \  \___|\ \  \|\  \ \  \\\__\ \  \ \   __/|        \|___ \  \_\ \  \|\  \   
 \ \  \  __\ \  \ \  \_|/_\ \  \    \ \  \    \ \  \\\  \ \  \\|__| \  \ \  \_|/__           \ \  \ \ \  \\\  \  
  \ \  \|\__\_\  \ \  \_|\ \ \  \____\ \  \____\ \  \\\  \ \  \    \ \  \ \  \_|\ \           \ \  \ \ \  \\\  \ 
   \ \____________\ \_______\ \_______\ \_______\ \_______\ \__\    \ \__\ \_______\           \ \__\ \ \_______\
    \|____________|\|_______|\|_______|\|_______|\|_______|\|__|     \|__|\|_______|            \|__|  \|_______|
  	   _________  ___  ___  _______           ________  ________  ________  ___  ________   ________     
  	  |\___   ___\\  \|\  \|\  ___ \         |\   ____\|\   __  \|\   ____\|\  \|\   ___  \|\   __  \    
  	  \|___ \  \_\ \  \\\  \ \   __/|        \ \  \___|\ \  \|\  \ \  \___|\ \  \ \  \\ \  \ \  \|\  \   
  	       \ \  \ \ \   __  \ \  \_|/__       \ \  \    \ \   __  \ \_____  \ \  \ \  \\ \  \ \  \\\  \  
      	        \ \  \ \ \  \ \  \ \  \_|\ \       \ \  \____\ \  \ \  \|____|\  \ \  \ \  \\ \  \ \  \\\  \ 
    	   	 \ \__\ \ \__\ \__\ \_______\       \ \_______\ \__\ \__\____\_\  \ \__\ \__\\ \__\ \_______\
         	  \|__|  \|__|\|__|\|_______|        \|_______|\|__|\|__|\_________\|__|\|__| \|__|\|_______|
)";
	std::cout << welcomeMessage << std::endl;
}
