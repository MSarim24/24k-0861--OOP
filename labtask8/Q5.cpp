#include <iostream>
using namespace std;

class Shape {
    private:
        double area;
    public:
        Shape(double a) : area(a) {}

        double operator+(const Shape& s) {
            return this->area + s.area;
        }

        double Area() {
            return area;
        }
};

int main() {
    Shape shape1(10.0);
    Shape shape2(20.0);

    double totalArea = shape1 + shape2;
    cout << "Total Area: " << totalArea << " square units" << endl;

    return 0;
}
