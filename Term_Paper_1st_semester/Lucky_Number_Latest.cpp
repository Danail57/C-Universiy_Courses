#include <iostream>
#include <set>
using namespace std;

int main() {
    int N;

    // Въвеждане с пълна проверка
    while (true) {
        cout << "Enter a number between 1 and 999: ";

        cin >> N;

        // Проверка дали входът е валиден
        if (cin.fail()) {
            cin.clear();              // нулираме флага за грешка
            cin.ignore(10000, '\n');  // изчистваме грешния вход от буфера
            cout << "Invalid input! Please enter a valid number." << endl;
            continue;
        }

        // Проверка дали числото е в диапазона
        if (N < 1 || N > 999) {
            cout << "Number out of range! Try again." << endl;
            continue;
        }

        break; // ако всичко е наред – излизаме от цикъла
    }

    set<int> seenNumbers;
    cout << N;

    while (true) {
        if (seenNumbers.count(N)) {
            cout << endl << "First repeated number: " << N << endl;
            break;
        }

        seenNumbers.insert(N);

        int sum = 0, temp = N;
        while (temp > 0) {
            int digit = temp % 10;
            sum += digit * digit;
            temp /= 10;
        }

        N = sum;
        cout << " -> " << N;
    }

    return 0;
}
