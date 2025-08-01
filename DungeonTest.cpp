#include <iostream>
#include <string>
#include <cstdlib> //for random numbers
#include <sstream>
#include <windows.h>
#include <fstream>
using namespace std;
int InputCheck(string word);
bool checkFile(string HalOfFame);
struct Adventurer
{
	string name;
	int def;
	int hp;
	int dmg;
	int MaxHp;
	int heal;
	int MaxDmg;
	int MagicDmg;
	int MaxMagicDmg;
};
void SetConsoleColor(WORD color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}
void ResetConsoleColor(WORD color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN |
		FOREGROUND_BLUE);
}
int GenerateRandomEnemyDamage()
{
	return rand() % 50 + 10 + 1;
}
int GenerateRandomEnemyHp()
{
	return rand() % 100 + 50 + 1;
}
int GenerateRandomPlayerDamage()
{
	return rand() % 50 + 10 + 1;
}
int GenerateRandomPlayerHp()
{
	return rand() % 100 + 50 + 1;
}
int GenerateRandomPlayerMagicDamage()
{
	return rand() % 50 + 10 + 1;
}
int GenerateRandomPlayerDEF()
{
	return rand() % 30 + 10 + 1;
}
int main()
{
	srand(time(NULL));
	bool fighting = true;
	string HallOfFame = "HallOfFame.txt", printing = "";
	if (!checkFile(HallOfFame))
	{
		ofstream fileCreate(HallOfFame);
		fileCreate.close();
	}
	string option;
	string adventurerName;
	string enemies[10] = { "Slimes", "Goblins", "Dinosaur", "Golem", "Demon",
	"Ancient Titan", "The Chimera", "Mystic Marauder", "Stink Monster",
	"Necromancer" };
	string enemieName = enemies[rand() % 10];
	string weaponNames[10] = { "Sword", "Axe", "Bow", "Staff", "Dagger", "Hammer",
	"Mace", "Spear", "Mystic Bow", "Magic Wand" };
	string weaponName = weaponNames[rand() % 10];
	bool dmgImmune[10] = { false, false, false, false, true, false, true, false,
	false, true };
	//Adventurer
	Adventurer player;
	player.dmg = 0;
	player.hp = 0;
	int playerDMG = GenerateRandomPlayerDamage();
	int playerHP = GenerateRandomPlayerHp();
	int playerMagicDMG = GenerateRandomPlayerMagicDamage();
	int playerDEF = GenerateRandomPlayerDEF();
	player.def = 0;
	player.MaxHp = 0;
	player.heal = 10;
	int atk = rand() % 101 + 1;
	int Atk = 0;
	int Battle;
	//Enemy
	int edmg[10];
	int ehp[10];
	int enemyDMG = GenerateRandomEnemyDamage();
	int enemyHP = GenerateRandomEnemyHp();
	int CurrentEnemy = 0; //Keeps track of enemy
	int DefeatedEnemies = 0;
	//OtherStuff
	int offdef;
	int orb;
	int mhp[5] = { 20, 40, 80, 100, 200 };//10, 20, 40, 50, 100
	int crit;
	int evade;
	int quantity = 0;
	int RandEvent;
	int Button;
	int Chance;
	int help;
	int choice;
	int HoF = 0;
	cout << "Welcome my to this game the rules are simple you battle some enemies,ones stronger than others and yeah just that.\nLet's begin\n";
		cout << "Actually, before we begin do you want to see the Hall of Fame?\n1.Yes\n2.No\n";
		getline(cin, option);
	HoF = InputCheck(option);
	if (HoF == 1) //See Hall of Fame
	{
		ifstream openingFile(HallOfFame);
		if (openingFile.is_open())
		{
			cout << "This is the Hall of Fame\n\n";
			while (getline(openingFile, printing))
			{
				cout << printing << endl;
			}
		}
		openingFile.close();
	}
	else if (HoF == 2) //Skip Hall of Fame
	{
		cout << "Ok then.\n";
	}
	cout << "\nNow let's begin.\n\nBut first. What's your name brave adventurer?\n";
	getline(cin, adventurerName);
	player.name = adventurerName;
	player.MagicDmg = playerMagicDMG;
	player.dmg = playerDMG;
	player.hp = playerHP;
	player.def = playerDEF;
	player.heal = 10;
	cout << "You start with a " << weaponName << " your hp is " << player.hp << ",your Atk is " << player.dmg << ", Magic Atk " << player.MagicDmg << " and your def is " << player.def << " and you can heal up to " << player.heal << " healthpoints.\n";
		cout << "With all that out of the way let's get to fighting.\n";
	system("pause");
	system("CLS");
	while (fighting) //Fight starts
	{
		cout << "Here are your stats: Hp " << player.hp << ", your Atk is: " <<
			player.dmg << ", Magic Atk " << player.MagicDmg << " and your Def is :" <<
			player.def << " and you can heal " << player.heal << " Hp.\n\n";
		cout << "Enemy: " << enemies[CurrentEnemy] << "\nHealth: " << enemyHP << "\nAtk: " << enemyDMG << "\n\n";
		edmg[CurrentEnemy] = enemyDMG;
		ehp[CurrentEnemy] = enemyHP;
		cout << "1.Attack\n2.Heal\n3.Magic Skill\n";
		getline(cin, option);
		Battle = InputCheck(option);
		if (Battle == 1) //Normal ATK
		{
			if (!dmgImmune[CurrentEnemy]) //Enemy not immune to normal ATKs
			{
				crit = rand() % 50 + 1;
				if (player.hp == 1) //Normal ATKs hit
				{
					SetConsoleColor(FOREGROUND_GREEN);
					cout << "\n\nCritical hit!! Damage dealt : " << player.dmg * 2
						<< "\n";
					cout << "You dodged!!\n\n";
					player.hp = player.hp;
					enemyHP -= player.dmg * 2;
				}
				else if (crit < 15) //Crit ATK
				{
					SetConsoleColor(FOREGROUND_GREEN);
					cout << "\n\nCritical hit , damage dealt : " << player.dmg * 2
						<< "\n";
					enemyHP -= player.dmg * 2;
					if (enemyHP <= 0) //If enemy HP 0 Victory
					{
						ResetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN |
							FOREGROUND_BLUE);
						cout << "You win\n\n";
					}
					else //Continue
					{
						SetConsoleColor(FOREGROUND_RED);
						cout << "\nThe enemy hit you, he dealt : " << enemyDMG <<
							"\n";
						player.hp -= edmg[CurrentEnemy];
						ResetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN |
							FOREGROUND_BLUE);
					}
				}
				else //Same thing but no crit ATK
				{
					SetConsoleColor(FOREGROUND_GREEN);
					cout << "\n\nYou hit the enemy, damage dealt : " << player.dmg
						<< "\n";
					enemyHP -= player.dmg;
					if (enemyHP <= 0)
					{
						ResetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN |
							FOREGROUND_BLUE);
						cout << "You win\n\n";
					}
					else
					{
						SetConsoleColor(FOREGROUND_RED);
						cout << "\nThe enemy hit you, he dealt : " << enemyDMG <<
							"\n";
						player.hp -= edmg[CurrentEnemy];
						ResetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN |
							FOREGROUND_BLUE);
					}
				}
			}
			else //Enemy Immune to normal ATKs
			{
				cout << "Damn enemy really said: Nuh-uh fool\n";
				SetConsoleColor(FOREGROUND_RED);
				cout << "\nThe enemy hit you, he dealt : " << enemyDMG << "\n";
				player.hp -= edmg[CurrentEnemy];
				ResetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN |
					FOREGROUND_BLUE);
			}
		}
		else if (Battle == 2) //Heal / Def
		{
			SetConsoleColor(FOREGROUND_GREEN);
			cout << "\n\nYou decided to heal yourself\n\n";
			player.hp += player.heal;
			ResetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			if (player.def >= edmg[CurrentEnemy])
			{
				cout << "Enemy dealt no damage.\n";
			}
			else
			{
				edmg[CurrentEnemy] -= player.def;
				SetConsoleColor(FOREGROUND_RED);
				cout << "\nThe enemy hit you, he dealt : " << edmg[CurrentEnemy] <<
					"\n\n";
				//edmg[CurrentEnemy] -= player.def;
				player.hp -= edmg[CurrentEnemy];
				ResetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN |
					FOREGROUND_BLUE);
			}
		}
		else if (Battle == 3) //Magic ATK
		{
			crit = rand() % 50 + 1;
			if (player.hp == 1) //Magic Crit Hit and Dodge
			{
				SetConsoleColor(FOREGROUND_GREEN);
				cout << "\n\nCritical hit!! Damage dealt : " << player.MagicDmg * 2
					<< "\n";
				cout << "You dodged!!\n\n";
				player.hp = player.hp;
				enemyHP -= player.MagicDmg * 2;
			}
			else if (crit < 15) //Magic Crit 2
			{
				SetConsoleColor(FOREGROUND_GREEN);
				cout << "\n\nCritical hit , damage dealt : " << player.MagicDmg * 2
					<< "\n";
				enemyHP -= player.MagicDmg * 2;
				if (enemyHP <= 0)
				{
					ResetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN |
						FOREGROUND_BLUE);
					cout << "You win\n\n";
				}
				else
				{
					SetConsoleColor(FOREGROUND_RED);
					cout << "\nThe enemy hit you, he dealt : " << enemyDMG << "\n";
					player.hp -= edmg[CurrentEnemy];
					ResetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN |
						FOREGROUND_BLUE);
				}
			}
			else // The same but no crit
			{
				SetConsoleColor(FOREGROUND_GREEN);
				cout << "\n\nYou hit the enemy, damage dealt : " << player.MagicDmg
					<< "\n";
				enemyHP -= player.MagicDmg;
				if (enemyHP <= 0)
				{
					ResetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN |
						FOREGROUND_BLUE);
					cout << "You win\n\n";
				}
				else
				{
					SetConsoleColor(FOREGROUND_RED);
					cout << "\nThe enemy hit you, he dealt : " << enemyDMG << "\n";
					player.hp -= edmg[CurrentEnemy];
					ResetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN |
						FOREGROUND_BLUE);
				}
			}
		}
		if (enemyHP <= 0) //After defeating enemies Hall of Fame or Events
		{
			ResetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << "\n\n You defeated " << enemies[CurrentEnemy] << ".\n\n";
			if (CurrentEnemy == 9) //Enter Hall of Fame
			{
				ofstream HallOfFameFile("HallOfFame.txt", ios::app);
				if (HallOfFameFile.is_open())
				{
					HallOfFameFile << player.name << " - HP: " << player.hp << ",ATK: " << player.dmg << ", Magic ATK " << player.MagicDmg << ", DEF : " <<
						player.def << "\n";
					HallOfFameFile.close();
					cout << "Congratulations, you have made it to the Hall of Fame!\n";
				}
				else
				{
					cout << "Error saving to HallOfFame.txt\n";
				}
				cout << "Do you want to see the Hall of Fame?\n1. Yes\n2. No\n";
				getline(cin, option);
				HoF = InputCheck(option);
				if (HoF == 1) //See Hall of Fame
				{
					ifstream openingFile(HallOfFame);
					if (openingFile.is_open())
					{
						cout << "This is the Hall of Fame\n\n";
						while (getline(openingFile, printing))
						{
							cout << printing << endl;
						}
					}
					openingFile.close();
				}
				else if (HoF == 2) //Skip Hall of Fame
				{
					cout << "Ok then.\n";
				}
				fighting = false;
			}
			else //Random Events
			{
				player.hp = playerHP;
				player.hp + enemyHP / 2;
				enemyHP = GenerateRandomEnemyHp();
				enemyDMG = GenerateRandomEnemyDamage();
				Chance = rand() % 3 + 1;
				RandEvent = rand() % 10;
				if (RandEvent == 1)//RandomEvent1
				{
					cout << "Look a stats orb. This will increase your hp or atk by 5 go and choose.\n1.Hp\n2.Atk\n";
						getline(cin, option);
					orb = InputCheck(option);
					if (orb == 1)
					{
						player.hp = player.hp += 5;
					}
					else if (orb == 2)
					{
						player.dmg = player.dmg += 5;
					}
				}
				else if (RandEvent == 2)//RandomEvent2
				{
					cout << "Look you found a weapon\n";
					int atk = rand() % 101 + 1;
					Atk += atk;
					if (atk > 180)
					{
						cout << "Legendary " << weaponName << ": ATK/MagicATK= " <<
							atk << ".\n\n";
					}
					else {
						cout << weaponName << ": ATK/MagicATK= " << atk << "\n\n";
					}
					cout << ": Total ATK/MagicATK: " << Atk << endl;
					player.dmg = player.dmg += Atk;
					player.MagicDmg = player.MagicDmg += Atk;
					cout << "Your dmg now is " << player.dmg << " and your Magic ATK is : " << player.MagicDmg << ".\n\n";
				}
				else if (RandEvent == 3)//RandomEvent3
				{
					cout << "Oh no, you fell on a trap!!\n";
					player.hp = player.hp -= 5;
					cout << "Now your health is " << player.hp << ".\n";
					if (player.hp <= 0)
					{
						cout << "Game over, you died to a trap...\n\n";
						fighting = false;
					}
				}
				else if (RandEvent == 4)//RandomEvent4
				{
					cout << "You found someone in the middle of your adventure.	Will you help him ? \n1.Yes\n2.No\n";
						getline(cin, option);
					help = InputCheck(option);
					if (help == 1)
					{
						cout << "You decided to help him.\n";
						if (Chance == 1)
						{
							if (player.dmg > 30)
							{
								cout << "But he juked you and stole your heapons but worry not you still know some magic.\n";
									player.dmg = playerDMG;
								player.MagicDmg = playerMagicDMG;
								cout << "Your attack damage is now: " << player.dmg
									<< ".\n";
							}
							else
							{
								cout << "He called you dumb. lol\n";
								player.hp = player.hp -= 1;
								cout << "Emotional damage! hp -1 you now have: " <<
									player.hp << ".\n";
							}
						}
						else if (Chance == 2)
						{
							cout << "You helped him and he gave you a potion.\n";
							player.heal = player.heal += 3;
							cout << "Now you can heal up to " << player.heal <<
								"health points.\n";
						}
					}
					else if (help == 2)
					{
						cout << "Wow you didn't help him. Quite the human being we have here.\n";
					}
				}
				else if (RandEvent == 5)//RandomEvent5
				{
					cout << "WOAH A SUPER COOL AWESOME EVENT YOU'RE REALLY LUCKY MY	GUY!!!\n";
						system("pause");
					cout << "Kidding there's nothing here bye!!\n";
				}
				else if (RandEvent == 6)//RandomEvent6
				{
					cout << "Oh look a wizard.\n";
					cout << "Wizard: Would you like to make an exchange?\n1. Yes\
n2. No\n";
					getline(cin, option);
					choice = InputCheck(option);
					if (choice == 1)
					{
						cout << "Wizard: Very well but it won't be cheap\nWhat change do you want to make ? \n1. + 5 hp - 5 atk\n2. + 5 atk - 5 hp\n3. 2 + heal - 1 hp and -1 atk\n";
							getline(cin, option);
						choice = InputCheck(option);
						if (choice == 1)
						{
							cout << "As you wish\n";
							player.hp = player.hp += 5;
							player.dmg = player.dmg -= 5;
							cout << "Your hp is now " << player.hp << " and your atk is " << player.dmg << ".\n";
						}
						else if (choice == 2)
						{
							cout << "As you wish\n";
							player.dmg = player.dmg -= 5;
							player.hp = player.hp += 5;
							cout << "Your hp is now " << player.hp << " and your atk is " << player.dmg << ".\n";
						}
						else if (choice == 3)
						{
							cout << "As you wish\n";
							player.heal = player.heal += 2;
							player.dmg = player.dmg -= 1;
							player.hp = player.hp -= 1;
							cout << "Your hp is now " << player.hp << " your atk is " << player.dmg << " and now you can heal up to " << player.heal << ".\n";
						}
					}
					else if (choice == 2)
					{
						cout << "Wizard: Well your loss kid.\n";
					}
				}
				else if (RandEvent == 7)//RandomEvent7
				{
					cout << "A strength check? What is this?\n";
					if (player.dmg <= 30)
					{
						cout << "Stranger: You're lucky you survived pal you're way	to weak.Let me help you.\n";
							player.dmg += 10;
						cout << "Stranger: You look much stronger now. You're welcome.\nYou can now do " << player.dmg << " damage.\n";
					}
					else
					{
						cout << "Oh... you're good then, your strength is good	enough.\n";
					}
				}
				else if (RandEvent == 8)//RandomEvent8
				{
					cout << "Wait is this random event number 8? Here have this	just because I'm running out of ideas for more events.\n";
						player.hp = player.hp += 5;
					player.dmg = player.dmg += 5;
					cout << "I added 5 HP and 5 ATK. Goodbye.\n";
				}
				else if (RandEvent == 9)//RandomEvent9
				{
					cout << "You encountered John Cena... That's it. pretty cool encounter right ? \n";
				}
				else if (RandEvent == 10)//RandomEvent10
				{
					cout << "Look you found a button. Will you press it?\n1. Yes\
n2. No\n";
					getline(cin, option);
					Button = InputCheck(option);
					if (Button == 1)
					{
						if (Chance == 1)
						{
							cout << "Nothing happened\n";
						}
						else if (Chance == 2)
						{
							cout << "Look a healing book appeared. (You learned	more about healing)\n";
								if (Chance == 1)
								{
									cout << "You got bored and learned nothing\n";
								}
								else if (Chance == 2)
								{
									cout << "You learned healing but didn't understand most of it.\n";
										player.heal = player.heal += 5;
									cout << "You can now heal " << player.heal << ".\
n";
								}
								else if (Chance == 3)
								{
									cout << "Your learned a lot\n";
									player.heal = player.heal += 10;
									cout << "You can now heal " << player.heal << ".\
n";
								}
						}
						else if (Chance == 3)
						{
							cout << "The floor opened up and you fell in a trap.\
n";
							if (Chance == 1)
							{
								cout << "The floor started shaking, you lost your balance and hit your head.\n";
									player.hp = player.hp -= 2;
								cout << "You lost a bit of health you now have " <<
									player.hp << ".\n";
							}
							else if (Chance == 2)
							{
								cout << "You fell on lava lol... You died.\n";
								fighting = false;
							}
						}
					}
					else if (Button == 2)
					{
						cout << "You didn't press the button? Really? So boring.\
n";
					}
				}
				CurrentEnemy++;
				cout << "\n\nPrepare to face the next enemy!\n\n";
			}
		}
		else if (player.hp <= 0)
		{
			cout << "You dead kid.\n\n";
			fighting = false;
			system("pause");
		}
		cout << "\n\n";
		system("pause");
		system("cls");
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
		cout << "Use numbers dude" << endl;
		getline(cin, word);
		if (word == "")
			word = " ";
	}
	stringstream(word) >> check;
	return check;
}
bool checkFile(string HallOfFame)
{
	ifstream file(HallOfFame);
	if (file.is_open())
	{
		file.close();
		return 1;
	}
	else
	{
		return false;
	}
}

