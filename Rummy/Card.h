#pragma once
class Card
{
public:
	Card();
	~Card();
	int getValue();
	int getSuit();
	void setValue(int v);
	void setSuit(int s);
	void print();

private:
	int value;
	int suit;
};
