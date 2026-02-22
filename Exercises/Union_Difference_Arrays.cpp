/*Да се напише програма на с++,
 *която намира сечението, обединението и
 *разликата на два масива
 */

#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Enter the number of array 1: ";
    cin >> a;

    int A[100];
    for (int i = 0; i < a; i++) {
        cout << "A["<< i + 1 <<"] = ";
        cin >> A[i];
    }

    int b;
    cout << "Enter the number of array 2: ";
    cin >> b;
    int B[100];
    for (int i = 0; i < b; i++) {
        cout << "B["<< i + 1 <<"] = ";
        cin >> B[i];
    }

    cout << "Intersection:" << endl;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (A[i] == B[j])
            {
                cout << A[i] << " = " << B[j] << endl;
                break;
            }
        }
    }
    cout << "Union:" << endl;
    for (int i = 0; i < a; i++)
        cout << A[i] << " ";
    for (int i = 0; i < b; i++)
    {
        bool found = false;
        for (int j = 0; j < a; j++)
        {
            if (B[i] == A[j])
            {
                found = true;
                break;
            }
        }
        if (!found) cout << B[i] << " ";
    }

    cout << "\nDifference (A - B):" << endl;
    bool found_any = false; 

    for (int i = 0; i < a; i++)
    {
        bool found_in_B = false;
        for (int j = 0; j < b; j++)
        {
            if (A[i] == B[j]) {
                found_in_B = true;
                break;
            }
        }
        if (!found_in_B) {
            cout << A[i] << " ";
            found_any = true;
        }
    }
    if (!found_any) {
        cout << "Empty Array" << endl;
    }
    cout << endl;
}
