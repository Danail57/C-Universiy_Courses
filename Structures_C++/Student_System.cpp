/*Създайте структура Student, съдържаща име на студента,
масив с 5 оценки и среден успех. ИЗчислете и изведете студента 
с най-нисък, най-висок среден успех, всички студенти
със среден успех по-голям от 3.0 и всички студенти с
оценка 6 и също намерете най-младия и стар ученик по ЕГН.*/


#include <iostream>
#include <string>
using namespace std;

struct Student
{
	string name;
	long long ID;
	double school_marks[5];
	int count_marks;
	double average;
};

int main()
{
	Student students[1000];

	int n;
	cout << "Enter a number for students: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin.ignore();
		cout << "Enter name: ";
		getline(cin, students[i].name);

		cout << "Enter ID: ";
		cin >> students[i].ID;

		cout << "Enter a number for marks: ";
		cin >> students[i].count_marks;

		for (int j = 0; j < students[i].count_marks; j++)
		{
			cout << "Enter mark " << j + 1 << ": ";
			cin >> students[i].school_marks[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		double sum = 0;
		int weak_count = 0;
		for (int j = 0; j < students[i].count_marks; j++)
		{
			sum += students[i].school_marks[j];
			if (students[i].school_marks[j] < 3)
				weak_count++;
		}
		students[i].average = sum / students[i].count_marks;
		cout << "Student: " << students[i].name << endl;
		cout << "Average: " << students[i].average << endl;
		cout << "Weak marks: " << weak_count << endl;
	}


	int min_avg_index = 0;
	int max_avg_index = 0;
	for (int i = 1; i < n; i++)
	{
		if (students[i].average < students[min_avg_index].average)
			min_avg_index = i;
		if (students[i].average > students[max_avg_index].average)
			max_avg_index = i;
	}
	cout << "\nStudents with lowest average: " << students[min_avg_index].name << " (" << students[min_avg_index].average << ")\n";
	cout << "\nStudents with highest average: " << students[max_avg_index].name << " (" << students[max_avg_index].average << ")\n";


	cout << "\nStudents with average > 3.0:\n";
	for (int i = 0; i < n; i++)
	{
		if (students[i].average > 3.0)
			cout << students[i].name << " (" << students[i].average << ")\n";
	}

	cout << "\nStudent with at least one mark 6:\n";
	for (int i = 0; i < n; i++)
	{
		bool has_six = false;
		for (int j = 0; j < students[i].count_marks; j++)
		{
			if (students[i].school_marks[j] == 6)
			{
				has_six = true;
				break;
			}
		}
		if (has_six)
			cout << students[i].name << endl;
	}


	int youngest_index = 0;
	int oldest_index = 0;
	for (int i = 1; i < n; i++)
	{
		if (students[i].ID > students[youngest_index].ID)
			youngest_index = i;
		if (students[i].ID < students[oldest_index].ID)
			oldest_index = i;
	}
	cout << "The youngest student: " << students[youngest_index].name << endl;
	cout << "The oldest student: " << students[oldest_index].name << endl;
}
