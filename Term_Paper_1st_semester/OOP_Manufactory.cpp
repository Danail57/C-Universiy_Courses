#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Worker
{
public:
	string name;
	string egn;
	double daily_pay;
	int worked_days;

	void get_data();
	void display() const;
};

void Worker::get_data()
{
	cout << "Name: "; cin >> name;
	cout << "EGN"; cin >> egn;
	cout << "Daily pay: "; cin >> daily_pay;
	cout << "Worked days: "; cin >> worked_days;
}

void Worker::display() const
{
	cout << "\nName: " << name << endl;
	cout << "\nEGN: " << egn << endl;
	cout << "\nDaily pay: " << daily_pay << endl;
	cout << "\nWorked days: " << worked_days << endl;
}

int get_age(string egn)
{
	int year = stoi(egn.substr(0, 2));
	int month = stoi(egn.substr(2, 2));
	
	if (month > 40)
	{
		year += 2000;
		month -= 40;
	}
	else if (month > 20)
	{
		year += 1800;
		month -= 20;
	}
	else
	{
		year += 1900;
	}
	time_t t = time(nullptr);
	tm* now = localtime(&t);
	int current_year = now->tm_year + 1900;
	return current_year - year;
}

bool is_female(string egn)
{
	int digit = egn[8] - '0';
	return digit % 2 == 0;
}

double salary(double daily_pay, int worked_days)
{
	return daily_pay * worked_days;
}

int main()
{
	vector<Worker> workers;
	int choice;
	do
	{
		cout << "\n1. Add new worker.\n";
		cout << "\n2. Display the data.\n";
		cout << "\n3. Women > 22 years old and worked 15 or more days\n";
		cout << "\n4. Women with salary > 300.\n";
		cout << "\n5. Exit\n";
		cin >> choice;

		if (choice == 1)
		{
			Worker w;
			w.get_data();
			workers.push_back(w);
		}
		else if (choice == 2)
		{
			for (auto w : workers)
				w.display();
		}
		else if (choice == 3)
		{
			for (auto w : workers)
			{
				if (is_female(w.egn) && get_age(w.egn) > 22 && w.worked_days >= 15)
				{
					cout << w.name << endl;
				}
			}
		}
		else if (choice == 4)
		{
			vector <Worker> result;
			for (auto w : workers)
			{
				if (is_female(w.egn) && salary(w.daily_pay, w.worked_days) > 300)
				{
					result.push_back(w);
				}
			}
			cout << "Women with salary > 300:\n";
			for (auto w : result)
			{
				cout << w.name << endl;
			}
		}

	} while (choice != 5);
	return 0;
}
