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


// Чете число n.

// За всеки ред i от 1 до n отпечатва i пъти символа symbol.

// След всеки ред увеличава symbol с 1 (от 'A' до 'B' и т.н.)

// Така получаваш пирамида с букви.
