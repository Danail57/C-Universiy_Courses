// Да се напише програма, която проверява дали даден низ е
// палиндром 

#include <iostream>
using namespace std;

int main()
{
	cout << "Check if the word is a palindrome." << endl;
	string text;
	cout << "Enter a text: ";
	getline(cin, text);

	int j = 0;
	while (text[j] != '\0')
	{
		j++;
	}
	j--;

	bool is_palindrome = true;
	for (int i = 0; i < j; i++)
	{
		if (text[i] != text[j])
		{
			is_palindrome = false;
			break;
		}
		j--;
	}
	if (is_palindrome)
		cout << "The word is a palindrome." << endl;
	else
		cout << "The word is not a palindrome." << endl;

	return 0;
}
