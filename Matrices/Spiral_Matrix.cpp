/*Дадена е квадратна матрица n×m.
Обходи матрицата по спирала отвън навътре и:
за всеки елемент, който е простo число, го добави към сума
ако броят на простите елементи е четен → изведи сумата
иначе → изведи произведението им*/

#include <iostream>
using namespace std;

bool is_prime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int  n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    int A[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A["<< i + 1 <<"]["<< j + 1 << "]: = ";
            cin >> A[i][j];
        }
    }
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int sum = 0;
    long long product = 1;
    int count_primes = 0;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
           if (is_prime(A[top][j])) {
               sum += A[top][j];
               product *= A[top][j];
               count_primes++;
           }
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            if (is_prime(A[i][right])) {
                sum += A[i][right];
                product *= A[i][right];
                count_primes++;
            }
        }
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                if (is_prime(A[bottom][j])) {
                    sum += A[bottom][j];
                    product *= A[bottom][j];
                    count_primes++;
                }
            }
            bottom--;
        }
        if (left  <= right) {
            for (int i = bottom; i >= top; i--) {
                if (is_prime(A[i][left])) {
                    sum += A[i][left];
                    product *= A[i][left];
                    count_primes++;
                }
            }
            left++;
        }
    }
    cout << "\nPrime count = " << count_primes << endl;
    if (count_primes % 2 == 0)
        cout << "Sum = " << sum << endl;
    else
        cout << "Product = " << product << endl;
    return 0;
}
