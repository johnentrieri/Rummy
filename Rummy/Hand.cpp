#include "Hand.h"
#include <iostream>

using namespace std;
Hand::Hand()
{
}

Hand::~Hand()
{
}

void Hand::put(int index, Card card)
{
	cards[index] = card;
}

Card Hand::get(int index)
{
	return cards[index];
}

void Hand::print()
{
	for (int i = 0; i < 7; i++)
	{
		cout << i << " : ";
		cards[i].print();
	}
}
