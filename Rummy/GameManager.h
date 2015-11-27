#include "Player.h"
#include "Deck.h"
#include "Card.h"

#pragma once
class GameManager
{
public:
	GameManager();
	~GameManager();
	int init();
	void dealCards();
	void updateScreen(Player p);
	void playerTurn(Player &p);
	void play();
	
private:
	Player player1;
	Player player2;
	Deck gameDeck;
	Card topCard;
};

