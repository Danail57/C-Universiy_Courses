#include <iostream>
using namespace std;

int main()
{
    int m;
    cout << "Enter how many numbers you want to type: ";
    cin >> m;
    
    int numbers[m];

    for (int i = 0; i < m; i++) {
        cout << "Number " << i + 1 << ": ";
        cin >> numbers[i];
    }
    
    int max_number = numbers[0];
    
    for (int i = 1; i < m; i++) {
        if (numbers[i] > max_number) {
            max_number = numbers[i];
        }
    }

    cout << "The biggest number is: " << max_number << endl;
    return 0;
}
