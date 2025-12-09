/*.Зададен е едномерният масив от ЕГН-та E0, E1,..., 
En-1  Да се състави програма, която определя дали
има лица с рожденни дни в един и същи ден */


#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cout << "Enter how many IDs you want to write: ";
	cin >> n;

	char ID[100][11];
	int day[100], month[100];

	for (int i = 0; i < n; i++)
	{
		cout << "Enter ID[" << i + 1 << "]: ";
		cin >> ID[i];
	}

	for (int i = 0; i < n; i++)
	{
		month[i] = (ID[i][2] - '0') * 10 + (ID[i][3] - '0');
		day[i] = (ID[i][4] - '0') * 10 + (ID[i][5] - '0');

		if (month[i] > 40)
		{
			month[i] -= 40;
		}
		else if (month[i] > 20)
		{
			month[i] -= 20;
		}

		bool found = false;
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (day[i] && month[i] == month[j])
				{
					cout << "IDs " << i + 1 << " and " << j + 1 << " have the same birthday: " << day[i] << "." << month[i] << endl;
					found = true;
				}
			}
		}
		if (!found)
		{
			cout << "No matching birthdays." << endl;
		}
		return 0;
	}
}

