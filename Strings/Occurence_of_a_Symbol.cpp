/*. Зададен е едномерният масив от символни низове
А0, А1,...,Аn-1. Да се състави програма, 
която създава нов масив а0, а1,...,аn-1, като
стойността на аi  показва колко пъти се
среща зададен символ в низа Аi. */


#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cout << "Enter number of strings: ";
	cin >> n;

	char A[100][100];
	char searched_symbol;
	int a[100];

	for (int i = 0; i < n; i++)
	{
		cout << "Enter A[" << i + 1 << "]: ";
		cin >> A[i];
	}
	cout << "Enter character to search: ";
	cin >> searched_symbol;

	for (int i = 0; i < n; i++)
	{
		int count = 0;
		int j = 0;

		while (A[i][j] != '\0')
		{
			if (A[i][j] == searched_symbol)
				count++;
			j++;
		}
		a[i] = count;
	}

	for (int i = 0; i < n; i++)
	{
		cout << "In A[" << i + 1 << "] symbol '" << searched_symbol << "' appears " << a[i] << " times." << endl;
	}
	return 0;
}
