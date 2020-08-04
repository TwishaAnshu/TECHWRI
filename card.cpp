#include "card.h"
#include <iomanip>
#include <iostream>
using namespace std;

Card::Card(char r, char s)
{
    rank = r;
    suit = s;
    faceUp = false;
}
Card::Card(){};
char Card::getRank()
{
    return rank;
}

char Card::getSuit()
{
    return suit;
}

bool Card::isFaceUp()
{
    return faceUp;
}

void Card::setValue(int n)
{
    value = n;
}
int Card::getValue()
{
    return value;
}

void Card::displayCard()
{
    if (getRank() == 'T')
    {
        cout << "10";
    }
    else
    {
        // format the rank so that when 10 shows up the columns stay even
        cout << setfill(' ') << setw(2) << getRank();
    }
    cout << getSuit();
}