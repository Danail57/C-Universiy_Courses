// string.at() - returns a char at a given string

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string first_name;
	string middle_name;
	string last_name;

	cout << "Enter your first name: ";
	getline(cin, first_name);

	cout << "Enter your middle name: ";
	getline(cin, middle_name);

	cout << "Enter your last name: ";
	getline(cin, last_name);

	char letter_1 = first_name.at(1);
	char letter_2 = middle_name.at(1);
	char letter_3 = last_name.at(1);
	cout << "Your initials are: " << letter_1 << letter_2 << letter_3 << endl;

	cout << endl;
	return 0;
}
