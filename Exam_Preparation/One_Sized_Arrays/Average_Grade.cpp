
/*39) Да се напише програма, която пресмята
 *средния успех на студентите и да им извежда успеха,
 *но ако има двойка, да изведе броя на слабите оценки
 *
*/

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int n;
    double grade;
    double sum = 0;
    int fail_count = 0;

    cout << "Enter the number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Write a grade for student " << i + 1 << ": ";
        cin >> grade;
        sum += grade;

        if (grade < 3.0) {
            fail_count++;
        }
    }
    if (fail_count > 0)
    {
        cout << "Number of failing grades: " << fail_count << endl;
    }
    else
    {
        double average = sum / n;
        cout << "Average grade: " << average << endl;
    }
    return 0;
}
