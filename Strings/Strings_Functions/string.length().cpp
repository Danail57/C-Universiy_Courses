// string.length() - returns length of a string

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string first_name;
	cout << "Enter your first name: ";
	getline(cin, first_name);

	if (first_name.length() >= 12)
	{
		cout << "Your name can not be over 12 chars long.";
	}
	else
	{
		cout << "Welcome " << first_name;
	}
	cout << endl;
	return 0;
}
