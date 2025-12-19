/*Този проект представлява училищна система, в която
са събрани броя оценки, броя на срлабите оценки,
изчислява се средно аритмметичното, и се намира
кой е най - млад и стар ученик по зададени ЕГН - та*/

#include <iostream>
using namespace std;

struct Student
{
	string name;
	long long ID;
	double school_marks[100];
	int count_marks;
	double average;
};

int main()
{
	Student students[1000];

	int n;
	cout << "Enter number of students: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin.ignore();
		cout << "Enter name: ";
		getline(cin, students[i].name);
		
		cout << "Enter ID: ";
		cin >> students[i].ID;

		cout << "Enter number of marks: ";
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

