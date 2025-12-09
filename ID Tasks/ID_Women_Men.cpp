/*. Зададен е едномерният масив от ЕГН-та E0,
E1,..., En-1  Да се състави програма, която създава
два нови масива М0, М1, М2 ....и W0, W1, W2, ...,
съдържащи ЕГН съответно на мъжете и жените.  */


#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cout << "Enter how many IDs you want to write: ";
	cin >> n;

	char ID[100][11];
	string man[100]; 
	string women[100];

	int man_count = 0;
	int women_count = 0;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter ID[" << i + 1 << "]: ";
		cin >> ID[i];

		char last_digit = ID[i][8];
		if ((last_digit - '0') % 2 == 0)
		{
			women[women_count++] = ID[i];
		}
		else
		{
			man[man_count++] = ID[i];
		}
	}

	cout << "\n--- Men IDs ---\n";
	for (int i = 0; i < man_count; i++)
	{
		cout << man[i] << endl;
	}

	cout << "\n--- Women IDs ---\n";
	for (int i = 0; i < women_count; i++)
	{
		cout << women[i] << endl;
	}
	return 0;
}

