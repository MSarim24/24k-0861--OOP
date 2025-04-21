#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
public:
    virtual void getData() = 0;
    virtual void displayData() const = 0;
    virtual double bonus() const = 0;
    virtual ~Person() {}
};

class Admin : virtual public Person {
protected:
    double adminSalary;
public:
    void getData() override {
        cout << "Enter Admin Name and ID: ";
        cin >> name >> id;
        cout << "Enter Admin Salary: ";
        cin >> adminSalary;
    }
    void displayData() const override {
        cout << "Admin: " << name << ", ID: " << id << ", Salary: " << adminSalary << endl;
    }
    double bonus() const override { return adminSalary * 0.1; }
};

class Account : virtual public Person {
protected:
    double accountSalary;
public:
    void getData() override {
        cout << "Enter Account Name and ID: ";
        cin >> name >> id;
        cout << "Enter Account Salary: ";
        cin >> accountSalary;
    }
    void displayData() const override {
        cout << "Account: " << name << ", ID: " << id << ", Salary: " << accountSalary << endl;
    }
    double bonus() const override { return accountSalary * 0.15; }
};

class Master : public Admin, public Account {
public:
    void getData() override {
        Admin::getData();
        Account::getData();
    }
    void displayData() const override {
        Admin::displayData();
        Account::displayData();
    }
    double bonus() const override {
        return Admin::bonus() + Account::bonus();
    }
};

int main() {
    Person* emp;
    Master m;
    emp = &m;
    emp->getData();
    emp->displayData();
    cout << "Total Bonus: $" << emp->bonus() << endl;
    return 0;
}
