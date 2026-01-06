// string1.find(string2) - returns index of string2

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string first_name;
	cout << "Enter your user name: ";
	getline(cin, first_name);

	string substring;
	cout << "Search for which character/s?: ";
	getline(cin, substring);

	int position = first_name.find(substring);
	cout << "Found character/s at position: " << position << endl;

	cout << endl;
	return 0;
}
