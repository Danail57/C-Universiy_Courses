/*Дадени са два масива a и b, които съдържат
оценките на n студенти по два предмета. 
Да се намери номера на студента с най-висок успех
и броя на студентите, които нямат 
двойки по някой от тези предмети.*/

#include <iostream> 
using namespace std;

int main()
{
	int n;
	cout << "How many students you want? ";
	cin >> n;


	int a[10000], b[10000];

	cout << "Enter grades for IT:\n";
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << "Enter grades for Maths:\n";
	for (int i = 0; i < n; i++)
		cin >> b[i];

	int max_sum = -1;
	int best_student = -1;
	int no_poor_marks = 0;

	for (int i = 0; i < n; i++)
	{
		int sum = a[i] + b[i];
		if (sum > max_sum)
		{
			max_sum = sum;
			best_student = i + 1;
		}
		if (a[i] != 2 && b[i] != 2)
		{
			no_poor_marks++;
		}
	}
	cout << "Student with highest grades: " << best_student << endl;
	cout << "Number of students without 2: " << no_poor_marks << endl;
	return 0;
}
