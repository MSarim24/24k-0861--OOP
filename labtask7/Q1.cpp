#include <iostream>
#include <vector>
using namespace std;

class Account {
protected:
    string accountNumber, accountHolderName;
    double balance;
public:
    Account(string accNo, string holder, double bal) : accountNumber(accNo), accountHolderName(holder), balance(bal) {}
    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << " | New Balance: " << balance << endl;
    }
    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
            return;
        }
        balance -= amount;
        cout << "Withdrawn " << amount << " | New Balance: " << balance << endl;
    }
    virtual void calculateInterest() = 0;
    virtual void printStatement() = 0;
    virtual void getAccountInfo() {
        cout << "Account: " << accountNumber << " | Holder: " << accountHolderName << " | Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate, minimumBalance;
public:
    SavingsAccount(string accNo, string holder, double bal, double rate, double minBal)
        : Account(accNo, holder, bal), interestRate(rate), minimumBalance(minBal) {}
    void calculateInterest() override {
        balance += balance * (interestRate / 100);
        cout << "Interest Applied | New Balance: " << balance << endl;
    }
    void printStatement() override {
        cout << "Statement for Savings Account: " << accountNumber << endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(string accNo, string holder, double bal) : Account(accNo, holder, bal) {}
    void calculateInterest() override {}
    void printStatement() override {
        cout << "Statement for Checking Account: " << accountNumber << endl;
    }
};

class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    string maturityDate;
public:
    FixedDepositAccount(string accNo, string holder, double bal, double rate, string date)
        : Account(accNo, holder, bal), fixedInterestRate(rate), maturityDate(date) {}
    void calculateInterest() override {
        balance += balance * (fixedInterestRate / 100);
        cout << "Fixed Deposit Interest Applied | New Balance: " << balance << endl;
    }
    void printStatement() override {
        cout << "Statement for Fixed Deposit Account: " << accountNumber << endl;
    }
};

int main() {
    SavingsAccount sa("SA001", "John Doe", 5000, 3.5, 1000);
    CheckingAccount ca("CA001", "Jane Doe", 3000);
    FixedDepositAccount fda("FDA001", "Alice", 10000, 5.0, "2025-12-31");
    
    vector<Account*> accounts = {&sa, &ca, &fda};
    
    for (Account* acc : accounts) {
        acc->getAccountInfo();
        acc->calculateInterest();
        acc->printStatement();
        cout << "--------------------------" << endl;
    }
    
    return 0;
}
