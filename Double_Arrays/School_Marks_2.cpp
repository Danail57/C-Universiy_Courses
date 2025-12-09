/*.Имаме студенти и оценки
Ако има слаби оценки (2) → печатаме
броя на слабите оценки
Ако няма слаби оценки → печатаме средно аритметично  */


#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of grades: ";
    cin >> n;

    int grades[100];

    for (int i = 0; i < n; i++)
    {
        cout << "Grade[" << i + 1 << "]: ";
        cin >> grades[i];
    }

    int count_weak = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (grades[i] == 2)
        {
            count_weak++;
        }
        sum += grades[i];
    }

    if (count_weak > 0)
    {
        cout << "\nNumber of weak grades: " << count_weak << endl;
    }
    else
    {
        double average = double(sum) / n;
        cout << "\nAverage grade: " << average << endl;
    }

    return 0;
}
