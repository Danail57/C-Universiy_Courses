
/*Даден е низ, съставен от
малки и големи латински букви.
Да се преброят броят на гласните и 
броят на съгласните.*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text;
	cout << "Write some text: ";
	getline(cin, text);
	
	int count_vowels = 0;
	int count_consonants = 0;

	for (int i = 0; i < text.length(); i++)
	{
		char ch = text[i];
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		{
			if (
				ch == 'a' || ch == 'e' || ch == 'i'
				|| ch == 'o' || ch == 'u' || ch == 'A'
				|| ch == 'E' || ch == 'I'
				|| ch == 'O' || ch == 'U'
				)
			{
				count_vowels++;
			}
			else
			{
				count_consonants++;
			}
		}
	}
	cout << "Vowels: " << count_vowels << endl;
	cout << "Consonants: " << count_consonants << endl;
	return 0;
}
