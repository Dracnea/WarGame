
Card::Card(int myNum) {
	setNum(myNum);
	setRank();
	setSuit();
}


Card::Card(const Card &c)
{
	*this = c;
}


void Card::operator=(const Card& c)
{
	cardNum = c.cardNum;
	Suit = c.Suit;
	Rank = c.Rank;
	value = c.value;
}

void Card::setNum(int myNum)
{
	cardNum = myNum;
}

int Card::getCardNum()
{
	return cardNum;
}

int Card::getCardValue()
{
	return value;
}

void Card::setRank()
{
	switch (cardNum % rankAmount)
	{
	case 1:
		Rank = "Ace";
		value = 14;
		break;
	case 2:
		Rank = "Two";
		value = 2;
		break;
	case 3:
		Rank = "Three";
		value = 3;
		break;
	case 4:
		Rank = "Four";
		value = 4;
		break;
	case 5:
		Rank = "Five";
		value = 5;
		break;
	case 6:
		Rank = "Six";
		value = 6;
		break;
	case 7:
		Rank = "Seven";
		value = 7;
		break;
	case 8:
		Rank = "Eight";
		value = 8;
		break;
	case 9:
		Rank = "Nine";
		value = 9;
		break;
	case 10:
		Rank = "Ten";
		value = 10;
		break;
	case 11:
		Rank = "Jack";
		value = 11;
		break;
	case 12:
		Rank = "Queen";
		value = 12;
		break;
		//default being if returned value is modulo 0 or case 0
	default:
		Rank = "King";
		value = 13;
		break;
	}
}

void Card::setSuit()
{
	switch (cardNum / rankAmount)
	{
	case 0:
		Suit = "Spades";
		break;
	case 1:
		Suit = "Hearts";
		break;
	case 2:
		Suit = "Diamonds";
		break;
	case 3:
		Suit = "Clubs";
		break;
	default:
		Suit = "Spades";
		break;
	}
}
