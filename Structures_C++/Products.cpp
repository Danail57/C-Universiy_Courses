/*ЗАДАЧА 5: Product

Структура Product:
име
цена
количество

Задача:
Въвеждате n продукта

Изчислявате общата стойност (цена × количество)

Извеждате продуктите с количество < 5*/

#include <iostream>
#include <limits>
#include <string>
using namespace std;

struct Product {
	string name;
	float price;
	int quantity;
};

int main()
{
	Product products[1000];

	int n;
	cout << "Enter the number of products: ";
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 0; i < n; i++)
	{
		cout << "Write the name: ";
		getline(cin, products[i].name);

		cout << "Write the price: ";
		cin >> products[i].price;

		cout << "Write the quantity: ";
		cin >> products[i].quantity;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double total = 0;
	for (int i = 0; i < n; i++)
		total += products[i].quantity * products[i].price;
	cout << "\nTotal value of all products: " << total << endl;

	cout << "Products with quantity < 5:\n";
	for (int i = 0; i < n; i++)
	{
		if (products[i].quantity < 5)
			cout << products[i].name << endl;
	}
	return 0;
}
