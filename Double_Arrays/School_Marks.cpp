// Да се напише програма, пресмятаща средния успех на 
// учениците. Ако ученикът е получил слаба оценка, 
// изведете броя на слабите оценки. Ако няма слаби оценки, 
// тогава изчислете средният му успех.

#include <iostream>
using namespace std;

int main()
{
	int students;
	cout << "Enter the number of students: ";
	cin >> students;

	int school_marks;
	cout << "Enter the number of marks: ";
	cin >> school_marks;

	int A[100][100];

	cout << "Enter the marks: ";
	for (int i = 0; i < students; i++)
	{
		for (int j = 0; j < school_marks; j++)
		{
			cin >> A[i][j];
		}
	}


	for (int i = 0; i < students; i++)
	{
		float count_marks = 0;
		float sum = 0;
		int poor_marks = 0;
		
		for (int j = 0; j < school_marks; j++)
		{
			if (A[i][j] == 2) // проверяваме дали има 2
			{
				poor_marks += 1; // броим слаби оценки
			}
			else
			{
				count_marks++;
				sum += A[i][j];
			}
		}
		if (poor_marks)
		{
			cout << "The number of poor marks: " << poor_marks << endl;
		}
		else
		{
			cout << "The average success is: " << sum / count_marks << endl;
		}
	}
}
