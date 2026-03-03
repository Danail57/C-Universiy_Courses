/*Да се реализира като съставна програма следната задача
Да се намери при кое от зададени цели числа
сумата от квадратите на нечетните цифри е по-голяма.
 */

#include <iostream>
#include <cmath>
using namespace std;

int biggest_digit_odd_square_sum(int number)
{
 int sum = 0;
 while (number != 0)
 {
  int digit = number % 10;
  if (digit % 2 != 0)
  {
   sum += digit * digit;
  }
  number /= 10;
 }
 return sum;
}

int main()
{
 int n;
 cout << "How many numbers you will write? "; cin >> n;
 int number, max_number;
 int max_sum = -1;

 for (int i = 0; i < n; i++)
 {
  cout << "Write number: ";
  cin >> number;

  int current_sum = biggest_digit_odd_square_sum(number);
  if (current_sum > max_sum)
  {
   max_sum = current_sum;
   max_number = number;
  }
 }
 cout << "The number with the biggest digit odd square sum is: " << max_number << endl;
 cout << "Sum = " << max_sum << endl;
}
