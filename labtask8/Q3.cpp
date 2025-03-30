#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BigInteger {
private:
    vector<int> digits;
    bool isNegative;

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            isNegative = false;
        }
    }

public:
    BigInteger(string num) {
        isNegative = (num[0] == '-');
        for (int i = num.length() - 1; i >= (isNegative ? 1 : 0); i--) {
            digits.push_back(num[i] - '0');
        }
        removeLeadingZeros();
    }

    BigInteger operator+(const BigInteger& other) const {
        if (isNegative == other.isNegative) {
            BigInteger result = addAbs(*this, other);
            result.isNegative = isNegative;
            return result;
        }
        if (absGreater(*this, other)) {
            BigInteger result = subtractAbs(*this, other);
            result.isNegative = isNegative;
            return result;
        } else {
            BigInteger result = subtractAbs(other, *this);
            result.isNegative = other.isNegative;
            return result;
        }
    }

    friend ostream& operator<<(ostream& os, const BigInteger& num) {
        if (num.isNegative) os << "-";
        for (int i = num.digits.size() - 1; i >= 0; i--) {
            os << num.digits[i];
        }
        return os;
    }

    static BigInteger addAbs(const BigInteger& a, const BigInteger& b) {
        BigInteger result("0");
        result.digits.clear();
        int carry = 0, sum;
        for (size_t i = 0; i < max(a.digits.size(), b.digits.size()) || carry; i++) {
            sum = carry;
            if (i < a.digits.size()) sum += a.digits[i];
            if (i < b.digits.size()) sum += b.digits[i];
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }
        return result;
    }

    static BigInteger subtractAbs(const BigInteger& a, const BigInteger& b) {
        BigInteger result("0");
        result.digits.clear();
        int borrow = 0, diff;
        for (size_t i = 0; i < a.digits.size(); i++) {
            diff = a.digits[i] - borrow - (i < b.digits.size() ? b.digits[i] : 0);
            borrow = diff < 0;
            if (borrow) diff += 10;
            result.digits.push_back(diff);
        }
        result.removeLeadingZeros();
        return result;
    }

    static bool absGreater(const BigInteger& a, const BigInteger& b) {
        if (a.digits.size() != b.digits.size()) return a.digits.size() > b.digits.size();
        for (int i = a.digits.size() - 1; i >= 0; i--) {
            if (a.digits[i] != b.digits[i]) return a.digits[i] > b.digits[i];
        }
        return false;
    }
};

int main() {
    BigInteger num1("12345678901234567890");
    BigInteger num2("98765432109876543210");
    cout << "Sum: " << (num1 + num2) << endl;
    return 0;
}
