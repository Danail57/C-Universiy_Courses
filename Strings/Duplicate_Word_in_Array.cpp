/* Зададен е двумерен масив A с m реда и n стълба.
Съставете програма да проверява дали има два еднакви
 стринга в този масив.*/  



#include <iostream> 
#include <unordered_set>
#include <string>
using namespace std;

int main()
{
	int m;
	cout << "Write the number of rows: ";
	cin >> m;

	int n;
	cout << "Write the number of cols: ";
	cin >> n;

	string text[100][100];
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cout << "Enter string [" << i + 1 << "][" << j + 1 << "]: ";
			cin >> text[i][j];
		}
	}

	unordered_set<string> seen;
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (seen.count(text[i][j]))
			{
				cout << "Duplicate found: " << text[i][j] << endl;
			}
			else
			{
				seen.insert(text[i][j]);
			}
		}
	}
}
