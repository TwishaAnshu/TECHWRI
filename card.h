#ifndef CARD_H
#define CARD_H
 #include <iostream>
 using namespace std;

class Card
{
private:
	char rank;
	char suit;
	int value;
	bool faceUp;

public:
	Card(char r, char s);
	Card();
	char getRank();
	char getSuit();
	bool isFaceUp();
	void setValue(int n);
	int getValue();
	void displayCard();


};


#endif