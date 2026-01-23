/*Да се състави програма, чрез която се 
въвеждат 7 естествени числа от интервала 
[0..5000] в едномерен масив. 
Програмата да извежда броя на цифрите 
на получената сума.*/

#include <iostream>
using namespace std;

int main()
{
	int A[7];
	int sum = 0;

	for (int i = 0; i < 7; i++)
	{
		cin >> A[i];
		sum += A[i];
	}
	int count_digits = 0;
	int temp = sum;

	if (temp == 0)
	{
		count_digits = 1;
	}
	else
	{
		while (temp > 0)
		{
			count_digits++;
			temp /= 10;
		}
	}
	cout << "The count of digits: " << count_digits << endl;
	cout << "Sum = " << sum << endl;
	return 0;
}
