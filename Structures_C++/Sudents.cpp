# work in progress

/*Въвежда n студенти (n <= 25), 
като за всеки студент се въвеждат:

име
ФН
дата на раждане (ден, месец, година)
група
брой оценки и оценките им
Изчислява средния успех на всеки студент.

Намира:
студента с най-висок среден успех
студента с най-нисък среден успех

Извежда:
всички студенти със среден успех по-висок от 5.0
всички студенти, които имат оценка 6
Намира най-младия и най-стария 
студент по дата на раждане.*/


#include <iostream>
#include <stdlib.h>
using namespace std;

struct student {
	char ime[31];
	long FN;
	struct RoDat {int D, M, G} rd;
	short group;
	int grades;
	float average;
};
int BrS;
student MasStudent[25];

int main()
{
	int n;
	do {
		cout << "Enter a number of students: ";
		cin >> n;
	} while (n < 1 || n > 25);

	for (int i = 0; i < n; i++)
	{
		cout << "Write the name: ";
		cin >> MasStudent[i].ime;

		cout << "Write the faculty number: ";
		cin >> MasStudent[i].FN;

		cout << "Write the group: ";
		cin >> MasStudent[i].group;

		cout << "Write the number for marks: ";
		for (int j = 0; j < MasStudent[i].grades; j++)
		{
			cout << "Enter mark " << j + 1 << ": " << endl;
			cin >> MasStudent[i].grades[j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		double sum = 0;
		int weak_count = 0;
		for (int j = 0; j < MasStudent[i].grades; j++)
		{
			sum += MasStudent[i].grades[j];
			if (MasStudent[i].grades[j] < 3)
				weak_count++;
		}
		MasStudent[i].average = sum / MasStudent[i].grades;
		cout << "Student: " << MasStudent[i].ime << endl;
		cout << "Average: " << MasStudent[i].average << endl;
		cout << "Weak marks: " << weak_count << endl;
	}
	int min_avg_index = 0;
	int max_avg_index = 0;
	for (int i = 1; i < n; i++)
	{
		if (MasStudent[i].average < MasStudent[min_avg_index].average)
			min_avg_index = i;
		if (MasStudent[i].average > MasStudent[max_avg_index].average)
			max_avg_index = i;
	}
	cout << "\nStudents with lowest average: " << MasStudent[min_avg_index].ime << " (" << MasStudent[min_avg_index].average << ")\n";
	cout << "\nStudents with highest average: " << MasStudent[max_avg_index].ime << " (" << MasStudent[max_avg_index].average << ")\n";

	cout << "\nStudent with at least one mark 6:\n";
	for (int i = 0; i < n; i++)
	{
		bool has_six = false;
		for (int j = 0; j < MasStudent[i].grades; j++)
		{
			if (MasStudent[i].grades[j] == 6)
			{
				has_six = true;
				break;
			}
		}
		if (has_six)
			cout << MasStudent[i].ime << endl;
	}
	int youngest_index = 0;
	int oldest_index = 0;
	for (int i = 1; i < n; i++)
	{

	}
}
