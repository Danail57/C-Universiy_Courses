/*Reverse a Given String*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text;
	string reversed_text;

	cout << "Enter text: ";
	getline(cin, text);

	for (int i = text.length() - 1; i >= 0; i--)
	{
		reversed_text += text[i];
	}
	cout << "Reversed text: " << reversed_text << endl;
	return 0;
}
