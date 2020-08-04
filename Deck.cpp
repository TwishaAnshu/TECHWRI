
#include "deck.h"
#include <iostream>
using namespace std;

Deck::Deck()
{	
	newDeck();
}

int Deck::cardsLeft() {
	return 51 - topCard;
}

void Deck::newDeck() {
	int lastCard = 0;
	for (int i = 0; i < 13; i++) {
		char rank;
		int value;
		if (i > 0 && i < 9) {
			rank = '0' + (i + 1);
			value = (i + 1);
		}
		else {
			if (i == 0) {
				rank = faces[i];
				value = 1;
			}
			else if (i == 9) {
				rank = 'T';
				value = 10;
			}
			else {
				rank = faces[i - 9];
				value = 10;
			}
		}
		for (int j = 0; j < 4; j++) {
			theDeck[lastCard] = Card(rank, suits[j]);
			theDeck[lastCard].setValue(value);
			lastCard++;
		}

	}
	cout << "A new deck was created." << endl;
}

Card Deck::deal() {
	topCard++;
	return theDeck[topCard-1];
}

void Deck::display() {
	for (int i = 0; i < 4; i++) {
		for (int j = i; j < 52; j += 4) {
			Card c = theDeck[j];
			c.displayCard();
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Deck::shuffle() {


	for (int i = 0; i < shuffleThisMuch; i++) {
		int ran1 = rand() % 52;
		int ran2 = rand() % 52;

		Card temp = theDeck[ran1]; // No mistake here
		theDeck[ran1] = theDeck[ran2];
		theDeck[ran2] = temp;
	}
}

bool Deck::isEmpty() {
	if (this->cardsLeft() < 1) {
		return true;
	}
	else {
		return false;
	}
}


