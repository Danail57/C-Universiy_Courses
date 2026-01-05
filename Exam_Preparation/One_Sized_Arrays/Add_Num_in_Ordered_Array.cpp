/* Въведен е масив подреден в нарастващ ред.
Да се добави още един елемент в масива, 
така че той също да е подреден.*/

#include <iostream>
using namespace std;

void ordered_array(int numbers[], int &n, int new_element)
{
	int i;
	for (i = n - 1; (i >= 0 && numbers[i] > new_element); i--)
	{
		numbers[i + 1] = numbers[i];
	}
	numbers[i + 1] = new_element;
	n++;
}

int main()
{
	int numbers[100];
	int n;

	cout << "Enter how many numbers: ";
	cin >> n;

	cout << "Enter numbers in increasing order: ";
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}
	
	int new_element;
	cout << "Enter the new element to insert: ";
	cin >> new_element;

	ordered_array(numbers, n, new_element);
	cout << "Array after the insertion: ";
	for (int i = 0; i < n; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
	return 0;
}
