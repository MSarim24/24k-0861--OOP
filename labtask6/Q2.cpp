#include <iostream>
using namespace std;

class Vehicle {
protected:
    double price;
public:
    Vehicle(double p) : price(p) {}
    virtual void display() = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
protected:
    int seatingCapacity, numDoors;
    string fuelType;
public:
    Car(double p, int seats, int doors, string fuel) : Vehicle(p), seatingCapacity(seats), numDoors(doors), fuelType(fuel) {}
};

class Motorcycle : public Vehicle {
protected:
    int cylinders, gears, wheels;
public:
    Motorcycle(double p, int cyl, int g, int w) : Vehicle(p), cylinders(cyl), gears(g), wheels(w) {}
};

class Audi : public Car {
private:
    string modelType;
public:
    Audi(double p, int seats, int doors, string fuel, string model) : Car(p, seats, doors, fuel), modelType(model) {}
    void display() override {
        cout << "Audi Details:\nPrice: " << price << "\nSeating: " << seatingCapacity << "\nDoors: " << numDoors << "\nFuel: " << fuelType << "\nModel: " << modelType << endl;
    }
};

class Yamaha : public Motorcycle {
private:
    string makeType;
public:
    Yamaha(double p, int cyl, int g, int w, string make) : Motorcycle(p, cyl, g, w), makeType(make) {}
    void display() override {
        cout << "Yamaha Details:\nPrice: " << price << "\nCylinders: " << cylinders << "\nGears: " << gears << "\nWheels: " << wheels << "\nMake: " << makeType << endl;
    }
};

int main() {
    Audi audi(50000, 5, 4, "Petrol", "A6");
    Yamaha yamaha(15000, 2, 6, 2, "R1");
    
    audi.display();
    cout << "\n";
    yamaha.display();
    
    return 0;
}
