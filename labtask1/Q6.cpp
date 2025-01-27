#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    float arr[5];
    float avg = 0;
    string name1,name2;
    cout<<"Enter the name and test scores: ";
    cin>>name1;
    cin>>name2;
    for(int i = 0;i<5;i++){
        cin>>arr[i];
        avg += arr[i];
    }
    avg = avg/5;
    cout<<"Student Name: "<<name1<<" ";
    cout<<name2<<endl;
    cout<<"Test Score: ";
    for(int i = 0;i<5;i++){
        cout<<fixed<<setprecision(2);
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Average scores: "<<avg;
    return 0;
}