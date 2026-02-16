#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string owner;
    double balance;

public:
    BankAccount(string o, double b) {
        owner = o;
        balance = b;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount acc("Maria", 1000);

    acc.deposit(500);
    acc.withdraw(300);
    acc.withdraw(1500); 

    cout << "Current balance: " << acc.getBalance() << endl;

    return 0;
}
