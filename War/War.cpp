War::War()
{
	aDeck.shuffle();
	//get the deck as a vector of cards
	myDeck = aDeck.getDeck();
	//create 2 equal halves for each player
	Player = vector<Card>(myDeck.begin(), myDeck.begin() + 26);
	CPU = vector<Card>(myDeck.begin() + 26, myDeck.begin() + 52);
}

void War::play()
{
	char cont;
	bool stop = false;

	cout << "Welcome to the card game of War!" << endl << endl;
	while ((Player.size() > 0 || CPU.size() > 0) && stop == false)
	{
		//grab each of the first card elements within the vector
		Card playerCard = *(Player.begin());
		Card cpuCard = *(CPU.begin());
		//grab each of the card elements numbers for later movement to back of vector
		int playerNum = playerCard.getCardNum();
		int cpuNum = cpuCard.getCardNum();
		//print out the current cards
		cout << "The Player has: " << playerCard << endl <<"The CPU has: " << cpuCard << endl;

		//if the cards have the same value and thus a tie occurs
		if (playerCard == cpuCard)
		{
			//declare that a tie has occured
			cout << "A Tie! A War it is then!" << endl;
			//create a temporary card vector to store all gathered cards during the loop of wars
			vector<Card> temp;
			//contiue to loop so long as the cards are equal (in case of multiple back to back wars
			while (playerCard == cpuCard)
			{
				//get the current card numbers
				int firstPlayerNum = playerNum;
				int firstCPUNum = cpuNum;

				//push these cards to the back of the temp card vector (array)
				temp.push_back(firstPlayerNum);
				temp.push_back(firstCPUNum);

				//remove the cards from the front of the player and cpu held vectors
				Player.erase(Player.begin());
				CPU.erase(CPU.begin());

				//obtain the next car which is left as unknown (face down) as per the game of war as the bonus victory card for the war
				Card hiddenPlayerCard = *(Player.begin());
				int hiddenPlayerNum = hiddenPlayerCard.getCardNum();
				Card hiddenCPUCard = *(CPU.begin());
				int hiddenCPUNum = hiddenCPUCard.getCardNum();

				//add these cards to the back of the temp card vector
				temp.push_back(hiddenPlayerNum);
				temp.push_back(hiddenCPUNum);

				//remove the cards from each players deck
				Player.erase(Player.begin());
				CPU.erase(CPU.begin());
				//reassign card to the newest card
				playerCard = *(Player.begin());
				cpuCard = *(CPU.begin());
				//reassign card number to the latest card number
				playerNum = playerCard.getCardNum();
				cpuNum = cpuCard.getCardNum();
				//push to the back of temp
				temp.push_back(playerNum);
				temp.push_back(cpuNum);

				//declare which cards are being played
				cout << "The Player has: " << playerCard << endl << "The CPU has: " << cpuCard << endl;

				//check which player has won the war
				if (playerCard < cpuCard)
				{
					//cpu wins
					cout << "The CPU Wins the Round" << endl;
					//removal of front cards
					Player.erase(Player.begin());
					CPU.erase(CPU.begin());
					//adding all cards gathered during the war onto the back of the CPU minideck
					CPU.insert(CPU.end(), temp.begin(), temp.end());
				}
				else
				{
					//player wins
					cout << "The Player Wins the Round" << endl;
					//removal of front cards
					Player.erase(Player.begin());
					CPU.erase(CPU.begin());
					//adding all cards gathered during the war onto the back of the Player minideck
					Player.insert(Player.end(), temp.begin(), temp.end());
				}
			}
		}
		else
		{
			//check which player has won this battle and properly move cards around, very similar to prior if-else statement
			if (playerCard < cpuCard)
			{
				cout << "CPU Wins the Round" << endl;
				Player.erase(Player.begin());
				CPU.erase(CPU.begin());
				CPU.push_back(cpuNum);
				CPU.push_back(playerNum);
			}
			else
			{
				cout << "Player Wins the Round" << endl;
				Player.erase(Player.begin());
				CPU.erase(CPU.begin());
				Player.push_back(cpuNum);
				Player.push_back(playerNum);
			}
		}
		cout << endl;
		//tell the current player and cpu minideck card counts to keep track of who is winning
		cout << "The Player's Card Count: " << Player.size() << endl <<"The CPU's Card Count: " << CPU.size() << endl;
		//ask the player if they wish to continue, acts as a pause to prevent nonstop play of the game that would be too fast to read
		cout << "Enter 'q' to quit or any char to continue: " << flush;

		//get the value in order to halt program
		cin >> cont;
		//check obtained value
		if (cont == 'q')
		{
			stop = true;
		}
		cout << endl;
	}
}