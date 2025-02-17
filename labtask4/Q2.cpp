#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Account {
private:
    double balance;

public:
    Account() : balance(20000) {}

    void credit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount added successfully!" << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void debit(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds! Withdrawing available balance." << endl;
            balance = 0;
        } else if (amount > 0) {
            balance -= amount;
            cout << "Amount withdrawn successfully!" << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    Account account1;
    double amount;
    char choice;

    do {
        cout << "Enter 'D' to deposit or 'W' to withdraw (or 'E' to exit): ";
        cin >> choice;
        choice = toupper(choice);

        if (choice == 'D') {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            account1.credit(amount);
        } else if (choice == 'W') {
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            account1.debit(amount);
        } else if (choice != 'E') {
            cout << "Invalid choice! Try again." << endl;
        }

        cout << "Current Balance: " << account1.getBalance() << endl;
    } while (choice != 'E');

    cout << "Final Balance: " << account1.getBalance() << endl;
    return 0;
}
