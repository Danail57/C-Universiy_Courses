/*23. Да се състави програма за нуждите на 
производствена организация, която съхранява
в масив следните данни за работниците:
- име - низ до 25 знака; 
- ЕГН - низ от 10 знака;
- размер на дневното заплащане - реално число;
- брой на отработени дни през месеца - цяло число 
и извършва следните операции, избирани от меню:  
- добавя към масива данните на нов работник; 
- извежда всички въведени данни; 
- извежда имената на всички мъже с 
месечно заплащане над 400лв; 
- създава нов масив с имената и датите на
раждане на жените с дневно заплащане под 20 лв */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct WomenWorkerInfo {
	string name;
	double salary;
	string birth_date;
};

class Factory {
public:
	string name;
	string egn;
	double salary;
	int worked_days;

	void get_data();
	void display() const;

	bool is_male() const
	{
		return (egn[8] - '0') % 2 == 0;
	}
	
	double get_monthly_salary() const
	{
		return salary * worked_days; 
	}
	string get_birth_data() const;

};

string Factory::get_birth_data() const
{
	string year = egn.substr(0, 2);
	string month_str = egn.substr(2, 2);
	string day = egn.substr(4, 2);

	int m = stoi(month_str);
	string full_year;

	if (m > 40) {
		full_year = "20" + year;
		m -= 40;
	}
	else if (m > 20) {
		full_year = "18" + year;
		m -= 20;
	}
	else {
		full_year = "19" + year;
	}
	string final_month = (m < 10 ? "0" : "") + to_string(m);
	return day + "." + final_month + "." + full_year;
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

void dsiplay_all_data(const vector<Factory> workers)
{
	for (auto worker : workers)
	{
		worker.display();
	}
}


void display_all_man_names_with_salary_up_400(const vector<Factory> workers)
{
	bool found = false;
	for (auto worker : workers)
	{
		if (worker.salary > 400.0 && worker.is_male())
		{
			cout << "Name: " << worker.name << "| Salary: " << worker.salary << endl;
			found = true;
		}
	}
	if (!found) cout << "No matches\n";
}


vector <WomenWorkerInfo> women_salary_info_below_20(const vector<Factory> workers)
{
	vector<WomenWorkerInfo> result;
	for (auto woman : workers)
	{
		if (!woman.is_male() && woman.salary < 20.0)
		{
			WomenWorkerInfo info;
			info.name = woman.name;
			info.salary = woman.salary;
			info.birth_date = woman.get_birth_data();
			result.push_back(info);
		}
	}
	return result;
}

int main()
{
	vector <Factory> workers;
	int choice;
	do {
		cout << "\nMenu\n";
		cout << "1. Add worker\n";
		cout << "2. Display all data\n";
		cout << "3. Show workers with salary > 400\n";
		cout << "4. Display workers with salary up to 20\n";
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
			dsiplay_all_data(workers);
		}
		else if (choice == 3)
		{
			display_all_man_names_with_salary_up_400(workers);
		}
		else if (choice == 4)
		{
			vector <WomenWorkerInfo> women_list = women_salary_info_below_20(workers);
			for (auto data : women_list)
			{
				cout << "Name: " << data.name << "|" << " Birthday" << data.birth_date << endl;
			}
		}
	} while (choice != 5);
}
