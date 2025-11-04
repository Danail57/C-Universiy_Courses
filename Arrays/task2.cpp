// Create a program to find the average positive sum of elements in an array.

#include <iostream>
using namespace std;

int main()
{


    int Nc = 10000;
	int N;
	cout << "Enter how many numbers you want to write: ";
	cin >> N;


	int arr[10000];
    for (int i = 0; i < N; i++) {
		cout << "Enter number " << i + 1 << ": ";
		cin >> arr[i];
	}
	int sum_positive = 0;
	int count_positive = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i] > 0) {
            sum_positive += arr[i];
            count_positive++;
        }
    }
    if (count_positive > 0) {
        double average = (double)sum_positive / count_positive;
        

        cout << "Average of positive numbers: " << average << endl;
    }
    else {
        cout << "No positive numbers entered." << endl;
    }

    return 0;
}

