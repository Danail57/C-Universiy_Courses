# Напишете програма на C++, която:
# Изисква от потребителя да въведе колко числа ще въвежда (положително цяло число).
# Валидира въведения брой – ако потребителят въведе невалидна стойност (напр. букви, отрицателно число или 0), го кара да въведе отново.
# Въвежда числата едно по едно, като за всяко се прави проверка дали е цяло число.
# Ако някое въведено число е невалидно (не е цяло число), програмата показва съобщение и иска въвеждането му отново.
# След успешно въвеждане на всички числа, извежда:
#  Числата във възходящ ред.
# Числата в низходящ ред.
# Минималното и максималното число.
#  Сумата и средното аритметично на числата.
#  Броя на четните и нечетните числа.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int count;
    cout << "How many numbers will you enter? ";

    while (!(cin >> count) || count <= 0) {
        cout << "Please enter a positive integer for the count: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    vector<int> numbers;
    int num;

    cout << "Enter " << count << " numbers:\n";

    for (int i = 0; i < count; ) {
        cout << "Number " << i + 1 << ": ";
        if (cin >> num) {
            numbers.push_back(num);
            i++;
        } else {
            cout << "Invalid input. Please enter a valid integer.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    sort(numbers.begin(), numbers.end());
    cout << "Numbers in ascending order: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    sort(numbers.begin(), numbers.end(), greater<int>());
    cout << "Numbers in descending order: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    int min_num = *min_element(numbers.begin(), numbers.end());
    int max_num = *max_element(numbers.begin(), numbers.end());

    cout << "Minimum number: " << min_num << endl;
    cout << "Maximum number: " << max_num << endl;

    int sum = 0;
    for (int n : numbers) {
        sum += n;
    }
    double average = static_cast<double>(sum) / count;

    cout << "Sum of numbers: " << sum << endl;
    cout << "Average of numbers: " << average << endl;

    int even_count = 0, odd_count = 0;
    for (int n : numbers) {
        if (n % 2 == 0)
            even_count++;
        else
            odd_count++;
    }

    cout << "Even numbers count: " << even_count << endl;
    cout << "Odd numbers count: " << odd_count << endl;

    return 0;
}
