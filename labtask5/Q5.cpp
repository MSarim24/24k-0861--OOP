#include <iostream>
using namespace std;

class Car {
    public:
        int engineHorsepower;
        int seatingCapacity;
        int noOfSpeakers;
        
        Car(int hp, int seats, int speakers) : engineHorsepower(hp), seatingCapacity(seats), noOfSpeakers(speakers) {}
        
        void SetValues(int hp, int seats, int speakers) const {
            Car* ptr = const_cast<Car*>(this);
            ptr->engineHorsepower = hp;
            ptr->seatingCapacity = seats;
            ptr->noOfSpeakers = speakers;
        }
        
        void Display() const {
            cout << "Engine Horsepower: " << engineHorsepower << endl;
            cout << "Seating Capacity: " << seatingCapacity << endl;
            cout << "Number of Speakers: " << noOfSpeakers << endl;
        }
};

void CarTest() {
    Car myCar(150, 5, 6);
    myCar.Display();
    myCar.SetValues(180, 7, 8);
    myCar.Display();
}

int main() {
    CarTest();
    return 0;
}
