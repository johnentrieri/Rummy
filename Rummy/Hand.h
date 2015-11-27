#include "Card.h"
#pragma once
class Hand
{
public:
	Hand();
	~Hand();
	void put(int index, Card card);
	Card get(int index);
	void print();

private:
	Card cards[7];
};

