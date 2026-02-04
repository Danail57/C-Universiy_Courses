

/*17)Да се състави програма, която намира разликата между сумата
от третите степени на четните цифри и сумата от вторите степени на
нечетните цифри на зададено цяло число.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Write an innteger: ";
    cin >> n;

    n = abs(n);
    int sum_even = 0;
    int sum_odd = 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 == 0) {
            sum_even += digit * digit * digit;
        } else {
            sum_odd += digit * digit;
        }
        n /= 10;
    }
    int result = sum_even - sum_odd;
    cout << "Result = " << result << endl;
    return 0;
}
