
/*4)Оценките на m студенти по n дисциплини
 *се въвеждат в двумерен масив. Да се създаде и
 *изведе нов масив, който съдържа средните оценки
 *по всяка дисциплина, като не се вземат
 *под внимание слабите оценки.
*/

#include <iostream>
#include <string>
using namespace std;


int main()
{
    int n;
    cout << "Enter the number of school subjects: ";
    cin >> n;

    int m;
    cout << "Number of students? ";
    cin >> m;

    int A[60][60];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "A["<< i + 1 << "]["<< j + 1 << "] = ";
            cin >> A[i][j];
        }
    }
    double average_grade[1000];

    for (int i = 0; i < n; i++) {
        double sum = 0;
        int count = 0;
        for (int j = 0; j < m; j++) {
            if (A[i][j] > 2.0) {
                sum += A[i][j];
                count++;
            }
        }
        if (count > 0)
            average_grade[i] = sum / count;
        else
            average_grade[i] = 0;
    }
    cout << "\nAverage grades per subject (without failing grades):\n";
    for (int i = 0; i < n; i++) {
        cout << "Subject " << i + 1 << ": " << average_grade[i] << endl;
    }
    return 0;
}
