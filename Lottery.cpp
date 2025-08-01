#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;
int InputCheck(string word);
int rollDice()
{
	return rand() % 6 + 1;
}
int Hand()
{
	return 1 + (rand() % 21);
}
int main()
{
	srand(time(NULL));
	string pInput;
	int tokens, tables, pChips, temp;//pChips(Player Chips)
	int cStake = 15;
	int MinTokens = 15; //Minimum of tokens you can convert
	int houseNumber = 0;
	int playerNumber = 0;
	int random = 15 + (rand() % 7);
	int option = 0;
	int pHand = Hand();
	int dHand = 0;
	int pDice1 = rollDice();
	int pDice2 = rollDice();
	int hDice1 = rollDice();
	int hDice2 = rollDice();
	srand(time(0));
	cout << "Welcome to the mid-term casino. How many tokens do you wish to	convert ? \n";
		getline(cin, pInput);
	tokens = InputCheck(pInput);
	if (tokens < MinTokens)
	{
		tokens = tokens + MinTokens;
		cout << "You have " << tokens << " tokens." << endl;
	}
	else
	{
		cout << "You have " << tokens << " tokens." << endl;
	}
	cout << "Let's begin dude.\n\n";
	cout << "We have 2 tables my friend\n1) Dices\n2) Blackjack(21)\n\nBoth have a 15 chip entry fee.\nWhich one do you want to play ? ---> ";
		getline(cin, pInput);
	tables = InputCheck(pInput);
	if (tables == 1)
	{
		system("CLS");
		cout << "Welcome to Dice!\nVery simple if you can get a higher roll than me	you win and if not well you lose.\n";
			tokens = tokens - 15;
		cout << "\nThe dice game fee was 15 chips you now have " << tokens <<
			".\n\n";
		cout << "How much do you want to add to your initial 15 chip stake? ---> ";
			getline(cin, pInput);
		cStake = InputCheck(pInput);
		pChips = 15 + cStake;
		tokens = tokens - cStake;
		system("pause");
		if (tokens < 0)
		{
			cout << "Not enough chips good bye.\n\n";
			return 0;
		}
		else
		{
			cout << "Very well.\nNew stake " << pChips << ". Remaining chips "
				<< tokens << ".\n\n";
		}
		int playerNumber;
		if (pDice1 > pDice2) {
			playerNumber = pDice1 * 10 + pDice2;
		}
		else {
			playerNumber = pDice2 * 10 + pDice1;
		}
		cout << "Your dices: " << "Dice 1) " << pDice1 << "\nDice 2) " <<
			pDice2 << endl;
		cout << "Your number: " << playerNumber << endl;
		if (hDice1 > hDice2) {
			houseNumber = hDice1 * 10 + hDice2;
		}
		else {
			houseNumber = hDice2 * 10 + hDice1;
		}
		cout << "House's dices: " << "Dice 1) " << hDice1 << "\nDice 2) " <<
			hDice2 << endl;
		cout << "House's number: " << houseNumber << endl;
		if (playerNumber > houseNumber)
		{
			cout << "Congrats you win!" << endl;
			tokens = tokens + 15;
			cout << "You have earned 15 tokens.\n";
		}
		else if (playerNumber < houseNumber)
		{
			cout << "House wins!" << endl;
		}
		else
		{
			cout << "Tie, house wins!" << endl;
		}
		cout << "You now have " << tokens << " chips.\n";
		if (tokens < 15)
		{
			cout << "No more playing for you good bye.\n";
			return 0;
		}
		system("pause");
		system("cls");
		cout << "Wanna play again friend?\n1) Yes\n2) No\n";
		getline(cin, pInput);
		option = InputCheck(pInput);
		if (option == 1)
		{
			return main();
		}
		else if (option == 2)
		{
			cout << "Exit\n";
			system("pause");
			system("cls");
		}
	}
	else if (tables == 2)
	{
		cout << "The Blackjack game fee was 15 chips you now have " << tokens <<
			".\n\n";
		cout << "Welcome to the Blackjack(21) table!\n\n";
		tokens = tokens - 15;
		cout << "\nThe dice game fee was 15 chips you now have " << tokens << ".\n\
n";
		cout << "How much do you want to add to your initial 15 chip stake? ---> ";
		getline(cin, pInput);
		cStake = InputCheck(pInput);
		pChips = 15 + cStake;
		tokens = tokens - cStake;
		system("pause");
		if (tokens < 0)
		{
			cout << "Not enough chips good bye.\n\n";
			return 0;
		}
		else
		{
			cout << "Very well.\nNew stake " << pChips << ". Remaining chips " <<
				tokens << ".\n\n";
		}
		while (pHand < 21)
		{
			cout << pHand << "\n1) Hit\n2) Stay\n";
			getline(cin, pInput);
			option = InputCheck(pInput);
			if (option == 1)
			{
				cout << " Here boy\n";
				random = rand() % 7 + 1;
				pHand = random + pHand;
			}
			else if (option == 2)
			{
				cout << "\nDealer: My turn ";
				dHand = 15 + (rand() % 7);
				if (dHand > pHand)
				{
					cout << dHand << "\nHouse wins! Better luck next time.\n";
					break;
					system("pause");
					system("cls");
				}
				else if (pHand > dHand)
				{
					cout << dHand;
					cout << "\nCongrats you win!" << endl;
					tokens = tokens + 15;
					cout << "You have earned 15 tokens.\n";
					break;
					system("pause");
					system("cls");
				}
				else
				{
					cout << dHand << "\nHouse wins! Better luck next time.\n";
					break;
					system("pause");
					system("cls");
				}
			}
		}
		if (pHand > 21)
		{
			cout << pHand;
			cout << "\nBust! You lose dude.Better luck next time.\n";
			system("pause");
			system("cls");
		}
		else if (pHand == 21)
		{
			cout << pHand;
			cout << "\nCongrats you win! " << endl;
			tokens = tokens + 15;
			cout << "You have earned 15 tokens.\n";
			system("pause");
			system("cls");
		}
		if (tokens < 15)
		{
			cout << "No more playing for you good bye.\n";
			return 0;
		}
		system("pause");
		system("cls");
		cout << "Wanna play again friend?\n1) Yes\n2) No\n";
		getline(cin, pInput);
		option = InputCheck(pInput);
		if (option == 1)
		{
			return main();
		}
		else if (option == 2)
		{
			cout << "Exit\n";
			system("pause");
			system("cls");
		}
	}
}
int InputCheck(string word)
{
	string number = "1234567890";
	int check = 0;
	if (word == "")
		word = " ";
	while (word.find_first_not_of(number) != string::npos)
	{
		cout << "\nNo you fool just a number.\n\nAgain" << endl;
		getline(cin, word);
		if (word == "")
			word = " ";
	}
	stringstream(word) >> check;
	return check;
}

