// Да се напише програма, която въвежда ЕГН-та
// на група лица и извежда ЕГН-та само
// на родените през зимните месеци: 12, 1, 2.

#include <iostream>
using namespace std;

int main() {
    int count_ID;
    cout << "Enter how many IDs you want to write: ";
    cin >> count_ID;
    cin.ignore(); 

    string IDs[100];
    for (int i = 0; i < count_ID; i++) {
        cout << "Enter ID #" << i + 1 << ": ";
        getline(cin, IDs[i]);
    }

    bool found = false; 
    cout << "\nWinter birth IDs:\n";
    for (int i = 0; i < count_ID; i++) {
        if ((IDs[i][2] == '1' && IDs[i][3] == '2') || // December
            (IDs[i][2] == '0' && IDs[i][3] == '1') || // January
            (IDs[i][2] == '0' && IDs[i][3] == '2'))   // February
        {
            cout << IDs[i] << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "There are no IDs for people born in winter months." << endl;
    }

    return 0;
}
