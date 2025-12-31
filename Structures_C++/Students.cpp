
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
#include <cstring>
using namespace std;

struct Date {
    int D, M, G;
};

struct Student {
    char name[31];
    long FN;
    Date birth;
    short group;
    int count_grades;
    int grades[20];
    float average;
};

int main() 
{
    Student students[25];
    int n;

    do {
        cout << "Enter number of students (1-25): ";
        cin >> n;
    } while (n < 1 || n > 25);

    for (int i = 0; i < n; i++) {
        cin.ignore(); 

        cout << "Enter name: ";
        cin.getline(students[i].name, 31);

        cout << "Enter faculty number: ";
        cin >> students[i].FN;

        cout << "Enter birth date (day month year): ";
        cin >> students[i].birth.D >> students[i].birth.M >> students[i].birth.G;

        cout << "Enter group: ";
        cin >> students[i].group;

        cout << "Enter number of grades: ";
        cin >> students[i].count_grades;

        for (int j = 0; j < students[i].count_grades; j++) {
            cout << "Enter grade " << j + 1 << ": ";
            cin >> students[i].grades[j];
        }

        
        int sum = 0;
        for (int j = 0; j < students[i].count_grades; j++)
            sum += students[i].grades[j];
        students[i].average = (float)sum / students[i].count_grades;
    }


    int max_avg_index = 0, min_avg_index = 0;
    for (int i = 1; i < n; i++) 
    {
        if (students[i].average > students[max_avg_index].average)
            max_avg_index = i;
        if (students[i].average < students[min_avg_index].average)
            min_avg_index = i;
    }

    cout << "\nStudent with highest average: " << students[max_avg_index].name
        << " (" << students[max_avg_index].average << ")" << endl;
    cout << "Student with lowest average: " << students[min_avg_index].name
        << " (" << students[min_avg_index].average << ")" << endl;

    cout << "\nStudents with average > 5.0:\n";
    for (int i = 0; i < n; i++)
        if (students[i].average > 5.0)
            cout << students[i].name << " (" << students[i].average << ")\n";

    cout << "\nStudents with at least one grade 6:\n";
    for (int i = 0; i < n; i++) {
        bool has_six = false;
        for (int j = 0; j < students[i].count_grades; j++) 
        {
            if (students[i].grades[j] == 6) {
                has_six = true;
                break;
            }
        }
        if (has_six)
            cout << students[i].name << endl;
    }

    int youngest_index = 0, oldest_index = 0;
    for (int i = 1; i < n; i++) 
	{
        // Най-млад: по-голяма година, после месец и после ден
        if (students[i].birth.G > students[youngest_index].birth.G ||
            (students[i].birth.G == students[youngest_index].birth.G && students[i].birth.M > students[youngest_index].birth.M) ||
            (students[i].birth.G == students[youngest_index].birth.G && students[i].birth.M == students[youngest_index].birth.M && students[i].birth.D > students[youngest_index].birth.D))
            youngest_index = i;

        // Най-стар: по-малка година, после месец и после ден
        if (students[i].birth.G < students[oldest_index].birth.G ||
            (students[i].birth.G == students[oldest_index].birth.G && students[i].birth.M < students[oldest_index].birth.M) ||
            (students[i].birth.G == students[oldest_index].birth.G && students[i].birth.M == students[oldest_index].birth.M && students[i].birth.D < students[oldest_index].birth.D))
            oldest_index = i;
    }

    cout << "\nYoungest student: " << students[youngest_index].name << endl;
    cout << "Oldest student: " << students[oldest_index].name << endl;

    return 0;
}
