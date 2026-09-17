
// 1. програма за извеждане на броя нулите и средноар.  на + ел.
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	cout << "Write the size of the array: ";
	cin >> n;

	int A[1000];
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i + 1 << "]: ";
		cin >> A[i];
	}

	int count_zeros = 0;
	int count_positives = 0;
	double sum_positives = 0;

	for (int i = 0; i < n; i++)
	{
		if (A[i] == 0)
		{
			count_zeros++;
		}

		if (A[i] > 0)
		{
			sum_positives += A[i];
			count_positives++;
		}
	}

	cout << "Number of zeros: " << count_zeros << endl;

	if (count_positives > 0)
	{
		double average_positive = sum_positives / count_positives;
		cout << "Average posititve: " << fixed << setprecision(2) << average_positive << endl;
	}
	else
	{
		cout << "No positive elements to calculate an average." << endl;
	}

}
