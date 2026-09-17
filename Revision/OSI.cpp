
/*Дадени са три цели неотрицателни числа a, b, c. 
Необходимо е да се подредят в някакъв ред и между тях да се 
поставят знаците + (за събиране), - (за изваждане) или 
* (за умножение), така че като се пресметне получения 
аритметичен израз неговата стойност да е възможно най-малка.
Между всяка двойка съседни числа може да има само един знак.
Всеки знак може да се използва само един път. Да се състави
алгоритъм и напише програма, която решава тази задача.*/


#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;




int evaluate_multiplication(int a, int b, int c, char operation_1, char operation_2)
{
	auto apply_operation = [](int a, int b, char operation)
	{
		if (operation == '+') return a + b;
		if (operation == '-') return a - b;
		if (operation == '*') return a * b;
		return 0;
	};
	
	if (operation_2 == '*')
	{
		int temp = apply_operation(b, c, '*');
		return apply_operation(a, temp, operation_1);
	}

	if (operation_1 == '*')
	{
		int temp = apply_operation(temp, c, operation_2);
	}
	int temp = apply_operation(a, b, operation_1);
	return apply_operation(temp, c, operation_2);
}


void permutation_digits(vector<int>digits)
{
	int n = digits.size();
	if (n == 0) return;

	int minimal_value = 0;

	bool initialized = false;
    vector<char> symbols = {'+', '-', '*'};

	sort(digits.begin(), digits.end());

	do {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == j) continue;
				char
			}
		}
	} while (next_permutation(digits.begin(), digits.end()));
	cout << "Minimal possible value: " << minimal_value << endl;
}


int main()
{
	int a, b, c;
	cout << "Write three numbers: ";
	cin >> a >> b >> c;

	
	vector<int> digits;
	digits.push_back(a);
	digits.push_back(b);
	digits.push_back(c);


	//unordered_map<int, string> digits = {{a, "+"}, {b, "-"}, {c, "*"}};
	//vector<int>digits = {a, b, c};
	//int minimal_value;
	
}
