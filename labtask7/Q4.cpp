#include <iostream>
#include <vector>
using namespace std;

class Person {
protected:
    string name, id, address, phoneNumber, email;
public:
    Person(string n, string i, string a, string p, string e) : name(n), id(i), address(a), phoneNumber(p), email(e) {}
    virtual void displayInfo() {
        cout << "Name: " << name << " | ID: " << id << " | Address: " << address << " | Phone: " << phoneNumber << " | Email: " << email << endl;
    }
};

class Student : public Person {
private:
    vector<string> coursesEnrolled;
    double GPA;
    int enrollmentYear;
public:
    Student(string n, string i, string a, string p, string e, double g, int year) : Person(n, i, a, p, e), GPA(g), enrollmentYear(year) {}
    void enrollCourse(string course) { coursesEnrolled.push_back(course); }
    void displayInfo() override {
        Person::displayInfo();
        cout << "GPA: " << GPA << " | Enrollment Year: " << enrollmentYear << " | Courses: ";
        for (const auto &course : coursesEnrolled) cout << course << " ";
        cout << endl;
    }
};

class Professor : public Person {
private:
    string department;
    vector<string> coursesTaught;
    double salary;
public:
    Professor(string n, string i, string a, string p, string e, string dept, double sal) : Person(n, i, a, p, e), department(dept), salary(sal) {}
    void addCourse(string course) { coursesTaught.push_back(course); }
    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << " | Salary: " << salary << " | Courses Taught: ";
        for (const auto &course : coursesTaught) cout << course << " ";
        cout << endl;
    }
};

class Staff : public Person {
private:
    string department, position;
    double salary;
public:
    Staff(string n, string i, string a, string p, string e, string dept, string pos, double sal) : Person(n, i, a, p, e), department(dept), position(pos), salary(sal) {}
    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << " | Position: " << position << " | Salary: " << salary << endl;
    }
};

int main() {
    Student s1("Alice", "S001", "123 St", "555-1234", "alice@email.com", 3.8, 2022);
    s1.enrollCourse("Math");
    s1.enrollCourse("Physics");
    
    Professor p1("Dr. Smith", "P100", "456 Ave", "555-5678", "smith@email.com", "Computer Science", 90000);
    p1.addCourse("Programming");
    
    Staff st1("John", "ST200", "789 Blvd", "555-9999", "john@email.com", "Administration", "Manager", 60000);
    
    cout << "--- University Information ---" << endl;
    s1.displayInfo();
    p1.displayInfo();
    st1.displayInfo();
    
    return 0;
}
