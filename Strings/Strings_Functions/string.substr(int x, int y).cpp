// string.substr(int x, int y) - retrieve a portion of a string

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string first_name;
	cout << "Enter your first name: ";
	getline(cin, first_name);

	string nickname = first_name.substr(0, 3);
	cout << "Your nickname is: " << nickname << endl;
	cout << "Hello " << nickname;

	cout << endl;
	return 0;
}
