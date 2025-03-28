#include <iostream>
using namespace std;

struct Employee {
    int employee_id;
    string name;
    float salary;
};

struct Organisation {
    string organisation_name;
    string organisation_number;
    Employee emp;
};

int main() {
    Organisation org;

    cout << "Enter Organisation Name: ";
    getline(cin, org.organisation_name);
    cout << "Enter Organisation Number: ";
    getline(cin, org.organisation_number);
    
    cout << "Enter Employee ID: ";
    cin >> org.emp.employee_id;
    cin.ignore(); 
    cout << "Enter Employee Name: ";
    getline(cin, org.emp.name);
    cout << "Enter Employee Salary: ";
    cin >> org.emp.salary;

    cout << "The size of structure organisation: " << sizeof(org) << endl;
    cout << "Organisation Name: " << org.organisation_name << endl;
    cout << "Organisation Number: " << org.organisation_number << endl;
    cout << "Employee ID: " << org.emp.employee_id << endl;
    cout << "Employee Name: " << org.emp.name << endl;
    cout << "Employee Salary: " << org.emp.salary << endl;

    return 0;
}
