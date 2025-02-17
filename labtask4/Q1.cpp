#include <iostream>
#include <cmath>

using namespace std;

class Circle {
private:
    double r;

public:
    Circle(double radius) : r(radius) {}

    double getArea() const {
        return M_PI * r * r;
    }

    double getPerimeter() const {
        return 2 * M_PI * r;
    }
};

int main() {
    Circle circle1(20.5);
    
    cout << "Area: " << circle1.getArea() << endl;
    cout << "Perimeter: " << circle1.getPerimeter() << endl;

    return 0;
}
