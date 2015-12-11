#include <iostream>
#include "../Rummy/Deck.h"
#include "../Rummy/Hand.h"
#include "../Rummy/Card.h"
#include "../Rummy/WinLogic.h"

using namespace std;

Hand initializeHand();
Hand randHand();


int main()
{
	//Hand hand = initializeHand();
	/*
	int values[] = { 6, 3, 4, 14, 2, 6, 6 };
	int suits[] =  { 2, 2, 2, 2, 2, 3, 0 };
	Card cards[7];
	Hand hand;

	for (int i = 0; i < 7; i++) {
		cards[i].setValue(values[i]);
		cards[i].setSuit(suits[i]);
		hand.put(i, cards[i]);

	}
	*/
	//winCheck(hand);

	int result;
	Hand hand;

	for (int i = 0; i < 10000000; i++) {
		hand = randHand();
		result = winCheck2(hand);
		if (result) {
			hand.print();
			cout << "RUMMY - Code: " << result << "\n\n";
		}
	}



	system("PAUSE");
}


Hand randHand()
{
	Deck tempDeck;
	Hand hand;

	for (int i = 0; i < 7; i++) {
		hand.put(i, tempDeck.draw());
	}

	return hand;
}

Hand initializeHand()
{
	Card cards[7];
	Hand hand;
	int user_input;

	for (int i = 0; i < 7; i++) {


		cout << "\n\n";
		cout << "-------------------------\n";
		cout << "Hand so far\n";
		cout << "-------------------------\n";
		for (int j = 0; j < i; j++) {
			cout << j+1 << ": ";
			cards[j].print();
		}

		cout << "\nChoose: 2-10, 11 - Jack, 12 - Queen, 13 - King, 14 - Ace";
		cout << "\nCard[ " << i+1 << " ].value = ";
		cin >> user_input;

		if (user_input >= 2 && user_input <= 14) {
			cards[i].setValue(user_input);
		}
		else {
			cout << "\nInvalid\n\n";
			i--;
			continue;
		}

		cout << "\nChoose: 0 - Hearts, 1 - Diamonds, 2 - Clubs, 3 - Spades";
		cout << "\nCard[ " << i+1 << " ].suit = ";
		cin >> user_input;

		if (user_input >= 0 && user_input <= 3) {
			cards[i].setSuit(user_input);
		}
		else {
			cout << "\nInvalid\n";
			i--;
			continue;
		}
	}

	for (int i = 0; i < 7; i++) {
		hand.put(i, cards[i]);
	}

	cout << "\n\n";
	cout << "-------------------------\n";
	cout << "Hand Initialized\n";
	cout << "-------------------------\n";
	for (int j = 0; j < 7; j++) {
		cout << j+1 << ": ";
		hand.get(j).print();
	}

	return hand;
}