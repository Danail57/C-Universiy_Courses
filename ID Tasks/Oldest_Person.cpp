/*. Зададени са два едномерни масива от 
символни низове А0, А1,...,Аn-1 и E0, E1,..., En-1,
където Аi и Ei са съответно името и ЕГН на i-тото лице.
Да се състави програма, която извежда името
на най - възрастното лице.  */


#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cout << "Enter number of people: ";
	cin >> n;

	string names[100];
	string ID[100];

	for (int i = 0; i < n; i++)
	{
		cout << "Enter name[" << i + 1 << "]: ";
		cin >> names[i];

		cout << "Enter ID[" << i + 1 << "]: ";
		cin >> ID[i];
	}

	int oldest_index = 0;
	for (int i = 1; i < n; i++)
	{
		// selecting the year/month/day from the current ID
		int y1 = stoi(ID[i].substr(0, 2));
		int m1 = stoi(ID[i].substr(2, 2));
		int d1 = stoi(ID[i].substr(4, 2));

		// selecting the year/month/day from the
		// Id of the oldest person
		int y2 = stoi(ID[oldest_index].substr(0, 2));
		int m2 = stoi(ID[oldest_index].substr(2, 2));
		int d2 = stoi(ID[oldest_index].substr(4, 2));

		if (y1 < y2 || (y1 == y2 && m1 < m2) || (y1 == y2 && m1 == m2 && d1 < d2))
		{
			oldest_index = i;
		}
	}
	cout << "\nThe oldest person is: " << names[oldest_index] << endl;
	return 0;
	
}

