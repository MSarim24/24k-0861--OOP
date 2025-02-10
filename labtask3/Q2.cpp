#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

public:
    Date(int d, int m, int y) {
        month = m;
        day = d;
        year = y;
    }

    string displayDate() {
        return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    }
};
void DateTest() {
    Date date1(12, 25, 2023);
    Date date2(1, 1, 2024);

    cout << "Demonstrating Date class capabilities:" << endl;
    cout<<date1.displayDate()<<endl;
    cout<<date2.displayDate()<<endl;
}
int main() {
    DateTest();
    return 0;
}
