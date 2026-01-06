// string.clear() - clears a string

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string first_name;
	cout << "Enter your first name: ";
	getline(cin, first_name);

	cout << "Welcome " << first_name << endl;
	cout << "Your name has been cleared." << endl;
	first_name.clear();

	cout << "Welcome " << first_name << endl;
	cout << endl;
}
