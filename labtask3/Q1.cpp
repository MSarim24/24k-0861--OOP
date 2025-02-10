#include <iostream>
#include <string>
using namespace std;
class User{
    public:
        int Age;
        string Name;
        User(int a,string n){
            Age = a;
            Name = n;
        }
};
int main()
{
    User person(24,"Teo");
    cout<<"My name is "<<person.Name<<" and I'm "<<person.Age<<endl;
    return 0;
}