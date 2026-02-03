
/*4) Дадени са дължините на n тройки отсечки
 *(ai, bi, ci, i=1,2,…,n). Да се състави алгоритъм,
 *`който намира броя на тройките, които образуват
равнобедрен триъгълник
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of triangles: ";
    cin >> n;

    int count = 0;
    for (int i = 0; i < n; i++) {
        double a, b, c;
        cout << "Write the number for each line: ";
        cin >> a >> b >> c;

        // checking if it is a triangle
        if (a + b > c && a + c > b && b + c > a) {
            // checking if its two of the sides are equal
            if (a == b || a == c || b == c) {
                count++;
            }
        }
    }
    cout << "Number of isosceles triangles: " << count << endl;
}
