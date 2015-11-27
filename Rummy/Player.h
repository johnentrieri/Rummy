#include "Hand.h"
#include <string>

using namespace std;
#pragma once
class Player
{
public:
	Player();
	~Player();
	Hand hand;
	void setName(string n);
	string getName();
private:
	string name;
};

