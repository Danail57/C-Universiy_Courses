/*2.Да се състави програма за нуждите на хотел, която
поддържа в масив следната информация за гостите на хотела:
- име - низ до 20 знака; 
- ЕГН - низ от 10 знака; 
- семейно положение (1-несемеен, 2-семеен); 
- брой нощувки - цяло число;
- цена на ползваното легло - реално число; 
- населено място - низ до 25; знака 
и извършва следните операции, избирани от меню: 
- записва в едномерен масив въведените данни; 
- извежда на екрана всички въведени данни; 
- извежда на екрана имената и заплатената сума 
от семейните гости от зададено населено място;
- създава нов масив с данните на несемейните мъже, 
родени през посочена година;  */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Hotel {
public:
	string name;
	string egn;
	int marital_status;
	int nights;
	double price;
	string town;

	void get_data();
	void display() const;
};

void Hotel::get_data()
{
	cin.ignore();
	cout << "Guest name: "; getline(cin, name);
	cout << "EGN: "; cin >> egn;
	cout << "Marital status: (1 - single; 2 - family): "; cin >> marital_status;
	cout << "Nights: "; cin >> nights;
	cout << "Price: "; cin >> price;
	cin.ignore();
	cout << "Residence city: "; getline(cin, town);
}

void Hotel::display() const
{
	cout << "Guest name: " << name << endl;
	cout << "EGN: " << egn << endl;
	cout << "Marital status: " << marital_status << endl;
	cout << "Nights: " << nights << endl;
	cout << "Price: " << price << endl;
	cout << "Residence city: " << town << endl;
}

void displya_all_data(const vector<Hotel>& guests)
{
	for (auto guest : guests)
	{
		guest.display();
	}
}

vector <Hotel> single_men(const vector <Hotel>& guests, int year)
{
	vector<Hotel> result;
	for (auto guest : guests)
	{
		if (guest.marital_status == 1)
		{
			int birth_year = stoi(guest.egn.substr(0, 2));

			int gender_digit = guest.egn[8] - '0';

			if (birth_year == year && gender_digit % 2 == 1)
			{
				result.push_back(guest);
			}
		}
	}
	return result;
}

void family_from_town(const vector<Hotel>& guests, string town)
{
	for (auto guest : guests)
	{
		if (guest.marital_status == 2 && guest.town == town)
		{
			double total = guest.nights * guest.price;
			cout << guest.name << " -> " << total << endl;
		}
	}
}

int main()
{
	vector<Hotel> guests;
	int choice;

	do {
		cout << "\nMENU:\n";
		cout << "1. Add guest\n";
		cout << "2. Show all guests\n";
		cout << "3. Family guests from town\n";
		cout << "4. Single men by year\n";
		cout << "0. Exit\n";
		cout << "Choice: ";
		cin >> choice;

		if (choice == 1)
		{
			Hotel g;
			g.get_data();
			guests.push_back(g);
		}
		else if (choice == 2)
		{
			displya_all_data(guests);
		}
		else if (choice == 3)
		{
			string town;
			cin.ignore();
			cout << "Enter town: ";
			getline(cin, town);
			family_from_town(guests, town);
		}
		else if (choice == 4)
		{
			int year;
			cout << "Enter year (last 2 digits): ";
			cin >> year;

			vector<Hotel> result = single_men(guests, year);

			for (auto g : result)
			{
				g.display();
			}
		}

	} while (choice != 0);

	return 0;
}
