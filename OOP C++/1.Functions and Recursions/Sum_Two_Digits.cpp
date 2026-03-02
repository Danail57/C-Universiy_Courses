/*Да се реализира като съставна програма следната задача
Да се намери при кое от две зададени
цели числа сумата от цифрите е по-голяма.
 */
#include <iostream>
using namespace std;

int biggest_digit_sum(int number)
{
 int sum = 0;
 while (number != 0)
 {
  int digit = number % 10;
  number /= 10;
  sum += digit;
 }
 return sum;
}

int main()
{
 int n, m   ;
 cout << "Write two numbers: "; cin >> n >> m;
 int sum1 = biggest_digit_sum(n);
 int sum2 = biggest_digit_sum(m);
 if (sum1 > sum2)
 {
  cout << "Biggest number = " << n << endl;
  cout << "Sum = " << sum1 << endl;
 }

 else if (sum2 > sum1)
 {
  cout <<"Biggest number = " << m << endl;
  cout << "Sum = " << sum2 << endl;
 }

 else
 {
  cout << "Both numbers have equal sum." << endl;
 }
 return 0;
}
