// Да се състави програма, която проверява
// дали зададен символен низ съдържа
// еднакви съседни символи. 

#include <iostream>
#include <locale>

using namespace std;

int main()
{
	string text;
	cout << "Enter a text: ";
	getline(cin, text);
	bool found = false;

	for (int i = 0; i < text.length() - 1; i++)
	{
		if (text[i] == text[i + 1])
		{
			cout << "Found equal consecutive symbols: " << text[i] << text[i + 1] << endl;
			found = true;
			break;
		}
	}
	// Ако цикълът стигне до последния символ(i == text.length() - 1) и се опитаме да направим text[i + 1], 
	// ще излезем извън границите на низа, защото text[i + 1] вече не съществува. Това води до runtime error.

	// Затова цикълът спира един елемент преди последния, за да може безопасно да сравняваме текущия елемент със следващия.
	
	if (!found)
	{
		cout << "No consecutive equal symbols found." << endl;
	}
	return 0;
}
