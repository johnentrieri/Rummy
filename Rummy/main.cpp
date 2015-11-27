#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "GameManager.h"

using namespace std;

int main()
{
	cout << "Rummy\n\n";

	GameManager gm;
	gm.init();
	gm.dealCards();
	gm.play();

	system("PAUSE");
	return 0;
}