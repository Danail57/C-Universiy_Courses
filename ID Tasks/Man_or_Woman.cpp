/*.Зададен е едномерният масив от ЕГН-та 
E0, E1,..., En-1  Да се състави програма, която 
създава нов масив а0, а1,...,аn-1, като 
стойността на аi  е 0, ако Ei  е ЕГН на мъж,
или 1, ако Ei  е ЕГН на жена.  */


#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cout << "Enter how many IDs you want to write: ";
	cin >> n;

	char ID[100][11];
	int a[100];

	for (int i = 0; i < n; i++)
	{
		cout << "Enter ID[" << i + 1 << "]: ";
		cin >> ID[i];
	}

	for (int i = 0; i < n; i++)
	{
		int gender_digit = ID[i][8] - '0';
		if (gender_digit % 2 == 0)
			a[i] = 1; // woman
		else
			a[i] = 0; // man
	}

	for (int i = 0; i < n; i++)
	{
		cout << "ID[" << i + 1 << "] is " << (a[i] == 0 ? "male" : "female") << endl;
	}
	return 0;
}

