/*Зададен е едномерният масив от символни низове 
А0, А1,...,Аn-1. Да се състави програма, която 
създава нов масив а0, а1,...,аn-1, 
като стойността на аi  е равна на броя 
на символите в низа Аi. */


#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of strings: ";
	cin >> n;

	char A[1000][100];
	int a[1000];


	// entering the symbols
	for (int i = 0; i < n; i++)
	{
		cout << "Enter a string A[" << i + 1 << "]: ";
		cin >> A[i];
	}

	// counting the symbols
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		while (A[i][count] != '\0')
		{
			count++;
		}
		a[i] = count; // record the count in the new array
	}

	// result
	for (int i = 0; i < n; i++)
	{
		cout << "Symbols in A[" << i + 1 << "] = " << a[i] << endl;
	}
	return 0;
}
