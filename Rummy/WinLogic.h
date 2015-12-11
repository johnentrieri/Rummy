#pragma once
#include "Hand.h"
#include "Card.h"

int winCheck(Hand h);
int winCheck2(Hand h);
void sortRemains(Card r[3]);
bool check3Match(Card c[3]);
bool check3Straight(Card c[3]);
