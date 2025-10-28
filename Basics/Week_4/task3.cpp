#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of students: ";
	cin >> n;


	double marks[n]; // we create onesized array for marks
	double sum = 0;

	cout << "Enter marks from 2 to 6: \n";

	for (int i = 0; i < n; i++)
	{
		cout << "Student mark " << i + 1 << ": ";
		cin >> marks[i];
		sum += marks[i];
	
	}
	double average = sum / n;  // we divide the sum on the students count
	cout << "\nThe average is: " << average << endl;
	return 0;
}
