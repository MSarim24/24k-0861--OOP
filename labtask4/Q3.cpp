#include <iostream>
#include <string>
#include <cctype> // For toupper()

using namespace std;

class Account {
private:
    double accountBalance;

public:
    Account() : accountBalance(20000) {}

    void credit(double transactionAmount) {
        if (transactionAmount > 0) {
            accountBalance += transactionAmount;
            cout << "Amount added successfully!" << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void debit(double transactionAmount) {
        if (transactionAmount > accountBalance) {
            cout << "Insufficient funds! You only have $" << accountBalance << " available." << endl;
        } else if (transactionAmount > 0) {
            accountBalance -= transactionAmount;
            cout << "Amount withdrawn successfully!" << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    double getBalance() const {
        return accountBalance;
    }

    void displayBalance() const {
        cout << "Current Balance: $" << accountBalance << endl;
    }
};

int main() {
    Account userAccount;
    double transactionAmount;
    char userChoice;

    do {
        cout << "\nEnter 'D' to Deposit, 'W' to Withdraw, or 'E' to Exit: ";
        cin >> userChoice;
        userChoice = toupper(userChoice);

        switch (userChoice) {
            case 'D':
                cout << "Enter amount to deposit: ";
                cin >> transactionAmount;
                userAccount.credit(transactionAmount);
                break;
            case 'W':
                cout << "Enter amount to withdraw: ";
                cin >> transactionAmount;
                userAccount.debit(transactionAmount);
                break;
            case 'E':
                cout << "Exiting... Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

        userAccount.displayBalance();

    } while (userChoice != 'E');

    return 0;
}
