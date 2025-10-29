#include <iostream>
#include <set>
using namespace std;

int main() {
    int N;
    cout << "Enter a number between 1 and 999: ";
    cin >> N;

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
