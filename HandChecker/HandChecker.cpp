#include <iostream>
#include "../Rummy/Hand.h"
#include "../Rummy/Card.h"
#include "../Rummy/WinLogic.h"

using namespace std;

Hand initializeHand();


int main()
{
	//Hand hand = initializeHand();

	Card cards[7];
	Hand hand;

	cards[0].setValue(11);
	cards[0].setSuit(2);
	hand.put(0, cards[0]);

	cards[1].setValue(2);
	cards[1].setSuit(2);
	hand.put(1, cards[1]);

	cards[2].setValue(3);
	cards[2].setSuit(2);
	hand.put(2, cards[2]);

	cards[3].setValue(11);
	cards[3].setSuit(3);
	hand.put(3, cards[3]);

	cards[4].setValue(11);
	cards[4].setSuit(3);
	hand.put(4, cards[4]);

	cards[5].setValue(14);
	cards[5].setSuit(2);
	hand.put(5, cards[5]);

	cards[6].setValue(11);
	cards[6].setSuit(3);
	hand.put(6, cards[6]);



	winCheck(hand);

	system("PAUSE");
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