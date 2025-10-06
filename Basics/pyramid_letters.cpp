# include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a value for n: ";
    cin >> n;

    char symbol = 'A';
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << symbol ;
        }
        cout << endl;
        symbol += 1;
    }
}
