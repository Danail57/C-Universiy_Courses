// Да се състави програма, която преброява 
// символите в зададен символен низ

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text;
	cout << "Enter a random text: ";
	getline(cin, text);

	int count_symbols = 0;

	for (int i = 0; text[i] != '\0'; i++)
	{
		if (text[i] != ' ')
		{
			count_symbols++;
		}
	}
	cout << "\nTotal number of characters of given string: ";
	cout << count_symbols;
	cout << endl;
	return 0;
}
