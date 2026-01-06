// string1.erase(int x, int y) - erases portion of a string

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string phone_number;
	cout << "Enter your phone number: ";
	getline(cin, phone_number);

	phone_number.erase(0, 4);
	cout << "Phone number: " << phone_number;
	
	cout << endl;
	return 0;
}
