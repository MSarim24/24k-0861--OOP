#include <iostream>
#include <windows.h>

using namespace std;

class Blend {
public:
    void blendJuice() {
        cout << "Selecting fruits..." << endl;
        cout << "Blending juice" << flush;
        
        for (int i = 0; i < 5; ++i) {
            cout << "." << flush;
            Sleep(1000);
        }
        
        cout << "\nBlending complete!" << endl;
    }
};

class Grind {
public:
    void grindJuice() {
        cout << "Grinding the juice..." << endl;
        Sleep(5000);
        cout << "Grinding complete!" << endl;
    }
};

class JuiceMaker {
private:
    Blend blender;
    Grind grinder;

public:
    void makeJuice() {
        cout << "Starting Juice Making Process..." << endl;
        blender.blendJuice();
        grinder.grindJuice();
        cout << "Juice is ready! Enjoy your fresh juice!" << endl;
    }
};

int main() {
    JuiceMaker juicer;
    juicer.makeJuice();
    return 0;
}
