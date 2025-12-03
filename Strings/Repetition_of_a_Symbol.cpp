// Да се напише програма, която намира колко пъти символът
// ‘а’ се среща в низ

#include <iostream>
using namespace std;

int main()
{
	string text;
	cout << "Enter a random text: ";
	getline(cin, text);

	int count = 0;
	for (int i = 0; text[i] != '\0'; i++)
	{
		if (text[i] == 'a')
		{
			count++;
		}
	}
	cout << "The symbol 'a' appears " << count << " times.";
	return 0;
}
