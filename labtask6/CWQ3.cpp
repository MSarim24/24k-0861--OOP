#include <iostream>
#include <vector>
using namespace std;

class Employee {
protected:
    int id;
    string name;
public:
    Employee(int i, string n) : id(i), name(n) {}
    virtual void showRole() = 0;
    virtual ~Employee() {}
};

class IOrderTaker {
public:
    virtual void takeOrder() = 0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer {
public:
    virtual void prepareOrder() = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller {
public:
    virtual void generateBill() = 0;
    virtual ~IBiller() {}
};

class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int i, string n) : Employee(i, n) {}
    void takeOrder() override {
        cout << name << " is taking an order." << endl;
    }
    void showRole() override {
        cout << name << " is a Waiter." << endl;
    }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int i, string n) : Employee(i, n) {}
    void prepareOrder() override {
        cout << name << " is preparing an order." << endl;
    }
    void showRole() override {
        cout << name << " is a Chef." << endl;
    }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(int i, string n) : Employee(i, n) {}
    void generateBill() override {
        cout << name << " is generating a bill." << endl;
    }
    void showRole() override {
        cout << name << " is a Cashier." << endl;
    }
};

class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int i, string n) : Employee(i, n) {}
    void takeOrder() override {
        cout << name << " is taking an order as Manager." << endl;
    }
    void generateBill() override {
        cout << name << " is generating a bill as Manager." << endl;
    }
    void showRole() override {
        cout << name << " is a Manager." << endl;
    }
};

int main() {
    vector<Employee*> staff;
    Waiter waiter(1, "Alice");
    Chef chef(2, "Bob");
    Cashier cashier(3, "Charlie");
    Manager manager(4, "Dave");
    
    staff.push_back(&waiter);
    staff.push_back(&chef);
    staff.push_back(&cashier);
    staff.push_back(&manager);
    
    for (Employee* e : staff) {
        e->showRole();
    }
    
    waiter.takeOrder();
    chef.prepareOrder();
    cashier.generateBill();
    manager.takeOrder();
    manager.generateBill();
    
    return 0;
}
