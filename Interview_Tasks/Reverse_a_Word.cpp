#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word;
	string reversed_word = "";

	cout << "Enter a word: ";
	cin >> word;

	int i = word.length() - 1;

	while (i >= 0)
	{
		reversed_word += word[i];
		i--;
	}
	cout << "Reversed word: " << reversed_word << endl;
	return 0;
}
