// string.insert(int x, int y) - insert a string with other string

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string user_name;
	cout << "Enter your user name: ";
	getline(cin, user_name);

	user_name.insert(0, "@");
	cout << "Reply: " << user_name;

	cout << endl;
	return 0;
}
