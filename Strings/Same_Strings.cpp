// Да се състави програма, която проверява
// дали два зададени символни низа са еднакви

#include <iostream>
#include <locale>

using namespace std;

int main()
{
	string text;
	cout << "Enter a text: ";
	getline(cin, text);

	string text_2;
	cout << "Enter another text: ";
	getline(cin, text_2);

	if (text != text_2)
	{
		cout << "Texts are not same.";
	}
	else
	{
		cout << "Texts are same.";
	}
	return 0;
}
