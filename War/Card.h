#pragma once
#include <string>
using namespace std;

class Card
{

public:
	void setNum(int cardNum);
	Card(int cardNum);
	void setRank();
	void setSuit();
	int getCardNum();
	int getCardValue();
	void operator=(const Card& c);
	Card(const Card &c);

	friend bool operator<(Card& c, Card& c2)
	{
		return c.value < c2.value;
	}

	friend bool operator==(Card& c, Card& c2)
	{
		return c.value == c2.value;
	}

	friend ostream& operator<<(ostream& out, Card c)
	{
		out << "Card # " << c.cardNum << " Suit: " << c.Suit << " Rank: " << c.Rank << " Value: " << c.getCardValue() << endl;
		return out;
	}

private:
	int cardNum;
	int value;
	string Suit;
	string Rank;
	const int suitAmount = 4;
	const int rankAmount = 13;

};

#include "Card.cpp"