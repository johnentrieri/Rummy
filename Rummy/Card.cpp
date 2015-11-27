#include "Card.h"
#include <iostream>
using namespace std;

Card::Card()
{
}

Card::~Card()
{
}

int Card::getValue()
{
	return value;
}

int Card::getSuit()
{
	return suit;
}

void Card::setValue(int v)
{
	value = v;
}

void Card::setSuit(int s)
{
	suit = s;
}

void Card::print()
{
	switch (value)
	{
	case 11:
		cout << "Jack of ";
		break;
	case 12:
		cout << "Queen of ";
		break;
	case 13:
		cout << "King of ";
		break;
	case 14:
		cout << "Ace of ";
		break;
	default:
		cout << value << " of ";
		break;
	}

	switch (suit)
	{
	case 0:
		cout << "Hearts";
		break;
	case 1:
		cout << "Diamonds";
		break;
	case 2:
		cout << "Clubs";
		break;
	case 3:
		cout << "Spades";
		break;
	}

	cout << endl;
}
