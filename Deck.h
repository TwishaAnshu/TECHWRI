
#ifndef DECK_H //if not defined
#define DECK // define it
#include "card.h"
#include <iostream>
using namespace std;

class Deck
{
private:
	Card theDeck[52];
	int shuffleThisMuch = 150;
	char suits[4] = { 'S', 'H', 'D', 'C' };
	char faces[4] = { 'A', 'J', 'Q', 'K' };
	int topCard = 0;


public:
	Deck();
	void shuffle();
	Card deal();
	void newDeck();
	void display();
	int cardsLeft();
	bool isEmpty();
};

#endif // If it was defined skip to here and don't define it again