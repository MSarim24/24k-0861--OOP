#include <iostream>
using namespace std;

class Shape {
public:
    virtual double getArea() const = 0;
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override { return width * height; }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double getArea() const override { return 0.5 * base * height; }
};

int main() {
    Rectangle r(10, 5);
    Triangle t(8, 6);

    cout << "Area of Rectangle: " << r.getArea() << endl;
    cout << "Area of Triangle: " << t.getArea() << endl;

    return 0;
}
