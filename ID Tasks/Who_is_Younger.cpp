// Да се състави програма, която определя
// кое от две лица със 
// зададени ЕГН - та е по - възрастно

#include <string>
#include <iostream>
using namespace std;


int main()
{
	char ID_1[11], ID_2[11];
	cout << "Enter the first ID: ";
	cin >> ID_1;

	cout << "Enter the second ID: ";
	cin >> ID_2;


	int year_1 = (ID_1[0] - '0') * 10 + (ID_1[1] - '0');
	int month_1 = (ID_1[2] - '0') * 10 + (ID_1[3] - '0');
	int day_1 = (ID_1[4] - '0') * 10 + (ID_1[5] - '0');


	int year_2 = (ID_2[0] - '0') * 10 + (ID_2[1] - '0');
	int month_2 = (ID_2[2] - '0') * 10 + (ID_2[3] - '0');
	int day_2 = (ID_2[4] - '0') * 10 + (ID_2[5] - '0');

	if (month_1 > 40)
	{
		month_1 -= 40; 
		year_1 += 2000;
	}
	
	else if (month_1 > 20)
	{
		month_1 -= 20;
		year_1 += 1800;
	}

	else
	{
		year_1 += 1900;
	}

	if (month_2 > 40)
	{
		month_2 -= 40;
		year_2 += 2000;
	}

	else if (month_2 > 20)
	{
		month_2 -= 20;
		year_2 += 1800;
	}

	else
	{
		year_2 += 1900;
	}

	if (year_1 < year_2 || (year_1 == year_2 && month_1 < month_2) || (year_1 == year_2 && month_1 == month_2 && day_1 < day_2))
		cout << "The first person is older." << endl;

/*Първо проверяваме дали годината на първото лице е по-малка от годината на второто.
Ако е така → първото лице е по-възрастно.
Ако годините са равни, сравняваме месеца.
Ако месецът на първото лице е по-малък → първото лице е по-възрастно.
Ако и годината, и месецът са равни, сравняваме деня.
Ако денят на първото лице е по-малък → първото лице е по-възрастно.
Идеята е: по-малката дата → по-възрастно лице.*/

	else if (year_1 > year_2 || (year_1 == year_2 && month_1 > month_2) || (year_1 == year_2 && month_1 == month_2 && day_1 > day_2))
		cout << "The second person is older." << endl;
	else
		cout << "Both persons are on the same age." << endl;

	return 0;
}		
