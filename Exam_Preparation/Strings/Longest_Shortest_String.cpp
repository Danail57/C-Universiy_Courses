
/*Дадени са N низа (1 ≤ N ≤ 100), всеки с 
дължина до 255.
Да се намерят най-късият
и най-дългият низ.*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	cout << "Enter how many strings you want: ";
	cin >> N;
	
	string s;
	string shortest, longest;

	cin >> s;
	shortest = longest = s;

	for (int i = 1; i < N; i++)
	{
		cin >> s;
		if (s.length() < shortest.length())
			shortest = s;
		if (s.length() > longest.length())
			longest = s;
	}
	cout << "The shortest string is: " << shortest << endl;
	cout << "The longest string is: " << longest << endl;
	return 0;
}
