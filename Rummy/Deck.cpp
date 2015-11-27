#include "Deck.h"
#include <time.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
Deck::Deck()
{
	this->shuffle();
	currentCardIndex = 0;
}

Deck::~Deck()
{
}

void Deck::shuffle()
{
	int randIndex[52];

	for (int i = 0; i < 52; i++) { randIndex[i] = -1; } //set all to -1

	srand(time(NULL)); //random number seed

	for (int i = 0; i < 52; i++)
	{
		int r = rand() % 52; //generate a random number between 1 and 52
		
		for (int j = 0; j <= i; j++) // check through array for duplicates
		{
			if (randIndex[j] == -1) { //no duplicates, add to array
				randIndex[j] = r;
			}

			else if (randIndex[j] == r) { //found a duplicate, try again
				i--;
				break;
			}
		}
	}

	for (int i = 0; i < 52; i++) //assign values and suits
	{
		cards[randIndex[i]].setValue((i % 13) + 2);
		cards[randIndex[i]].setSuit((i % 4));
	}
}

void Deck::print()
{
	for (int i = 0; i < 52; i++)
	{
		cards[i].print();
	}
}

Card Deck::draw()
{
	//TODO - figure out how to handle the deck running out
	if (this->isFinished()) {
		cout << "Error, drawing from empty Deck\n";
		exit(-1);
	}
	else {
		currentCardIndex++;
		return cards[currentCardIndex - 1];
	}
	
}

bool Deck::isFinished()
{
	if (currentCardIndex < 51)
		return false;
	else
		return true;
}
