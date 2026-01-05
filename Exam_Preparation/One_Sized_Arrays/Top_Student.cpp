/*Дадени са два масива a и b, които съдържат
оценките на n студенти по два предмета. 
Да се намери номера на студента с най-висок успех
и броя на студентите, които нямат двойки по
някой от тези предмети.
.*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of students: ";
	cin >> n;

	int a[100], b[100];
	int school_marks;

	cout << "Enter school marks for subject 1: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << "Enter school marks for subject 2: ";
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	int top_student_index = 0;
	double max_average = (a[0] + b[0]) / 2.0;
	int count_no_poor_marks = 0;

	for (int i = 0; i < n; i++)
	{
		double average = (a[i] + b[i]) / 2.0;

		if (average > max_average)
		{
			max_average = average;
			top_student_index = i;
		}
		if (a[i] > 2 && b[i] > 2)
		{
			count_no_poor_marks++;
		}
	}
	cout << "Top student is #" << top_student_index + 1 << " with average marks: " << max_average << endl;
	cout << "Number of students without poor mark: " << count_no_poor_marks << endl;
	return 0;

}
