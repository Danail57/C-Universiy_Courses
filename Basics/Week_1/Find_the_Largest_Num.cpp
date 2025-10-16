# include <iostream>
using namespace std;

int find_the_biggest_number();

int main() {
    int first_number = 0, second_number = 0, third_number = 0;
    int largest_number = 0;
    cout << "Enter first number: ";
    cin >> first_number;

    cout << "Enter second number: ";
    cin >> second_number;

    cout << "Enter the third number:";
    cin >> third_number;
    largest_number = max(first_number, second_number);
    largest_number = max(largest_number, third_number);
    cout << "The largest number is: " << largest_number << endl;
    return 0;
}
