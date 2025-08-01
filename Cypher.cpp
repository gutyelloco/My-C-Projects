#include<iostream>
#include<string>

using namespace std;

int main()
{
	string Text;

	cout << "Tu texto:\n";
	getline(cin, Text);

	int k;

	cout << "\n\nValor de desplazamiento: \n";
	cin >> k;

	string abc_mayus = "ABCDEFGHIJKLMNSOPQRSTUVWXYZ";
	string abc_min = "abcdefghijklmnsopqrstuvwxyz";


	string cifrado = "";

	for (char c : Text)
	{
		if (isupper(c))
		{
			string abc = abc_mayus;
			int indice = (abc.find(c) + k) % abc.length();
			cifrado += abc[indice];
		}
		else if (islower(c))
		{
			string abc = abc_min;
			int indice = (abc.find(c) + k) % abc.length();
			cifrado += abc[indice];
		}
		else
		{
			cifrado += c;
		}
	}

	cout << "Texto Cifrado: " << cifrado << "\n";
}