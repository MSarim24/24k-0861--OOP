#include <iostream>
#include <string>
using namespace std;
struct customer {
    int id;
    string name;
    int units;
};
int main()
{
    struct customer cst;
    float total,surcharge,charge;
    cout<<"Enter the customerID: ";
    cin>>cst.id;
    cout<<"Enter the customerName: ";
    cin>>cst.name;
    cout<<"Enter the Units: ";
    cin>>cst.units;
    cout<<"Customer Id: "<<cst.id<<endl<<"Customer Name: "<<cst.name<<endl<<"Units consumed: "<<cst.units<<endl;
    if (cst.units>0 & cst.units<= 199){
        charge = 16.2;
    }
    else if (cst.units>=200 &cst.units<300){
        charge = 20.10;
    }
    else if (cst.units>=300 & cst.units<500){
        charge = 27.10;
    }
    else {
        charge = 35.90;
    }
    total = cst.units*charge;
    if (total>18000){
        surcharge = total*0.15;
    }
    cout<<"Amount Charges @Rs."<<charge<<" per unit: "<<total<<endl;
    cout<<"Surcharge Amount: "<<surcharge<<endl;
    total = total + surcharge;
    cout<<"Net Amount Paid by the Customer: "<<total<<endl;
    return 0;
}