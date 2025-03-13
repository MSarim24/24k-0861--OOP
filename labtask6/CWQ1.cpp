#include <iostream>
#include <vector>
using namespace std;

class BankAccount{
    protected:
        string accno;
        double balance;
    public:
        BankAccount(string a, double b) : accno(a),balance(b){}

        virtual void deposit(double da){
            balance += da;
            cout << "Deposited " << da << " in " << accno << " | New Balance: " << balance << endl;
        }

        virtual void withdraw(double wa){
            if(wa <= balance){
                balance -= wa;
                cout << "Withdrawn " << wa << " from " << accno << " | New Balance: " << balance << endl;
            }
            else{
                cout << "Insufficient funds!" << endl;
            }
        }
        virtual void applyMonthlyUpdate() = 0;
};

class SavingsAccount : public BankAccount{
    private:
        double interest;
    public:
        SavingsAccount(double i, string a, double b) : BankAccount(a, b), interest(i) {}

        void applyMonthlyUpdate() override {
            balance += balance * (interest / 100); 
            cout << "Interest applied to " << accno << " | New Balance: " << balance << endl;
        }
};

class CheckingAccount : public BankAccount{
    private:
        double overdraftLimit;
    public:
        CheckingAccount(string a, double b, double limit) : BankAccount(a, b), overdraftLimit(limit) {}
        void withdraw(double amount) override {
            if (amount > balance + overdraftLimit) {
                cout << "Overdraft limit exceeded!" << endl;
                return;
            }
            balance -= amount;
            cout << "Withdrawn " << amount << " from " << accno << " | New Balance: " << balance << endl;
        }
        void applyMonthlyUpdate() override{}
};

class BusinessAccount : public BankAccount{
    private:
        double tax;
    public:
        BusinessAccount(string a, double b, double t) : BankAccount(a, b), tax(t) {}

        void deposit(double a) override {
            balance += a - (a * tax);
            cout << "Deposited " << a << " in " << accno << " after tax | New Balance: " << balance << endl;
        }
        void applyMonthlyUpdate() override{}
};

class Customer {
    private:
        string name;
    public:
        Customer(string n) : name(n) {}
        void deposit(BankAccount* acc, double amount) { acc->deposit(amount); }
        void withdraw(BankAccount* acc, double amount) { acc->withdraw(amount); }
        string getname(){
            return name;
        }
};

class Employee {
    protected:
        string name;
    public:
        Employee(string n) : name(n) {}
        virtual void performOperation(BankAccount *acc) = 0;
        string getname(){
            return name;
        }
};

class Teller : public Employee {
    private:
        bool freeze;
    public:
        Teller(string n, bool f) : Employee(n), freeze(f) {}
        void performOperation(BankAccount *acc) override {
            if (freeze) {
                cout << "Your account is frozen.." << endl;
                return;
            }
            double a;
            cout << "Enter the Amount: ";
            cin >> a;
            int choice = 0;
            cout << "1----Withdraw\n2----Deposit";
            cin >> choice;
            switch (choice) {
                case 1:
                    acc->withdraw(a);
                    break;
                case 2:
                    acc->deposit(a);
                    break;
                default:
                    break;
            }
        }
};

class Manager : public Employee {
    private:
        bool freeze;
    public:
        Manager(string n, bool f) : Employee(n), freeze(f) {}
        void performOperation(BankAccount* acc) override {
            if (freeze) {
                cout << "Your account is frozen.." << endl;
                return;
            }
            double a;
            cout << "Enter the Amount: ";
            cin >> a;
            int choice = 0;
            cout << "1----Withdraw\n2----Deposit";
            cin >> choice;
            switch (choice) {
                case 1:
                    acc->withdraw(a);
                    break;
                case 2:
                    acc->deposit(a);
                    break;
                default:
                    break;
            }
            acc->applyMonthlyUpdate();
        }
};

int main() {
    SavingsAccount savingsAcc(5.0, "SA001", 1000.0);
    CheckingAccount checkingAcc("CA001", 500.0, 200.0);
    BusinessAccount businessAcc("BA001", 5000.0, 0.05);

    Teller teller("Alice", false);
    Manager manager("Bob", false);

    vector<BankAccount*> accounts;
    accounts.push_back(&savingsAcc);
    accounts.push_back(&checkingAcc);
    accounts.push_back(&businessAcc);

    vector<Employee*> employees;
    employees.push_back(&teller);
    employees.push_back(&manager);

    for (Employee* emp : employees) {
        cout << "\n--- Operation by " << emp->getname() << " ---\n";
        for (BankAccount* acc : accounts) {
            emp->performOperation(acc);
        }
    }

    Customer customer("Charlie");
    cout << "\n--- Operation by Customer " << customer.getname() << " ---\n";
    customer.deposit(&savingsAcc, 500.0);
    customer.withdraw(&checkingAcc, 100.0);

    return 0;
}
