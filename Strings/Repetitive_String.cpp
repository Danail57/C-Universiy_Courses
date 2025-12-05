// Зададен е двумерен масив A с m реда и n стълба.
// Съставете програма да проверява дали има два еднакви
// стринга в този масив.

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
	
	int m;
	cout << "Enter the number of rows: ";
	cin >> m;

	int n;
	cout << "Enter the number of cols: ";
	cin >> n;

	string text[100][100];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Enter string [" << i + 1 << "][" << j + 1 << "]: ";
			cin >> text[i][j];
		}
	}

	bool found = false;

	for (int i1 = 0; i1 < m; i1++)
	{
		for (int j1 = 0; j1 < n; j1++)
		{
			for (int i2 = i1; i2 < m; i2++)
			{
				int start_j = (i2 == i1) ? j1 + 1 : 0;
				for (int j2 = start_j; j2 < n; j2++)
				{
					if (text[i1][j1] == text[i2][j2])
					{
						found = true;
						cout << "Duplicate found: \"" << text[i1][j1] << "\" at positions "
						<< "[" << i1 + 1 << "][" << j1 + 1 << "] and [" << i2 + 1 << "][" << j2 + 1 << "]\n";
					}
				}
			}
		}
	}
	if (!found)
		cout << "No duplicate strings found.\n";
	return 0;
	
	
}
