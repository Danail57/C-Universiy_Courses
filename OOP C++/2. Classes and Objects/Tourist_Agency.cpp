#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TouristAgency {
private:
	string ID;
	int month_salary;

public:
	string name;
	string phone_number;
	string destination;

	void get_data();
	void display();
	string getID() const;
	int get_salary() const;
};

void display_id_of_women(const vector<TouristAgency>& people);
long month_income_above_1000(const vector<TouristAgency>& people);

string TouristAgency::getID() const
{
	return ID;
}

int TouristAgency::get_salary() const
{
	return month_salary;
}

void TouristAgency::get_data()
{
	cin.ignore(1000, '\n');
	cout << "What destination you want to visit?"; cin >> destination;
	cout << "Phone number: "; cin >> phone_number;
	cout << "Name: "; cin.ignore(); getline(cin, name);
	cout << "ID: "; cin >> ID;
	cout << "Month salary: "; cin >> month_salary;
}

void TouristAgency::display()
{
	cout << "Chosen destination: " << destination << endl;
	cout << "Guest name: " << name << endl;
	cout << "Phone number: " << phone_number << endl;
}

void display_id_of_women(const vector<TouristAgency>& people)
{
	int size = people.size();
	for (int i = 0; i < size; i++)
	{
		const TouristAgency& currPerson = people[i];
		string currPerson_ID = currPerson.getID();
		bool isWoman = false;
		if ((currPerson_ID[7] - '0') % 2 == 1) { isWoman = true; }
		if (isWoman)
		{
			cout << "ID of woman #" << i + 1 << ": " << currPerson_ID << '\n';
		}
	}
}


long month_income_above_1000(const vector<TouristAgency>& people)
{
	long salary = 0;
	for (const auto& person : people)
	{
		if (person.get_salary() > 1000)
		{
			salary += person.get_salary();
		}
	}
	return salary;
}


void get_birthday_dates_of_women(vector<TouristAgency> people)
{
	display_id_of_women(people);
}

int main()
{
	vector<TouristAgency> people{};
	int choice;

	do 
	{
		cout << "\nMENU\n";
		cout << "1. Add tourist\n";
		cout << "2. Show women IDs\n";
		cout << "3. Total salary above 1000\n";
		cout << "4. Exit\n";
		cout << "Choice: ";

		if (!(cin >> choice))
		{
			cout << "Invalid input! Use numbers only.\n";
			break;
		}

		if (choice == 1)
		{
			TouristAgency t;
			t.get_data();
			people.push_back(t);
		}
		else if (choice == 2)
		{
			display_id_of_women(people);
		}
		else if (choice == 3)
		{
			cout << "Total salary above 1000: " << month_income_above_1000(people) << endl;
		}

	} while (choice != 4);
	return 0;
}
