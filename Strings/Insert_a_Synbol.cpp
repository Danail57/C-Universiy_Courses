/*Дефинирайте функция, която вмъква даен символ
в сортиран във възходящ ред символен 
низ като запазва наредбата на символите*/

#include <iostream>
#include <cstring>
using namespace std;

char* insert_sorted(char c, char* a)
{
	int n = strlen(a);
	char* result = new char[n + 2];
	int i = 0;

	while (i < n && a[i] < c)
	{
		result[i] = a[i];
		i++;
	}
	result[i] = c;
	while (i < n)
	{
		result[i + 1] = a[i];
		i++;
	}
	result[n + 1] = '\0';
	return result;
}

int main()
{
	char text[1200];
	char c;

	cout << "Enter sorted text: ";
	cin >> text;

	cout << "Enter symbol text to insert: ";
	cin >> c;

	char* result = insert_sorted(c, text);
	cout << "Result: " << result << endl;
	delete[] result;
	return 0;   

}
