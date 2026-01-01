#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter how many numbers you want to write: ";
	cin >> n;

	int numbers[1000];
	int searched_element;

	cout << "Enter the number to search for: ";
	cin >> searched_element;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter number " << i + 1 << ": ";
		cin >> numbers[i];
	}
	
	bool found = false;
	for (int i = 0; i < n; i++)
	{
		if (numbers[i] == searched_element)
		{
			cout << "Number found at position " << i + 1 << endl;
			found = true;
		}
	}
	if (!found)
	{
		cout << "Number not found in the list." << endl;
	}
	return 0;
	
}
