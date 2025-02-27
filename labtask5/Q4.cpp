#include <iostream>
using namespace std;

class Blend {
    public:
        void BlendJuice() {
            cout << "Blending juice..." << endl;
            for (int i = 0; i < 5; i++) {
                cout << "Blending..." << endl;
            }
            cout << "Juice blended successfully!" << endl;
        }
};

class Grind {
    public:
        void GrindJuice() {
            cout << "Grinding juice..." << endl;
            for (int i = 0; i < 5; i++) {
                cout << "Grinding..." << endl;
            }
            cout << "Juice ground successfully!" << endl;
        }
};

class JuiceMaker {
    private:
        Blend blender;
        Grind grinder;
    public:
        void MakeJuice() {
            blender.BlendJuice();
            grinder.GrindJuice();
        }
};

void JuiceMakerTest() {
    JuiceMaker jm;
    jm.MakeJuice();
}

int main() {
    JuiceMakerTest();
    return 0;
}
