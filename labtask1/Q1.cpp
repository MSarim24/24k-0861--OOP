#include <iostream>
using namespace std;

int main()
{
    float arr[20];
    float max = -999999;
    float max2 = -999999;
    for(int i = 0; i<20; i++){
        cout<<"Enter a number for Element"<<i+1<<": ";
        cin>>*(arr+i);
    }
    for(int i = 0; i<20; i++){
        if(arr[i]>=max){
            max = *(arr+i);
        }
        else if(*(arr+i)> max2){
            max2 = *(arr+i);
        }
    }
    cout<<"The second highest Element: "<<max2;
    return 0;
}