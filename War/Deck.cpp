Deck::Deck()
{
	for (int i = 0; i <= deckSize; ++i)
	{
		myDeck.push_back(i);
	}
}

void Deck::shuffle()
{
	srand((unsigned)time(0));
	for (int i = 0; i < 1000; ++i)
	{
		int a = rand() % 52;
		int b = rand() % 52;
		swap(myDeck[a], myDeck[b]);
	}
}

vector<Card> Deck::getDeck()
{
	return myDeck;
}