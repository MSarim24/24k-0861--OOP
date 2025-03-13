#include <iostream>
using namespace std;

class Student {
protected:
    string name;
    int rollNumber;
public:
    Student(string n, int roll) : name(n), rollNumber(roll) {}
    void displayStudent() {
        cout << "Student Name: " << name << "\nRoll Number: " << rollNumber << endl;
    }
};

class Marks : public Student {
protected:
    int subject1, subject2, subject3;
public:
    Marks(string n, int roll, int s1, int s2, int s3) : Student(n, roll), subject1(s1), subject2(s2), subject3(s3) {}
    void displayMarks() {
        cout << "Marks: " << subject1 << ", " << subject2 << ", " << subject3 << endl;
    }
};

class Result : public Marks {
public:
    Result(string n, int roll, int s1, int s2, int s3) : Marks(n, roll, s1, s2, s3) {}
    void displayResult() {
        int total = subject1 + subject2 + subject3;
        float average = total / 3.0;
        cout << "Total Marks: " << total << "\nAverage Marks: " << average << endl;
    }
};

int main() {
    Result student("John Doe", 101, 85, 90, 78);
    student.displayStudent();
    student.displayMarks();
    student.displayResult();
    return 0;
}
