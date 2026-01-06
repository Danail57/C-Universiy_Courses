// string.empty() - returns true if empty

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string first_name;
	cout << "Enter your first name: ";
	getline(cin, first_name);

	if (first_name.empty())
	{
		cout << "You did not enter a name!";
	}
	else
	{
		cout << "Welcome " << first_name;
	}
	cout << endl;
	return 0;
}
