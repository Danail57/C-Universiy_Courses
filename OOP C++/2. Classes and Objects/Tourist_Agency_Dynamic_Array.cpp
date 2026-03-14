#include <iostream>
#include <string>
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
	void display() const;
	string get_ID() const { return ID; }
	int get_salary() const { return month_salary; }
};


void TouristAgency::get_data()
{
	cin.ignore(1000, '\n');
	cout << "Destination: "; getline(cin, destination);
	cout << "Phone number: "; cin >> phone_number;
	cout << "Name: "; cin.ignore(); getline(cin, name);
	cout << "ID: "; cin >> ID;
	cout << "Monthly salary: "; cin >> month_salary;
}

void TouristAgency::display() const
{
	cout << "Name: " << name << "| Destination: " << destination << "| ID " << ID << endl;
}

int main()
{
	int capacity = 2;
	int current_size = 0;
	TouristAgency* people = new TouristAgency[capacity];
	int choice;
	do 
	{
		cout << "\nMENU\n";
		cout << "1. Add tourist\n";
		cout << "2. Show all tourists\n";
		cout << "3. Show women IDs\n";
		cout << "4. Exit\n";
		cout << "Choice: ";
		if (!(cin >> choice)) break;

		if (choice == 1)
		{
			if (current_size == capacity)
			{ 
				capacity *= 2; 
				TouristAgency* temp = new TouristAgency[capacity];
				for (int i = 0; i < current_size; i++)
				{
					temp[i] = people[i];
				}
				delete[] people;
				people = temp;
				cout << "(Log: Array expanded to capacity " << capacity << ")\n";
			}
			people[current_size].get_data();
			current_size++;
		}
		else if (choice == 3)
		{
			for (int i = 0; i < current_size; i++)
			{
				string currend_ID = people[i].get_ID();
				if (currend_ID.length() > 8 && (currend_ID[7] - '0') % 2 == 1)
				{
					cout << "Woman ID: " << currend_ID << endl;
				}
			}
		}
		else if (choice == 2)
		{
			for (int i = 0; i < current_size; i++)
			{
				people[i].display(); 
			}
		}
	} while (choice != 4);
	delete[] people;
}
