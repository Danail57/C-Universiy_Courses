/*Даден е низ, образуван от главни латински букви.
Да се напише програма, която конструира същия низ, 
но от съответните малки латински букви.*/

#include <iostream> 
#include <cstring>
using namespace std;

int main()
{
	char s[1000];
	cout << "Write string: ";
	cin >> s;

	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = s[i] + 32;
		}
	}
	cout << "Lowercase string: " << s << endl;
	return 0;
}
