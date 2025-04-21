#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int id;
public:
    Student(string n, int i) : name(n), id(i) {}
    virtual double getTuition(const string& status, int creditHours) const = 0;
    virtual ~Student() {}
};

class GraduateStudent : public Student {
private:
    string researchTopic;
public:
    GraduateStudent(string n, int i, string topic) : Student(n, i), researchTopic(topic) {}

    void setResearchTopic(const string& topic) { researchTopic = topic; }
    string getResearchTopic() const { return researchTopic; }

    double getTuition(const string& status, int creditHours) const override {
        if (status == "undergraduate") return creditHours * 200;
        else if (status == "graduate") return creditHours * 300;
        else if (status == "doctoral") return creditHours * 400;
        else return 0.0;
    }
};

int main() {
    GraduateStudent gs("Ahmed", 123, "AI Research");
    cout << "Student: " << gs.getResearchTopic() << endl;
    cout << "Tuition (Graduate, 9 credits): $" << gs.getTuition("graduate", 9) << endl;
    return 0;
}
