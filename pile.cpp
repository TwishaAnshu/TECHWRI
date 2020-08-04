#include "pile.h"


Pile::Pile()
{
}


Pile::~Pile()
{
}

int Pile::getNumOfCards() {
	return numOfCards;
}
void Pile::addCard(Card c) {
	cards[numOfCards] = c;
	numOfCards++;
}
int Pile::getTotal() {
	sum = 0;
	for (int i = 0; i < this->getNumOfCards(); i++) {
		sum += cards[i].getValue();
	}
	return sum;
}
bool Pile::isPrime() {
	// Make sure there are cards in the pile
	if (numOfCards > 0) {
		//Get the total of this pile
		int s = this->getTotal();
		//Make sure the total isn't 1
		if (s != 1) {
			// Loop through all the numbers below s
			for (int i = 2; i < s - 1; i++) {
				if (s%i == 0) {
					// check if s is divisible by i, if it is then not prime
					return false;
				}
			}
			// else it is prime
			return true;
		}
		else {
			//if s = 1 then it's not prime
			return false;
		}
	}
	else {
		// If the pile is empty it's not prime
		return false;
	}
}

void Pile::displayPile() {
	cout << "Pile: ";
	for (int i = 0; i < numOfCards; i++) {
		cards[i].displayCard();
		cout << ", ";
	}
	if (sum > 1) {
		cout << "Prime: " << sum << endl;
	}
	else {

	}
}

void Pile::displayLastPile() {
	cout << "Final Pile: ";
	for (int i = 0; i < numOfCards; i++) {
		cards[i].displayCard();
		cout << ", ";
	}
	cout << "Total: " << sum;
	if (isPrime()) {
		cout << " YOU WIN!" << endl;
	}
	else {
		cout << " You Lost..." << endl;
	}
}