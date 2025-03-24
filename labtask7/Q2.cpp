#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string color;
    double positionX, positionY;
public:
    Shape(string c, double x, double y) : color(c), positionX(x), positionY(y) {}
    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(string c, double x, double y, double r) : Shape(c, x, y), radius(r) {}
    void draw() override {
        cout << "Drawing Circle at (" << positionX << ", " << positionY << ") with radius " << radius << " and color " << color << endl;
    }
    double calculateArea() override {
        return M_PI * radius * radius;
    }
    double calculatePerimeter() override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(string c, double x, double y, double w, double h) : Shape(c, x, y), width(w), height(h) {}
    void draw() override {
        cout << "Drawing Rectangle at (" << positionX << ", " << positionY << ") with width " << width << " and height " << height << " and color " << color << endl;
    }
    double calculateArea() override {
        return width * height;
    }
    double calculatePerimeter() override {
        return 2 * (width + height);
    }
};

int main() {
    Circle circle("Red", 5.0, 5.0, 10.0);
    Rectangle rectangle("Blue", 0.0, 0.0, 8.0, 6.0);
    
    circle.draw();
    cout << "Circle Area: " << circle.calculateArea() << endl;
    cout << "Circle Perimeter: " << circle.calculatePerimeter() << endl;
    
    rectangle.draw();
    cout << "Rectangle Area: " << rectangle.calculateArea() << endl;
    cout << "Rectangle Perimeter: " << rectangle.calculatePerimeter() << endl;
    
    return 0;
}
