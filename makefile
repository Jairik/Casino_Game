all: game

game: main.o card.o poker.o blackjack.o
	g++ main.o card.o poker.o blackjack.o -o game

blackjack.o: blackjack.cpp
	g++ -c blackjack.cpp

poker.o: poker.cpp
	g++ -c poker.cpp

main.o: main.cpp
	g++ -c main.cpp

cards.o: g++ -c card.cpp
	g++ -c card.cpp

clean:
	rm -rf *o game
