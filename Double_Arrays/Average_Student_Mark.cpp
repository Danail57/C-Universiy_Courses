//Даден е двумерен масив, съдържащ оценките 
// на група от m студенти по n дисциплини. 
// Да се създаде нов масив, 
// съдържащ средния успех на всеки студент. 

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int m_students;
	cout << "Enter the number of students: ";
	cin >> m_students;

	int n_subjects;
	cout << "Enter the number of school disciplines: ";
	cin >> n_subjects;

	int A[1000][1000];

	for (int i = 0; i < m_students; i++)
	{
		cout << i + 1 << " student\n";
		for (int j = 0; j < n_subjects; j++)
		{
			cout << i + 1 << " school mark\n";
			cin >> A[i][j];
		}
	}

	float average_mark[100];
	for (int i = 0; i < m_students; i++)
	{
		float sum = 0;
		for (int j = 0; j < n_subjects; j++)
		{
			sum += A[i][j];
		}
		average_mark[i] = sum / n_subjects;
	}

	cout << "Rate success of students:\n";
	for (int i = 0; i < m_students; i++)
	cout <<'\t' << i + 1 << " student:" << average_mark[i] << endl;
}
