#include "GameManager.h"
#include <iostream>

using namespace std;

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

int GameManager::init()
{
	string nameString;

	cout << "Player 1 Name: ";
	cin >> nameString;
	player1.setName(nameString);

	cout << "Player 2 Name: ";
	cin >> nameString;
	player2.setName(nameString);

	gameDeck = Deck();

	return 0;
}

void GameManager::dealCards()
{
	for (int i = 0; i < 7; i++)
	{
		player1.hand.put(i, gameDeck.draw());
		player2.hand.put(i, gameDeck.draw());
	}

	topCard = gameDeck.draw();
}

void GameManager::updateScreen(Player p)
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

	cout << p.getName() << "\n\n";
	p.hand.print();

	cout << "\n\nTop Card: ";
	topCard.print();

	cout << "\n0-Pickup\n1-Draw\n2-Forfeit\nChoice: ";
}

void GameManager::playerTurn(Player &p)
{
	updateScreen(p);

	int choice;
	Card tempCard;

	cin >> choice;

	switch (choice)
	{
	case 0:
		cout << "\nChoose a card to replace: ";
		cin >> choice;
		tempCard = topCard;
		topCard = p.hand.get(choice);
		p.hand.put(choice, tempCard);
		updateScreen(p);
		break;
	case 1:
		topCard = gameDeck.draw();

		cout << "\n\nTop Card: ";
		topCard.print();

		cout << "\n0 - Keep\n1 - Discard\nChoice:  ";
		cin >> choice;
		if (choice == 0) {
			cout << "\nChoose a card to replace: ";
			cin >> choice;
			tempCard = topCard;
			topCard = p.hand.get(choice);
			p.hand.put(choice, tempCard);
			updateScreen(p);
			break;
		}

	default:
		cout << "\nPick a Valid Option";

	}
}

void GameManager::play()
{
	while (!gameDeck.isFinished())
	{
		playerTurn(player1);
	}

}
