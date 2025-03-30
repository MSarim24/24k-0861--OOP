#include <iostream>
#include <string>
using namespace std;

class Person {
    protected:
        int employeeID;
    public:
        void getData(int id) {
            employeeID = id;
        }

        void displayData() {
            cout << "Employee ID: " << employeeID << endl;
        }
};

class Admin : public Person {
    private:
        string name;
        double monthlyIncome;
    public:
        void getData(int id, string n, double income) {
            Person::getData(id);
            name = n;
            monthlyIncome = income;
        }

        void displayData() {
            Person::displayData();
            cout << "Name: " << name << endl;
            cout << "Monthly Income: " << monthlyIncome << endl;
        }

        void bonus() {
            double bonus = monthlyIncome * 0.05;
            cout << "Annual Bonus: " << bonus << endl;
        }
};

class Accounts : public Person {
    private:
        string name;
        double monthlyIncome;
    public:
        void getData(int id, string n, double income) {
            Person::getData(id);
            name = n;
            monthlyIncome = income;
        }

        void displayData() {
            Person::displayData();
            cout << "Name: " << name << endl;
            cout << "Monthly Income: " << monthlyIncome << endl;
        }

        void bonus() {
            double bonus = monthlyIncome * 0.05;
            cout << "Annual Bonus: " << bonus << endl;
        }
};

int main() {
    Admin admin1;
    admin1.getData(101, "Alice", 3000);
    admin1.displayData();
    admin1.bonus();

    Accounts accounts1;
    accounts1.getData(102, "Bob", 2500);
    accounts1.displayData();
    accounts1.bonus();

    return 0;
}
