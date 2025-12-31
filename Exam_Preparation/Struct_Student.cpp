#include <iostream>
#include <string>

using namespace std;

struct Student {
	string name;
	int age;
	float grades[1000];
	int count_marks;
	double average;
};

int main()
{
	Student students[1000];

	int n;
	cout << "Enter a number of students: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin.ignore();
		cout << "Enter a name: ";
		getline(cin, students[i].name);

		cout << "Enter the age: ";
		cin >> students[i].age;

		cout << "Enter a number for marks: ";
		cin >> students[i].count_marks;

		double sum = 0;
		for (int j = 0; j < students[i].count_marks; j++)
		{
			cout << "Enter mark " << j + 1 << ": ";
			cin >> students[i].grades[j];
			sum += students[i].grades[j];
		}
		students[i].average = sum / students[i].count_marks;
	}

	int min_average = 0;
	int max_average = 0;
	for (int i = 1; i < n; i++)
	{
		if (students[i].average < students[min_average].average)
			min_average = i;
		if (students[i].average > students[max_average].average)
			max_average = i;
	}
	cout << "\nStudents with lowest average: " << students[min_average].name << " (" << students[min_average].average << ")\n";
	cout << "\nStudents with highest average: " << students[max_average].name << " (" << students[max_average].average << ")\n";


	int longest_name = 0;
	int shortest_name = 0;
	for (int i = 1; i < n; i++)
	{
		if (students[i].name.length() > students[longest_name].name.length())
			longest_name = i;
		if (students[i].name.length() < students[shortest_name].name.length())
			shortest_name = i;
	}
	cout << "\nLongest name: " << students[longest_name].name << endl;
	cout << "\nShortest name: " << students[shortest_name].name << endl;
	return 0;
}
