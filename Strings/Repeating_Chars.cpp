/*Даден е низ с дължина N, съставен от 
големи и малки латински букви и цифри, в който
има повтарящи се знаци.
Напишете програма, която определя най-ляво 
разположените два еднакви знака в низа. 
Казваме че два еднакви знака в низа са
разположени най-ляво, ако в ляво от десния няма
други два еднакви знака. 
Програмата трябва да извежда две цели числа 
между 1 и N - позициите в низа, в които
са намерени най-ляво разположените
два еднакви знака.*/

#include <iostream> 
#include <cstring>
using namespace std;

int main()
{
	char s[1000];
	cout << "Write string: ";
	cin >> s;

	int N = strlen(s);
	int last_pos[128];
	for (int i = 0; i < 128; i++)
		last_pos[i] = -1;

	int first = -1, second = -1;
	for (int i = 0; i < N; i++)
	{
		int c = (int)s[i];
		if (last_pos[c] == -1)
		{
			last_pos[c] = i;
		}
		else
		{
			if (second == -1 || i < second)
			{
				first = last_pos[c];
				second = i;
			}
		}
	}
	if (first != -1)
		cout << (first + 1) << " " << (second + 1) << endl;
	else
		cout << "No repeating characters" << endl;
	return 0;
}
