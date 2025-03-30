#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
private:
    vector<int> coefficients;
    void trim() {
        while (!coefficients.empty() && coefficients.back() == 0) {
            coefficients.pop_back();
        }
    }
public:
    Polynomial() {}
    Polynomial(const vector<int>& coeffs) : coefficients(coeffs) {
        trim();
    }
    friend ostream& operator<<(ostream& os, const Polynomial& p) {
        if (p.coefficients.empty()) {
            os << "0";
            return os;
        }
        for (int i = p.coefficients.size() - 1; i >= 0; --i) {
            if (p.coefficients[i] != 0) {
                if (i != p.coefficients.size() - 1 && p.coefficients[i] > 0) {
                    os << " + ";
                } else if (p.coefficients[i] < 0) {
                    os << " - ";
                }
                if (abs(p.coefficients[i]) != 1 || i == 0) {
                    os << abs(p.coefficients[i]);
                }
                if (i > 0) {
                    os << "x";
                    if (i > 1) {
                        os << "^" << i;
                    }
                }
            }
        }
        return os;
    }
    Polynomial operator+(const Polynomial& other) const {
        vector<int> result(max(coefficients.size(), other.coefficients.size()), 0);
        for (size_t i = 0; i < coefficients.size(); ++i) {
            result[i] += coefficients[i];
        }
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            result[i] += other.coefficients[i];
        }
        return Polynomial(result);
    }
    Polynomial operator-(const Polynomial& other) const {
        vector<int> result(max(coefficients.size(), other.coefficients.size()), 0);
        for (size_t i = 0; i < coefficients.size(); ++i) {
            result[i] += coefficients[i];
        }
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            result[i] -= other.coefficients[i];
        }
        return Polynomial(result);
    }
    Polynomial operator*(const Polynomial& other) const {
        vector<int> result(coefficients.size() + other.coefficients.size() - 1, 0);
        for (size_t i = 0; i < coefficients.size(); ++i) {
            for (size_t j = 0; j < other.coefficients.size(); ++j) {
                result[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return Polynomial(result);
    }
    friend class PolynomialUtils;
};

class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p, int x) {
        int result = 0;
        int power = 1;
        for (int coeff : p.coefficients) {
            result += coeff * power;
            power *= x;
        }
        return result;
    }
    static Polynomial derivative(const Polynomial& p) {
        if (p.coefficients.size() <= 1) {
            return Polynomial({0});
        }
        vector<int> deriv(p.coefficients.size() - 1);
        for (size_t i = 1; i < p.coefficients.size(); ++i) {
            deriv[i - 1] = p.coefficients[i] * i;
        }
        return Polynomial(deriv);
    }
};

int main() {
    Polynomial p1({3, 2, 1}); // 1x^2 + 2x + 3
    Polynomial p2({1, -1, 2}); // 2x^2 - 1x + 1

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p1 + p2: " << (p1 + p2) << endl;
    cout << "p1 - p2: " << (p1 - p2) << endl;
    cout << "p1 * p2: " << (p1 * p2) << endl;
    cout << "p1 evaluated at x=2: " << PolynomialUtils::evaluate(p1, 2) << endl;
    cout << "Derivative of p1: " << PolynomialUtils::derivative(p1) << endl;
    return 0;
}
