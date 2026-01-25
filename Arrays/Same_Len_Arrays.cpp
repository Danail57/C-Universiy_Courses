/*Имате две редици съдържащи естествени числа. 
Стойностите на 1-вата редица са въведени 
предварително, а във втората се въвеждат от 
клавиатурата.
Да се състави програма (C++), чрез която се 
проверява дали всички числа от първата редица
са числа и от втората редица, т.е. дали първата и
вторта редица съдържат еднакви елементи.*/

#include <iostream> 
using namespace std;

bool array_equals(int* a1, int len1, int* a2, int len2)
{
	if (len1 != len2)
		return false;
	bool used[100] = { false };

	for (int i = 0; i < len1; i++)
	{
		bool found = false;
		for (int j = 0; j < len2; j++)
		{
			if (!used[j] && a1[i] == a2[j])
			{
				used[j] = true;
				found = true;
				break;
			}
		}
		if (!found)
			return false;
	}
	return true;
}

int main()
{
	int a1[] = { 1,2,3,4,5 };
	int len1 = 5;

	int len2;
	cout << "Enter the count of the elements: ";
	cin >> len2;

	int a2[100];
	cout << "Write the elements:\n";
	for (int i = 0; i < len2; i++)
	{
		cin >> a2[i];
	}
	if (array_equals(a1, len1, a2, len2))
		cout << "Equal elements.";
	else
		cout << "Not equal elements.";
	return 0;
}
