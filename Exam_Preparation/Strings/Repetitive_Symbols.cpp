
/*Даден е низ S с дължина N (50 ≤ N ≤ 255), 
съставен от: главни букви A–Z, малки букви a–z,
цифри 0–9
В низа има повтарящи се символи.
Трябва да намерим най-ляво разположената двойка
еднакви символи*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cout << "Write some text: ";
	cin >> s;

	int n = s.length();
	int pos[256];
	// ASCI has 256 possible symbols

	for (int i = 0; i < 256; i++)
		pos[i] = -1;
	for (int i = 0; i < n; i++)
	{
		unsigned char ch = s[i];
		if (pos[ch] != -1)
		{
			cout << pos[ch] + 1 << " " << i + 1;
			return 0;
		}
		else 
		{
			pos[ch] = i;
		}
	}
	return 0;
}
