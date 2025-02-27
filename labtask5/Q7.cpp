#include <iostream>
using namespace std;

class Student {
    private:
        const int rollNo;
    public:
        Student(int roll) : rollNo(roll) {}
        void Display() const {
            cout << "Student Roll Number: " << rollNo << endl;
        }
};

void StudentTest() {
    int roll;
    cout << "Enter Student Roll Number: ";
    cin >> roll;
    Student s(roll);
    s.Display();
}

int main() {
    StudentTest();
    return 0;
}
