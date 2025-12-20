/*Създайте структура Employee, съдържаща:
име
заплата
години стаж

Да се напише програма, която:
Въвежда n служители (1 ≤ n ≤ 100)

Намира служителя с най-висока заплата

Намира служителя с най-малко години стаж

Извежда всички служители със заплата над средната

Извежда всички служители със стаж над 10 години*/

#include <iostream>
#include <string>
using namespace std;

struct Employee {
	string name;
	float salary;
	int work_experience;
};

int main()
{
	Employee employees[1000];

	int n;
	cout << "Enter a number of employees: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin.ignore();
		cout << "Enter name: ";
		getline(cin, employees[i].name);

		cout << "Enter the salary: ";
		cin >> employees[i].salary;

		cout << "Enter the years of experience: ";
		cin >> employees[i].work_experience;
	}

	float sum_salary = 0;
	for (int i = 0; i < n; i++)
		sum_salary += employees[i].salary;
	float average_salary = sum_salary / n;

	int max_salary_index = 0;
	for (int i = 1; i < n; i++)
	{
		if (employees[i].salary > employees[max_salary_index].salary)
			max_salary_index = i;
	}

	int min_experience_index = 0;
	for (int i = 1; i < n; i++)
	{
		if (employees[i].work_experience < employees[min_experience_index].work_experience)
			min_experience_index = i;
	}

	cout << "\nEmployee with highest salary: " << employees[max_salary_index].name << " (" << employees[max_salary_index].salary << ")\n";
	cout << "Employee with least experience: " << employees[min_experience_index].name << " (" << employees[min_experience_index].work_experience << " years)\n";
	
	cout << "\nEmployees with salary above average (" << average_salary << "):\n";
	for (int i = 0; i < n; i++)
	{
		if (employees[i].salary > average_salary)
			cout << employees[i].name << endl;
	}
	cout << "\nEmployees with more than 10 years of experience:\n";
	for (int i = 0; i < n; i++)
	{
		if (employees[i].work_experience > 10)
			cout << employees[i].name << endl;
	}
	return 0;
}
