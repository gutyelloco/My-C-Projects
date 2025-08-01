#include<iostream>
#include<string>
#include<sstream>


using namespace std;
int InputCheck(string word);

int main()
{
    string input;
    int check = 1;
    int option;
    int* Mypointer;
    int temp;

    cout << "How many numbers do you want in your list?\n";
    getline(cin, input);
    check = InputCheck(input);
    Mypointer = new int[check];
    cout << "Input " << check << " Numbers\n";
    for (int x = 0;check > x;x++)
    {
        cout << x + 1 << ") ";
        getline(cin, input);
        Mypointer[x] = InputCheck(input);

    }
    system("pause");
    system("cls");
    do
    {
        cout << "Do you want to:\n1) See list\n2) Organize from highest to lowest\n3) Organize from lowest to highest\n4) Start over\n5) Exit\n";
        getline(cin, input);
        option = InputCheck(input);
        if (option == 1)
        {
            for (int x = 0; check > x;x++)
            {
                cout << x + 1 << ") " << Mypointer[x] << "\n";

            }

        }
        else if (option == 2)
        {
            for (int a = 0; a < check; a++)
            {
                for (int b = a + 1; b < check; b++) {
                    if (Mypointer[a] < Mypointer[b])
                    {
                        temp = Mypointer[b];
                        Mypointer[b] = Mypointer[a];
                        Mypointer[a] = temp;
                    }
                }
                cout << "-" << Mypointer[a] << "- \n";
            }
            cout << "- - -Organized- - -\n" << endl;

        }
        else if (option == 3)
        {

            for (int a = 0; a < check; a++)
            {
                for (int b = a + 1; b < check; b++) {
                    if (Mypointer[a] > Mypointer[b])
                    {
                        temp = Mypointer[a];
                        Mypointer[a] = Mypointer[b];
                        Mypointer[b] = temp;

                    }

                }
                cout << "-" << Mypointer[a] << "-";
                cout << "\n";
            }
            cout << "- - -Organized- - -\n" << endl;

        }
        else if (option == 4)
        {
            system("cls");
            cout << "How many numbers do you want in your list?\n";
            getline(cin, input);
            check = InputCheck(input);
            Mypointer = new int[check];
            cout << "Give me " << check << " Numbers\n";
            for (int x = 0;check > x;x++)
            {
                cout << x + 1 << ") ";
                getline(cin, input);
                Mypointer[x] = InputCheck(input);

            }
        }

    } while (option < 5);
    delete[]Mypointer;
    cout << "\n\n";
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