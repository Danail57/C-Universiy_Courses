/*  Даден е двумерен масив А с m реда и n стълба.
 *  Да се състави програма, която създава нов масив
 *  а0, а1,...,аm-1, като стойността на аi
 *  е равна на средно-аритметичното
 *  на елементите в i-ия ред, които са
 *  в интервала [p,q], където
 *  p и q са зададени и p<q.
 */

#include <iostream>
#include <cmath>
using namespace std;

void type_elements_array(int array[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << " = " ;
        cin >> array[i];
    }
}

double average_elements_array(int array[], int n, int p, int q)
{
    double sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] >= p && array[i] <= q) {
            sum += array[i];
            count++;
        }
    }
    if (count == 0) return 0;
    return sum / count;
}

int main()
{
    int m, n, p, q;
    cout << "Enter number of rows (m): "; cin >> m;
    cout << "Enter number of columns (n): "; cin >> n;
    cout << "Limits p and q (p < q): "; cin >> p >> q;

    double result_array[m];
    for (int i = 0; i < m; i++)
    {
        int temp_row[n];
        cout << "\nEnter the elements for row: " << i + 1 << ":" << endl;
        type_elements_array(temp_row, n);
        result_array[i] = average_elements_array(temp_row, n, p, q);
    }
    cout << "Average:" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << "a["<< i + 1 <<"] = " << result_array[i] << endl;
    }
    return 0;
}
