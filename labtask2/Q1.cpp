#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Please provide the size of the array as a command-line argument." << endl;
        return 1;
    }

    int size = atoi(argv[1]); 
    float* arr = new float[size]; 

    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Element " << (i + 1) << ": ";
        cin >> *(arr + i); 
    }

    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i); 
    }

    cout << "Sum of the elements: " << sum << endl;

    return 0;
}
