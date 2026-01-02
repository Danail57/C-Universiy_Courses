/*Find the Largest Word in a String*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string text;
	cout << "Enter a string: ";
	getline(cin, text);

	string word, longest_word;
	stringstream ss(text);

	while (ss >> word)
	{
		if (word.length() > longest_word.length())
		{
			longest_word = word;
		}
	}
	cout << "The longest word is: " << longest_word << endl;
	return 0;
}
