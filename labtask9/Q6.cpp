#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    float price;
public:
    Car(string m) : model(m), price(0.0f) {}
    string getModel() const { return model; }
    float getPrice() const { return price; }
    virtual void setPrice(float p) = 0;
    virtual void display() const = 0;
};

class Color : public Car {
private:
    string colorName;
public:
    Color(string m, string color) : Car(m), colorName(color) {}
    void setPrice(float p) override { price = p; }
    void display() const override {
        cout << "Model: " << model << ", Color: " << colorName << ", Price: $" << price << endl;
    }
};

class Company : public Car {
private:
    string companyName;
public:
    Company(string m, string comp) : Car(m), companyName(comp) {}
    void setPrice(float p) override { price = p; }
    void display() const override {
        cout << "Model: " << model << ", Company: " << companyName << ", Price: $" << price << endl;
    }
};

int main() {
    Color c("Corolla", "Red");
    Company cm("Civic", "Honda");

    c.setPrice(22000);
    cm.setPrice(25000);

    c.display();
    cm.display();

    return 0;
}
