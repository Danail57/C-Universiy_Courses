/*Даден е масив от n цели числа.
Да се изведат само уникалните елементи 
(които се срещат точно 1 път).*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 40;

int main()
{
	int n;
	cout << "Enter elements between 1 and " << MAX_SIZE << endl;
	cin >> n;

	int A[MAX_SIZE];
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i + 1<< "]: ";
		cin >> A[i];
	}

	bool visited[MAX_SIZE] = { false };
	
	cout << "Unique elements: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (visited[i])
			continue;
		bool is_unique = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (A[i] == A[j])
			{
				is_unique = false;
				visited[j] = true;
			}
		}
		if (is_unique)
		{
			cout << A[i] << " ";
		}
	}
	return 0;
}
