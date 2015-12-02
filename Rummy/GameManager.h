#include "Player.h"
#include "Deck.h"
#include "Card.h"
#include "Hand.h"

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
	int winCheck(Hand h);
	
private:
	Player player1;
	Player player2;
	Deck gameDeck;
	Card topCard;
};

