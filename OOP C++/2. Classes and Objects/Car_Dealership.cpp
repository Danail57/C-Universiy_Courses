//Задача: Система за управление на автокъща(Car Dealership)
//Създайте програма на C++, която управлява информация за налични автомобили в автокъща.
//
//1. Дефинирайте клас Car със следните членове :
//Private:
//
//string registration_number(Регистрационен номер – напр. "CB1234AB")
//
//double price(Цена на автомобила)
//
//Public :
//
//	string brand(Марка – напр. "Toyota")
//
//	string model(Модел – напр. "Corolla")
//
//	int year(Година на производство)
//
//	void input_data() – метод за въвеждане на данните от клавиатурата.
//
//	void print_data() – метод за извеждане на информацията.
//
//	double get_price() – гетър за цената.
//
//	string get_reg_num() – гетър за регистрационния номер.
//
//	2. Напишете следните функции(извън класа) :
//	void show_cars_by_brand(const vector<Car>&stock, string search_brand)
//
//	Функцията да извежда всички данни за колите от дадена марка.
//
//	double average_price_after_year(const vector<Car>&stock, int year_limit)
//
//	Да изчислява и връща средната цена на всички автомобили, произведени след определена година(напр.след 2015 г.).
//
//	void find_special_numbers(const vector<Car>& stock)
//
//	Да извежда регистрационните номера на колите, чиято цена е над 5000 и регистрационният им номер 
// завършва на четна цифра(аналогично на проверката за пол в твоята задача).
//
//	3. Напишете main() функция с меню :
//Добавяне на нов автомобил във вектор.
//
//Търсене по марка.
//
//Изчисляване на средна цена за нови автомобили(след 2020 г.).
//
//Списък на коли с "късметлийски" номера(цена > 5000 и четен номер).
//
//Изход.

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Car {
private:
	string registration_number;
	double price;

public:
	string brand;
	string model;
	int year;
	void get_data();
	void display_data() const;

	string get_registration_number() const { return registration_number; };
	double get_price() const { return price; }
};


void Car::get_data()
{
	cout << "Brand: "; cin >> brand;
	cout << "Model: "; cin >> model;
	cout << "Year of manufacturing: "; cin >> year;
	cout << "Registration number: "; cin >> registration_number;
	cout << "Price: "; cin >> price;
}


void Car::display_data() const
{
	cout << "\nBrand: " << brand << endl;
	cout << "\nModel: " << model << endl;
	cout << "\nYear of manufacturing: " << year << endl;
	cout << "\nRegistration number: " << registration_number << endl;
	cout << "\nPrice: " << price << endl;
}


void show_cars_by_brand(const vector <Car>& stock, string search_brand)
{
	bool found = false;
	for (const auto& c : stock)
	{
		if (c.brand == search_brand)
		{
			c.display_data();
			found = true;
		}
	}
	if (!found)
		cout << "No cars from this brand: " << search_brand << endl; 
}


//	Да изчислява и връща средната цена на всички автомобили, произведени след определена година(напр.след 2015 г.).
double average_price_after_an_year(const vector <Car>& stock, int year_limit)
{
	int count_cars;
	double sum = 0;

	for (const auto& c : stock)
	{
		if (c.year > year_limit)
		{
			sum += c.get_price();
			count_cars++;
		}
	}
	if (count_cars == 0) return 0;
	return sum / count_cars;
}


//	Да извежда регистрационните номера на колите, чиято цена е над 5000 и регистрационният им номер 
// завършва на четна цифра
string find_special_numbers(const vector<Car>& stock)
{
	cout << "Cars with --PRICE > 5000-- and --even registration digit--:\n";
	for (const auto& car : stock)
	{
		string reg = car.get_registration_number();
		double current_price = car.get_price();
		if (current_price > 5000.0 && reg.length() > 0)
		{
			char digit_char = reg[5];
			int digit = digit_char - '0';
			if (digit % 2 == 0)
			{
				cout << "Match found: " << reg << " | Price: " << current_price << endl;
			}
		}
	}
}

int main()
{
	vector <Car> stock;
	int choice;

	do 
	{
		cout << "\nMENU\n";
		cout << "1. Add car\n";
		cout << "2. Show cars by brand\n";
		cout << "3. Average price of cars from any year\n";
		cout << "4. Registration numbers ending in even digit\n";
		cout << "5. Exit\n";
		if (!(cin >> choice))
		{
			cout << "Invalid input! Use the shown menu numbers only.\n";
			break;
		}

		if (choice == 1)
		{
			Car automobile;
			automobile.get_data();
			stock.push_back(automobile);
		}
		else if (choice == 2)
		{
			string brand;
			cout << "Write a brand to search: "; cin >> brand;
			show_cars_by_brand(stock, brand);
		}
		else if (choice == 3)
		{
			double average = average_price_after_an_year(stock, 2014);
			cout << "Average price (after 2014): " << average << endl;
		}
		else if (choice == 4)
		{
			find_special_numbers(stock);
		}

	} while (choice != 5);
	return 0;
}
