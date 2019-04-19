#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iostream>
#include "Card.h"
#include "Deck.h"
using namespace std;

class War
{

public:
	War();
	void play();

private:
	//the deck
	Deck aDeck;
	//deck card vector
	vector<Card> myDeck;
	//two player vectors
	vector<Card> Player;
	vector<Card> CPU;

};

#include "War.cpp"