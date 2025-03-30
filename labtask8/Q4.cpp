#include <iostream>
using namespace std;

class Number {
    private:
        int num;
    public:
        Number(int n) : num(n) {}

        Number& operator--() {
            num *= 4;
            return *this;
        }

        Number operator--(int) {
            Number temp = *this;
            num /= 4;
            return temp;
        }

        void display() {
            cout << "Number: " << num << endl;
        }
};

int main() {
    Number num(10);

    cout << "Original: ";
    num.display();

    --num;
    cout << "After Prefix Decrement: ";
    num.display();

    num--;
    cout << "After Postfix Decrement: ";
    num.display();

    return 0;
}
