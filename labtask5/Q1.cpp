#include <iostream>
using namespace std;

class Engine {
    private:
        bool isRunning;
    public:
        Engine() : isRunning(false) {}
        void start() {
            isRunning = true;
            cout << "Engine started" << endl;
        }
        void stop() {
            isRunning = false;
            cout << "Engine stopped" << endl;
        }
};

class Car {
    private:
        Engine engine;
    public:
        void startCar() {
            engine.start();
        }
        void stopCar() {
            engine.stop();
        }
};

void carTest() {
    Car myCar;
    myCar.startCar();
    myCar.stopCar();
}

int main() {
    carTest();
    return 0;
}
