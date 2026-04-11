/*25. Да се състави програма за нуждите на 
производствена организация, която съхранява
в масив следните данни за работниците:
- име - низ до 25 знака; 
- ЕГН - низ от 10 знака;
- размер на месечното заплащане - реално число;
- брой на отработени дни през месеца - цяло число 
и извършва следните операции, избирани от меню:  
- добавя към масива данните на нов работник; 
- извежда всички въведени данни; 
- извежда имената и възрастта на всички мъже; 
- създава нов масив с имената и месечното заплащане
на мъжете.  */

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

struct WorkerInfo {
	string name;
	double monthly_salary;
};

int calculate_birth_year(string egn)
{
	if (egn.length() < 10) return 0;
	int year = stoi(egn.substr(0, 2));
	int month = stoi(egn.substr(2, 2));
	int birth_year = 0;

	if (month > 40)
	{
		birth_year = 2000 + year;
	}
	else if (month > 20)
	{
		birth_year = 1800 + year;
	}
	else
	{
		birth_year = 1900 + year;
	}
	return birth_year;
}

class Factory {
public:
	string name;
	string egn;
	double salary;
	int worked_days;

	void get_data();
	void display() const;
	int get_age() const;
};

int Factory::get_age() const
{
	time_t t = time(0);
	tm* now = localtime(&t);
	int current_year = now->tm_year + 1900;
	int birth_year = calculate_birth_year(egn);
	return current_year - birth_year;
}


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

void display_all_data(const vector<Factory> workers)
{
	for (auto worker : workers)
	{
		worker.display();
	}
}

void display_age_and_name_of_man(const vector<Factory> workers)
{
	for (auto worker : workers)
	{
		if (is_male(worker.egn))
		{
			cout << "Name: " << worker.name << "|"<< "Age: " << worker.get_age() << endl;
		}
	}
}

vector<WorkerInfo> show_names_salary_man(const vector<Factory> workers)
{
	vector <WorkerInfo> result;
	for (auto worker : workers)
	{
		int gender_digit = worker.egn[8] - '0';
		if (gender_digit % 2 == 0)
		{
			WorkerInfo w;
			w.name = worker.name;
			w.monthly_salary = worker.salary * worker.worked_days;
			result.push_back(w);
		}
	}
	return result;
}

int main()
{
	vector<Factory> workers;
	int choice;
	do {
		cout << "\nFactory menu\n";
		cout << "1. Add worker\n";
		cout << "2. Display all information\n";
		cout << "3. Display age and name of a worker\n";
		cout << "4. Display the salary of a worker\n";
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
			display_age_and_name_of_man(workers);
		}
		else if (choice == 4)
		{
			vector <WorkerInfo> salaries = show_names_salary_man(workers);
			for (auto info : salaries)
			{
				cout << info.name << ": " << info.monthly_salary << "$" << endl;
			}
		}
	} while (choice != 5);
}
