//Зададен е двумерен масив А с m реда и n стълба, 
// съдържащ ЕГН-та на група лица.  
// Да се състави програма, която намира
// най-младата жена във всеки ред на двумерния масив.
// NOT READY
#include <iostream>
using namespace std;

int main()
{
	int m;
	cout << "Enter a number for rows: ";
	cin >> m;

	int n;
	cout << "Enter a number for cols: ";
	cin >> n;

	int A[100][100];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int youngest_ID = -1;
		int youngest_year = -1;

		for (int j = 0; j < n; j++)
		{
			int ID = A[i][j];
			int gender_digit = (ID / 100000000) % 10;
			int year = (ID / 100000000) % 10;
			
			if (gender_digit % 2 == 0)
			{
				if (youngest_ID == -1 || year > youngest_year)
				{
					youngest_ID = ID;
					youngest_year = year;
				}
			}
		}
		if (youngest_year != -1)

			cout << "Row " << i + 1 << ": youngest woman ID = " << youngest_ID << endl;
		else
			cout << "Row " << i + 1 << ": no woman found." << endl;
	}
	return 0;
}

