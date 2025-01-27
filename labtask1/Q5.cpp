#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

int main()
{
    string name;
    int atp,ctp,ats,cts;
    float gross, amount,grosprc, sale,nts;
    cout<<"Enter the movie name: ";
    getline(cin, name);
    cout<<"Enter the adult ticket price: ";
    cin>>atp;
    cout<<"Enter the child ticket price: ";
    cin>>ctp;
    cout<<"Enter the adult ticket sold: ";
    cin>>ats;
    cout<<"Enter the child ticket sold: ";
    cin>>cts;
    cout<<"Enter the percentage of the gross amount to donated: ";
    cin>>grosprc;
    cout<<endl<<endl<<endl;
    nts = ats + cts;
    gross = (ats * atp) + (cts * ctp);
    amount = gross * (grosprc/100.0);
    sale = gross - amount;
    for(int i = 0; i<33; i++){
        cout<<"-*";
    }
    cout<<endl;
    string arr[6] = {"Movie Name:","Number of Ticket of sold:","Gross Amount:","Percentage of Gross Amount Donated:","Amount Donated:","Net Sale:"};
    for(int i = 0; i<6; i++){
        cout<<arr[i];
        for(int j = 48-arr[i].size(); j>0; j--){
            cout<<".";
        }
        switch (i)
        {
        case 0:
            cout<<name<<endl;
            break;
        case 1:
            cout<<nts<<endl;
            break;
        case 2:
            cout<<"$"<<gross<<endl;
            break;
        case 3:
            cout<<grosprc<<"%"<<endl;
            break;
        case 4:
            cout<<fixed<<setprecision(2);
            cout<<"$"<<amount<<endl;
            break;
        case 5:
            cout<<fixed<<setprecision(2);
            cout<<"$"<<sale<<endl;
            break;
        default:
            break;
        }
    }
    return 0;
}