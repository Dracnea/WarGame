#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Card.h"
using namespace std;

class Deck
{

public:
	Deck();
	void shuffle();
	vector<Card> getDeck();

	friend ostream& operator<<(ostream& out, Deck d)
	{
		vector<Card> c = d.myDeck;
		for (int i = 0; i < c.size(); ++i)
		{
			out << c[i] << endl;
		}
		return out;
	}
	
private:
	vector<Card> myDeck;
	const int deckSize = 52;

};
#include "Deck.cpp"