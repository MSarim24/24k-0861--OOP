#include <iostream>
#include <iomanip>
using namespace std;
class Employee{
    private:
        string firstname;
        string lastname;
        double monsalary;
    public:
        Employee(string f,string l,double s){
            firstname = f;
            lastname = l;
            setmonsalary(s);
        }
        void setmonsalary(double salary) {
            monsalary = (salary > 0) ? salary : 0.0;
        }
        void raise(double p){
            monsalary +=  monsalary*(p/100);
        }
        string getfirstname(){
            return firstname;
        }
        string getlastname(){
            return lastname;
        }
        double getmonsalary(){
            return monsalary;
        }
        void displayyearlysalary(){
            cout << fixed<<setprecision(2);
            cout << "Employee: " << firstname << " " << lastname << endl;
            cout << "Monthly Salary: $" << monsalary <<endl;
            cout << "Yearly Salary: $" << monsalary*12 <<endl;
        }
};
void EmployeeTest(){
    string fName, lName;
    double salary;

    cout << "Enter first employee's first name: ";
    cin >> fName;
    cout << "Enter first employee's last name: ";
    cin >> lName;
    cout << "Enter first employee's monthly salary: ";
    cin >> salary;
    Employee emp1(fName, lName, salary);
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "Enter second employee's first name: ";
    cin >> fName;
    cout << "Enter second employee's last name: ";
    cin >> lName;
    cout << "Enter second employee's monthly salary: ";
    cin >> salary;
    Employee emp2(fName, lName, salary);
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "Initial Salaries:\n"<<"Employee1: "<<endl;
    emp1.displayyearlysalary();
    cout <<"\nEmployee2: "<< endl;
    emp2.displayyearlysalary();
    cout << endl;
    cout << endl;
    cout << endl;
    

    emp1.raise(10);
    emp2.raise(10);

    cout << "After 10% Raise:\n"<<"Employee1: "<<endl;
    emp1.displayyearlysalary();
    cout <<"\nEmployee2: "<< endl;
    emp2.displayyearlysalary();
}
int main()
{
    EmployeeTest();
    return 0;
}