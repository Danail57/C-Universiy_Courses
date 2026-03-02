/*Да се реализира като съставна програма следната задача
Да се намери при кое от две зададени
цели числа сумата на четните цифри е по-голяма
 */
#include <iostream>
using namespace std;

int biggest_digit_even_sum(int number)
{
 int sum = 0;
 while (number != 0)
 {
  int digit = number % 10;
  if (digit % 2 == 0)
  {
   sum += digit;
  }
  number /= 10;
 }
 return sum;
}

int main()
{
 int m, n;
 cout<<"m = "; cin >> m;
 cout<<"n =  "; cin >> n;

 cout<<biggest_digit_even_sum(m)<<endl;
 cout<<biggest_digit_even_sum(n)<<endl;

 int sum_m = biggest_digit_even_sum(m);
 int sum_n = biggest_digit_even_sum(n);
 cout << "Even digit sum of m: " << sum_m << endl;
 cout << "Even digit sum of n: " << sum_n << endl;

 if (sum_m > sum_n)
  cout << "Number with the biggest even digit sum: " << m << endl;
 else if (sum_n > sum_m)
  cout << "Number with the biggest even digit sum: " << n << endl;
 else
  cout << "Both numbers have equal even digit sums." << endl;
}
