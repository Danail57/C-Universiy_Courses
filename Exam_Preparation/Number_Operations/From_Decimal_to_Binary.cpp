// Да се състави програма 
// за превръщане на  цяло десетично 
// число в двоично. 

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
	unsigned long long number;
	cout << "Enter a number: ";
	cin >> number;
	vector<int> bit_vector;

	while (number > 0)
	{
		bit_vector.push_back(number % 2);
		number /= 2;
	}
	for (int i = bit_vector.size() - 1; i >= 0; i--)
	{
		cout << bit_vector.at(i);
	}
}
