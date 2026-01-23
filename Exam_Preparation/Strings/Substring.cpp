
/*Дадени са два низа:

S – основен

T – подниз

Да се провери дали T се съдържа в S.
Ако да – да се изведе позицията на първото му срещане (от 1).
Ако не – -1.*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string S, T;
	cout << "Write the main string: ";
	getline(cin, S);

	cout << "Write the substring: ";
	getline(cin, T);

	int n = S.length();
	int m = T.length();
	
	for (int i = 0; i <= n - m; i++)
	{
		bool found = true;
		for (int j = 0; j < m; j++)
		{
			if (S[i + j] != T[j])
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			cout << i + 1;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
