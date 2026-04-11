/*24. Да се състави програма за нуждите на
производствена организация, която съхранява 
в масив следните данни за работниците: 
- име - низ до 25 знака; 
- ЕГН - низ от 10 знака;
- размер на месечното заплащане - реално число;
- брой на отработени дни през месеца - цяло число
и извършва следните операции, 
избирани от меню: 
- добавя към масива данните на нов работник;
- извежда всички въведени данни; 
- извежда имената на мъжете с най-малко
със заработка между 300 и 500 лв;
- създава нов масив с имената и за жените
 със заработка над 300 лв, родени 
 през посочен месец.  */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Factory {
public:
	string name;
	string egn;
	double salary;
	int worked_days;

	void get_data();
	void display() const;
};

void Factory::get_data()
{
	cin.ignore();
	cout << "Name: "; getline(cin, name);
	cout << "ID: "; cin >> egn;
	cout << "Salary: "; cin >> salary;
	cout << "Worked days: "; cin >> worked_days;
}

void Factory::display() const
{
	cout << "Name: " << name << endl;
	cout << "ID: " << egn << endl;
	cout << "Salary: " << salary << endl;
	cout << "Worked days: " << worked_days << endl;
}

bool is_male(string egn)
{
	if (egn.length() < 10) return false;
	int gender_digit = egn[8] - '0';
	return (gender_digit % 2 == 0);
}

bool is_female(string egn)
{
	if (egn.length() < 10) return false;
	int gender_digit = egn[8] - '0';
	return (gender_digit % 2 == 1);
}


void display_all_data(const vector <Factory> workers)
{
	for (auto worker : workers)
	{
		worker.display();
	}
}

void display_man_names_and_salaries_between_300_500(const vector<Factory> workers)
{
	bool found = false;
	for (auto worker : workers)
	{
		if (is_male(worker.egn) && worker.salary > 300.0 && worker.salary < 500.0)
		{
			cout << "Worker name: " << worker.name << "|" << "Salary: " << worker.salary << endl;
			found = true;
		}
	}
	if (!found)
		cout << "No matches" << endl;
}

void women_with_salary_up_300_born_in_a_month(const vector <Factory> workers)
{
	int month;
	cout << "Write a month (1 - 12): "; cin >> month;
	vector <string> result;
	for (auto worker : workers)
	{
		int birth_month = stoi(worker.egn.substr(2, 2));
		if (is_female(worker.egn) && worker.salary > 300.0 && birth_month == month)
		{
			result.push_back(worker.name);
		}
	}
	cout << "Result:\n";
	for (auto name : result)
		cout << name << endl;

	if (result.empty())
		cout << "No matches" << endl;
}

int main()
{
	vector <Factory> workers;
	int choice;
	do {
		cout << "\nMenu\n";
		cout << "1. Add worker\n";
		cout << "2. Display all data\n";
		cout << "3. Men with salary 300-500\n";
		cout << "4. Women with salary below 300 and born in any month\n";
		cout << "5. Exit\n";
		cin >> choice;
		if (choice == 1)
		{
			Factory worker;
			worker.get_data();
			workers.push_back(worker);
		}
		else if (choice == 2)
		{
			display_all_data(workers);
		}
		else if (choice == 3)
		{
			display_man_names_and_salaries_between_300_500(workers);
		}
		else if (choice == 4)
		{
			women_with_salary_up_300_born_in_a_month(workers);
		}
	} while (choice != 5);
}
