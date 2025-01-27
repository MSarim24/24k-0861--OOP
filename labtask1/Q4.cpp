#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float weight_kg;
    cout << "Enter weight in kilograms: ";
    cin >> weight_kg;

    float weight_lb = weight_kg * 2.2; 
    cout << fixed <<  setprecision(2);
    cout << "Weight in kilograms: " << weight_kg << " kg" << endl;
    cout << "Equivalent weight in pounds: " << weight_lb << " lb" << endl;

    return 0;
}
