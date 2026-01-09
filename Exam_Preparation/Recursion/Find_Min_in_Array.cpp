//Зададени са два едномерни целoчислeни масива 
// А0, А1,...,Аm-1 и B0, B1,...,Bn-1.
// Да се състави рекурсивна програма, 
// която намира сумата
// от най-малката стойност в масива А 
// и най-малката стойност в масива B.  

#include <iostream>
using namespace std;

int find_min(int array[], int n)
{
	if (n == 1)
		return array[0];
	int min_rest = find_min(array + 1, n - 1);
	return (array[0] < min_rest) ? array[0] : min_rest;
}

int main()
{
	int m, n;
	cout << "Enter size of array A: ";
	cin >> m;

	int A[1000];
	cout << "Elements for A: ";
	for (int i = 0; i < m; i++)
	{
		cin >> A[i];
	}
	

	cout << "Enter size of array B: ";
	cin >> n;
	
	int B[1000];
	cout << "Elements for B: ";
	for (int i = 0; i < n; i++)
	{
		cin >> B[i];
	}
	
	int min_A = find_min(A, m);
	int min_B = find_min(B, n);
	cout << "Sum of minimums = " << (min_A + min_B) << endl;
	return 0;
}


