/*Даден е ред с текст (има интервали).
Да се намери най-дългата дума и дължината ѝ.*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text;
	cout << "Write some text: ";
	getline(cin, text);
	
	int current_length = 0;
	int max_length = 0;
	string current_word = "";
	string longest_word = "";

	for (int i = 0; i <= text.length(); i++)
	{
		if (i < text.length() && text[i] != ' ')
		{
			current_word += text[i];
			current_length++;
		}
		else
		{
			if (current_length > max_length)
			{
				max_length = current_length;
				longest_word = current_word;
			}
			current_word = "";
			current_length = 0;
		}
	}
	cout << longest_word << " " << max_length << endl;
	return 0;
}
