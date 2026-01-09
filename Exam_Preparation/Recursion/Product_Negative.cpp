// Да се състави програма с рекурсивна функция
// за намиране  произведението на
// отрицателните елементи на едномерен 
// масив с n елемента.  


#include <iostream>
using namespace std;

int product_negative(int A[], int n)
{
	if (n == 0)
		return 1;
	if (A[n - 1] < 0)
		return A[n - 1] * product_negative(A, n - 1);
	return product_negative(A, n - 1);

}

int main()
{
	int n;
	cout << "Enter how many numbers you want to write: ";
	cin >> n;

	int A[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	int result = product_negative(A, n);
	cout << "Product of negative elements: " << result;
	return 0;
}
