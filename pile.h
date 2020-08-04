#ifndef PILE_H 
#define PILE 
#include "card.h"
#include <iostream>
using namespace std;
class Pile
{
private:
	int sum;
	int numOfCards = 0;
	Card cards[52];

public:
	Pile();
	~Pile();
	int getTotal();
	int getNumOfCards();
	bool isPrime();
	void addCard(Card);
	void displayPile();
	void displayLastPile();
};

#endif