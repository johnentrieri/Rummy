#include "WinLogic.h"
#include <iostream>
using namespace std;

int winCheck(Hand h)
{
	//DEBUG
	cout << "\nBeginning WinCheck\n";

	Card cards[7];
	int remain_index[3];

	for (int i = 0; i < 7; i++) {
		cards[i] = h.get(i);
	}


	for (int j = 0; j < 7; j++) {

		//DEBUG
		cout << "\nChecking Card " << j << ", ";
		cards[j].print();
		cout << endl;

		int of_a_kind = 0;

		for (int k = 0; k < 7; k++) {
			if (cards[j].getValue() == cards[k].getValue()) {
				of_a_kind++;
			}
		}

		//check remaining for 3 straight or 3 of a kind
		if (of_a_kind == 4) {

			int index = 0;
			for (int k = 0; k < 7; k++) {
				if (cards[j].getValue() != cards[k].getValue()) {
					remain_index[index++] = k;
				}
			}

			//DEBUG
			cout << "\nHand has 4 " << cards[j].getValue() << "'s\n";
			cout << "\nRemaining cards are: " << remain_index[0] << " " << remain_index[1] << " " << remain_index[2] << endl;

			int v0 = cards[remain_index[0]].getValue();
			int s0 = cards[remain_index[0]].getSuit();
			int v1 = cards[remain_index[1]].getValue();
			int s1 = cards[remain_index[1]].getSuit();
			int v2 = cards[remain_index[2]].getValue();
			int s2 = cards[remain_index[2]].getSuit();

			if (v0 == v1 && v0 == v2) {

				//DEBUG
				cout << "\nHand also has 3 " << v0 << "'s\n\nRUMMY\n\n";

				return 1;
			}

			if (s0 == s1 && s0 == s2) {

				//DEBUG
				cout << "\nRemaining 3 have the same suit\n\n";

				int sorted[3];

				if (v0 > v1) {
					if (v0 > v2) {
						if (v1 > v2) {
							sorted[0] = v2;
							sorted[1] = v1;
							sorted[2] = v0;
						}
						else {
							sorted[0] = v1;
							sorted[1] = v2;
							sorted[2] = v0;
						}

					}
					else {
						sorted[0] = v1;
						sorted[1] = v0;
						sorted[2] = v2;
					}
						
				}
				else {
					if (v1 > v2) {
						if (v0 > v2) {
							sorted[0] = v2;
							sorted[1] = v0;
							sorted[2] = v1;
						}
						else {
							sorted[0] = v0;
							sorted[1] = v2;
							sorted[2] = v1;
						}
					}
					else {
						sorted[0] = v0;
						sorted[1] = v1;
						sorted[2] = v2;
					}
				}

				
				if ((sorted[0]+1 == sorted[1] && sorted[0]+2 == sorted[2]) || (sorted[0] + 1 == sorted[1] && sorted[0] + 12 == sorted[2])) {

					//DEBUG
					cout << "\nHand also has a 3 card straight\n\nRUMMY\n\n";

					return 1;
				}
			}
		}//end 4OfAkind

	}

	return 0;
}