/*. Зададен е едномерният масив от ЕГН-та E0, E1,...,
En-1  Да се състави програма, която създава 
нов масив а0, а1,...,аn-1, като стойността на аi 
е равна на годната на раждане на лицето с ЕГН Ei. */


#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cout << "Enter number of IDs: ";
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
		char first_year_number = ID[i][0];
		char second_year_number = ID[i][1];


		int year = (first_year_number - '0') * 10 + (second_year_number - '0');
		int month = (ID[i][2] - '0') * 10 + (ID[i][3] - '0');
		int day = (ID[i][4] - '0') * 10 + (ID[i][5] - '0');

		if (month > 40)
		{
			month -= 40;
			year += 2000;
		}
		else if (month > 20)
		{
			month -= 20;
			year += 1800;
		}
		else
		{
			year += 1900;
		}
		a[i] = year;

		cout << "ID[" << i + 1 << "] date of birth: " << day << "." << month << "." << year << endl;
	}
	
	/*/ for (int i = 0; i < n; i++)
	{
		cout << "Year of birth for ID[" << i + 1 << "] = " << a[i] << endl;
	}
	return 0; /*/
}
