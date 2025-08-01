#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <sstream>
using namespace std;
void SetColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}
int main()
{
	int score = 0;
	char movement = ' ';
	bool GameRun = true;
	//Walls
	int Height = 40;
	int columns = 20;
	int Length = 40;
	//FoodSpawnAndPoints
	int FoodX;
	int FoodY;
	srand(time(0));
	FoodX = 2 + rand() % (Length - 2);
	FoodY = 2 + rand() % (columns - 2);
	char Fruits[5] = { 'A', 'B', 'C', 'D', 'F' };
	int FruitPoints[5] = { 1, 3, 5, 7, 10 };
	char FruitTypes = Fruits[rand() % 5];
	//PlayerSpawn
	int playerX = Length / 2;
	int playerY = columns / 2;
	//SnakeTail
	bool Tail;
	int TailLength = 0;
	int TailX[20], TailY[20];
	while (GameRun)
	{
		for (int a = 0; a < Length; a++) //Top Wall
		{
			cout << "#";
		}
		cout << "\n";
		for (int a = 0; a < columns; a++) //Everything
		{
			for (int b = 1; b < Length + 1; b++)
			{
				if (b == 1 || b == Height)//Walls
				{
					cout << "|";
				}
				else
				{
					if (a == FoodY && b == FoodX)//FruitSpawner
					{
						int colorCode = 7; // Default color white
						switch (FruitTypes)
						{
						case 'A':
							colorCode = 12; // Red
							break;
						case 'B':
							colorCode = 9; // Blue
							break;
						case 'C':
							colorCode = 14; // Yellow
							break;
						case 'D':
							colorCode = 10; // Green
							break;
						case 'F':
							colorCode = 6; // Orange
							break;
						}
						SetColor(colorCode);
						cout << FruitTypes;
						SetColor(7); // Color goes back to white
					}
					else if (a == playerY && b == playerX)//HeadSpawner
					{
						cout << "O";
					}
					else if (playerY == FoodY && playerX == FoodX)//FruitCollision
					{
						for (int i = 0; i < 5; i++)
						{
							if (Fruits[i] == FruitTypes)
							{
								score += FruitPoints[i];
								break;
							}
						}
						FoodX = 2 + rand() % (Length - 2);
						FoodY = 2 + rand() % (columns - 2);
						FruitTypes = Fruits[rand() % 5];
						if (TailLength < 20)
						{
							TailLength++;
						}
						for (int a = TailLength - 1; a > 0; a--)
						{
							TailX[a] = TailX[a - 1];
							TailY[a] = TailY[a - 1];
							if (TailX[a] == playerX && TailY[a] == playerY)
							{
								GameRun = false;
							}
						}
						TailX[0] = playerX;
						TailY[0] = playerY;
					}
					else if (playerY < 0 || playerY >= columns - 0 || playerX < 2
						|| playerX >= Length - 0)//WallImpact(Death)
					{
						system("CLS");
						cout << "Game Over, you hit the wall, your score is: " <<
							score << "\n\n";
						system("pause");
						return 0;
					}
					else
					{
						bool tail = false;
						for (int t = 0; t < TailLength; t++)
						{
							if (TailX[t] == b && TailY[t] == a)// Check for tail collision
							{
							tail = true;
							break;
							}
						}
						if (tail)
						{
							cout << "o"; // Draw tail
						}
						else
						{
							cout << " "; // Draw empty space
						}
					}
				}
			}
			cout << "\n";
		}
		for (int a = 0; a < Length; a++) //Bottom Wall
		{
			cout << "#";
		}
		cout << "\n";
		cout << "Move with W A S D\n";
		cout << "Press x to exit.\n";
		cout << "Points ---> A = 1pt, B = 3pts, C = 5pts, D = 7pts, F = 10pts.\n";
		cout << "Score ---> " << score << "\n";
		if (_kbhit()) //movement
		{
			movement = _getch();
		}
		for (int t = TailLength - 1; t > 0; t--)
		{
			TailX[t] = TailX[t - 1];
			TailY[t] = TailY[t - 1];
		}
		TailX[0] = playerX;
		TailY[0] = playerY;
		switch (movement) //movement
		{
		case 'w':
			playerY--;
			break;
		case 'a':
			playerX--;
			break;
		case 's':
			playerY++;
			break;
		case 'd':
			playerX++;
			break;
		case 'p':
			cout << "Pause\n\n";
			system("pause");
			break;
		case 'x':
			cout << "Exit\nYour score is: " << score << "\n\n";
			system("pause");
			return 0;
			break;
		}
		Sleep(100);
		system("cls");
	}
}