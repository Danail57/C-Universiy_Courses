// Да се напише програма, която намира колко пъти
// се среща всеки от следните символи 
// “!’, ‘ ? ’, ‘, ’, ‘.’, ‘ : ’, ‘;’ в даден низ

#include <iostream>
using namespace std;

int main()
{
	char symbls[] = { '!', '?', ',', '.', ':', ';' };
	int counts[6] = { 0, 0, 0, 0, 0, 0 };

	string text;
	cout << "Enter a text: ";
	getline(cin, text);

	for (char c : text)
	{
		for (int i = 0; i < 6; i++)
		{
			if (c == symbols[i])
			{
				counts[i]++;
			}
		}
	}

}
