#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <windows.h>
using namespace std;
int InputCheck(string word);
int main() {
	string guess;
	int check;
	int limit = 6;
	int WinNums[6] = { 0,0,0,0,0,0 };
	int PlayerNums[6] = { 0,0,0,0,0,0 };
	int random = 0;
	srand(time(NULL));
	cout << "Welcome to Puertorrican lottery." << endl;
	cout << "Please enter 6 numbers from 1 to 6" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << i + 1 << ") ";
		getline(cin, guess);
		PlayerNums[i] = InputCheck(guess);
	}
	for (int i = 0; i < 6; i++) //2 of these
	{
		random = rand() % 6 + 1;
		WinNums[i] = random;
		for (int b = 0; b < 6; b++)
		{
			if (i != b && WinNums[i] == WinNums[b])
			{
				i--;
			}
		}
	}
	for (int i = 0; i < 6; i++)
	{
		cout << WinNums[i] << " ";
		cout << PlayerNums[i] << " " << endl;
		if (WinNums[i] == PlayerNums[i])
		{
			cout << "Congrats" << endl;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		if (WinNums[i] == PlayerNums[i])
		{
			cout << "Congrats" << endl;
		}
	}
	system("pause");
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