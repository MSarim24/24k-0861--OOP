#include <iostream>
#include <string>
using namespace std;

class Wallet {
private:
    double balance;
    double dailyDepositLimit;
    double dailyWithdrawalLimit;
    double depositedToday;
    double withdrawnToday;

public:
    Wallet(double depositLimit = 5000, double withdrawLimit = 3000)
        : balance(0), dailyDepositLimit(depositLimit), dailyWithdrawalLimit(withdrawLimit),
          depositedToday(0), withdrawnToday(0) {}

    bool deposit(double amount) {
        if (amount <= 0 || depositedToday + amount > dailyDepositLimit) return false;
        balance += amount;
        depositedToday += amount;
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance || withdrawnToday + amount > dailyWithdrawalLimit)
            return false;
        balance -= amount;
        withdrawnToday += amount;
        return true;
    }

    double getBalance() const { return balance; }
};

class User {
private:
    string userID;
    string name;
    Wallet wallet;

public:
    User(string id, string n) : userID(id), name(n) {}

    bool deposit(double amount) {
        return wallet.deposit(amount);
    }

    bool withdraw(double amount) {
        return wallet.withdraw(amount);
    }

    void showBalance() const {
        cout << name << "'s Balance: $" << wallet.getBalance() << endl;
    }
};

int main() {
    User u1("U001", "Alice");
    User u2("U002", "Bob");

    u1.deposit(2000);
    u1.withdraw(500);
    u1.showBalance();

    u2.deposit(6000); // exceeds limit
    u2.deposit(3000);
    u2.withdraw(3500); // exceeds withdraw limit
    u2.withdraw(2000);
    u2.showBalance();

    return 0;
}
