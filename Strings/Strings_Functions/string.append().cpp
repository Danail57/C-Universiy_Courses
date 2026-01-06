// string.append() - appends a string

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string user_name;
	cout << "Enter your first username: ";
	getline(cin, user_name);

	string email = user_name.append("@gmai.com");
	cout << "Your email is now: " << email << endl;
	cout << endl;
	return 0;
}
