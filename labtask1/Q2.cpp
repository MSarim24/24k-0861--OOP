#include <iostream>
using namespace std;

int main()
{
    int arr[10];
    int sum = 0;
    char stop;
    for(int i = 0; i<10;i++){
        cout<<"Enter the number: ";
        cin>>*(arr+i);
        sum += *(arr+i);
    }
    cout<<"sum = "<<sum;
    return 0;
}