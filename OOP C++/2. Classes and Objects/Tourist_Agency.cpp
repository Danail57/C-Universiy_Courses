#include <iostream>
#include <string>
#include <vector>
#include "tourist_agency.h"
using namespace std;


class TouristAgency {
private:
	string ID;
	int month_salary;

public:
	string name;
	int phone_number;
	string destination;

	void get_data();
	void display();
	string getID();
};

string TouristAgency::getID()
{
	return ID;
}

void TouristAgency::get_data()
{
	cout << "What destination you want to visit?"; cin >> destination;
	cout << "Phone number: "; cin >> phone_number;
	cout << "Name: "; cin >> name;
	cout << "ID: "; cin >> ID;
	cout << "Month salary: "; cin >> month_salary;
}



void TouristAgency::display()
{
	cin.ignore();
	cout << "Chosen destination: " << destination << endl;
	cout << "Guest name: " << name << endl;
	cout << "Phone number: " << phone_number << endl;
}


// vector <TouristAgency> information
void record_all_guest_data(TouristAgency information[], int size)
{
	vector <TouristAgency> people;
	for (int i = 0; i < size; i++)
	{
		people.push_back(information[i]);
	}

	display_id_of_women(people);
	long income = month_income_above_1000(information, size);
	cout << "Total income above 1000: " << income << endl;
}


int get_birthday_dates_of_women(vector<TouristAgency> people)
{
	display_id_of_women(people); 
}

void display_id_of_women(vector<TouristAgency> people)
{
	/*vector <char> women_ids;

	int day, month, year;
	cout << day << "." << month << "." << year << "." << endl;
	cin >> day >> month >> year;

	char ld = '8';
	char id;
	int women_count = 0;
	for (auto w : women_ids)
	{
		cout << "Enter ID: " << w << endl;
		cin >> id;

		char last_digit = ld;
		if ((last_digit - '0') % 2 == 0)
		{
			women_count++;
		}
	}
	return */

	int size = people.size();
	for (int i = 0; i < size; i++)
	{
		TouristAgency currPerson = people[i];
		string currPerson_ID = currPerson.getID();
		bool isWoman = false;
		if (currPerson_ID[7] % 2 == 1) { isWoman = true; }
		if (isWoman)
		{
			cout << "ID of woman #" << i + 1 << ": " << currPerson_ID << '\n';
		}
	}
}


long month_income_above_1000(TouristAgency salaries[], int size)
{
	long salary = 0;

	vector <int> salaries_above_1000;
	for (auto i : salaries_above_1000)
	{
		if (salaries_above_1000[i] > 1000)
		{
			salary += salaries_above_1000[i];
		}
	}
	return salary;
}


int main()
{
	// create vector
	vector<TouristAgency> people{};

	// menu
	
	// 1. add
	for (int i = 0; i < 5; i++)
	{
		TouristAgency toBeAdded{};
		toBeAdded.get_data();
		people.push_back(toBeAdded);
	}

	display_id_of_women(people);
}
