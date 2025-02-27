#include <iostream>
#include <vector>
using namespace std;

class Car {
    private:
        string name;
        int id;
    public:
        Car(string carName, int carId) : name(carName), id(carId) {}
        string getName() { return name; }
        int getId() { return id; }
};

class Garage {
    private:
        vector<Car*> cars;
    public:
        void parkCar(Car* car) {
            cars.push_back(car);
        }
        void listCars() {
            for (Car* car : cars) {
                cout << "Car ID: " << car->getId() << ", Name: " << car->getName() << endl;
            }
        }
};

void garageTest() {
    Car car1("Toyota", 1);
    Car car2("Mclaren", 2);
    Garage myGarage;
    myGarage.parkCar(&car1);
    myGarage.parkCar(&car2);
    myGarage.listCars();
}

int main() {
    garageTest();
    return 0;
}
