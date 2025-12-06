// How to find the frequency of a character
// in a given string?

#include <iostream>
using namespace std;

int main()
{
	string text;
	char symbol;
	cout << "Enter a string: ";
	getline(cin, text);

	cout << "\nEnter a character to find it frequency: ";
	cin >> symbol;
	cout << "\nGiven string is: " << text;
	cout << endl;

	int frequency = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == symbol)
		{
			frequency++;
		}
	}
	cout << "\nThe frequency of " << symbol << " is: " << frequency;
	cout << endl;
	return 0;
}
