/*Да се реализира като съставна програма следната задача
Да се намери при кое от зададени
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
 int m;
 cout << "Enter how many numbers you want to write: ";
 cin >> m;
 int number, max_number = 0;
 int max_sum = -1;

 for (int i = 0; i < m; i++)
 {
  cout << "Write number " << i + 1 << ": ";
  cin >> number;

  int current_sum = biggest_digit_sum(number);
  if (current_sum > max_sum)
  {
   max_sum = current_sum;
   max_number = number;
  }
 }
 cout << "Number with the biggest digit sum = " << max_number << endl;
 cout << "Sum = " << max_sum << endl;
}
