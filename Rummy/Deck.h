#include "Card.h"

#pragma once
class Deck
{
public:
	Deck();
	~Deck();
	void shuffle();
	void print();
	Card draw();
	bool isFinished();



private:
	Card cards[52];
	int currentCardIndex;

};


