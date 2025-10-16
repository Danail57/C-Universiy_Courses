# include <iostream>
using namespace std;

int find_the_smallest_number(int first, int second, int third);
int main() {

    int first_number = 0, second_number = 0, third_number = 0;
    int smallest_number = 0;

    cout << "Enter the first number: ";
    cin >> first_number;

    cout << "Enter the second number: ";
    cin >> second_number;

    cout << "Enter the third number: ";
    cin >> third_number;

    smallest_number = find_the_smallest_number(first_number, second_number, third_number);
    cout << "The smallest number is: " << smallest_number << endl;
    return 0;
}


int find_the_smallest_number(int first, int second, int third) {
    int smallest_number = first;

    if (second < first) {smallest_number = second;}
    if (third < smallest_number) {smallest_number = third;}

    return smallest_number;
}# include <iostream>
using namespace std;

int find_the_smallest_number(int first, int second, int third);
int main() {

    int first_number = 0, second_number = 0, third_number = 0;
    int smallest_number = 0;

    cout << "Enter the first number: ";
    cin >> first_number;

    cout << "Enter the second number: ";
    cin >> second_number;

    cout << "Enter the third number: ";
    cin >> third_number;

    smallest_number = find_the_smallest_number(first_number, second_number, third_number);
    cout << "The smallest number is: " << smallest_number << endl;
    return 0;
}


int find_the_smallest_number(int first, int second, int third) {
    int smallest_number = first;

    if (second < first) {smallest_number = second;}
    if (third < smallest_number) {smallest_number = third;}

    return smallest_number;
}
