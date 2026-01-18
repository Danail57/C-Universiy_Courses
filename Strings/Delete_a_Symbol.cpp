/*Даден е символен низ, сортиран в НИЗХОДЯЩ ред.
Да се дефинира функция, която премахва даден
символ от низа, като запазва подредбата.*/

#include <iostream>
#include <cstring>
using namespace std;

char* remove_char_sorted(char c, char* a)
{
	int n = strlen(a);
	char* result = new char[n];
	int i = 0, k = 0;
	bool removed = false;

	while (i < n)
	{
		if (a[i] == c && !removed)
		{
			removed = true;
		}
		else
		{
			result[k] = a[i];
			k++;
		}
		i++;
	}
	result[k] = '\0';
	return result;
}

int main()
{
	char text[1200];
	char c;

	cout << "Enter sorted text: ";
	cin >> text;

	cout << "Enter symbol text to delete: ";
	cin >> c;

	char* result = remove_char_sorted(c, text);
	cout << "Result: " << result << endl;
	delete[] result;
	return 0;
}
