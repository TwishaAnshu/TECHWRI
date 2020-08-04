#include <iostream>
#include "card.h"
#include "deck.h"
#include "pile.h"

using namespace std;

int main()
{
    // Create a deck
    Deck theDeck;
    int selection;
    int nextPile;
    int lastTotal;
    bool playing = true;
    

    while (playing)
    {
        cout << "-----------------------------" << endl;
        cout << "Play Solitaire !" << endl;
        cout << "1.) New Deck\n2.) Display Deck\n3.) Shuffle Deck\n4.) Play Solitaire Prime\n5.) Exit\n";
        cout << "-----------------------------" << endl;

        // Create piles 
        Pile piles[50];
        while (true)
        {
            cout << "What is your selection?: ";
            cin >> selection;

            // Check for valid input
            if ((selection > 0) && (selection < 6) && cin.good())
            {
                break;
            }
            // Clear cin and display message if invalid input
            else
            {
                cin.clear();
                cin.ignore();
                cout << "Invalid Selection, try again..." << endl;
            }
        }
        // Process selection
        switch (selection)
        {
        case 1:
            theDeck = Deck();
            break;
        case 2:
            theDeck.display();
            break;
        case 3:
            theDeck.shuffle();
            theDeck.display();
            break;
        case 4:
            cout << "PLAYING SOLITAIRE!!!" << endl;
            lastTotal = 0;
            nextPile = 0;
            // if the deck is not empty and the pile is not prime
            while (!theDeck.isEmpty())
            {
                while (!piles[nextPile].isPrime() && !theDeck.isEmpty())
                {
                    // Deal the next card into the pile
                    piles[nextPile].addCard(theDeck.deal());
                }
                // if the deck is empty show the pile and continue
                if (!theDeck.isEmpty())
                {
                    piles[nextPile].displayPile();
                    cout << endl;
                    nextPile++;
                }
            }
            // Displaying the last pile and checking players win or loss status
            piles[nextPile].displayLastPile();
            cout << "Number of Piles: " << (nextPile + 1) << endl;

            break;
        case 5:
            return 0;
        }
    }

    cin.get();
    return (0);
}