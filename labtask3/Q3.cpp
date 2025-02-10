#include <iostream>
using namespace std;

class Glass{ 
    public:
        int LiquidLevel = 200;
        
        void Drink(int d){
            if (d < 0) {
                cout << "Invalid amount. Please enter a positive number." << endl;
                return;
            }

            if (d > LiquidLevel) {
                cout << "Not enough liquid! You only have " << LiquidLevel << " ml left." << endl;
                return;
            }
            LiquidLevel -= d;
            Refill();
        };
        void Refill(){
            if(LiquidLevel < 100){
                LiquidLevel = 200;
            }
        }

};

int main()
{
    Glass person;
    int drank;
    cout<<"Enter -1 to stop..."<<endl;
    while(1){
        cout<<"Liquid Level: "<<person.LiquidLevel<<endl;
        cout<<"Enter the amout you drank: ";
        cin>>drank;
        if(drank == -1){
            break;
        }
        person.Drink(drank);
    }

    return 0;
}