#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Polynomial
{
private:
    double* coeffs;
    int deg;

public:
    Polynomial() : deg(0) {
        coeffs = new double[1]{0};
    }

    Polynomial(int degree, double* coefficients) : deg(degree) {
        coeffs = new double[deg + 1];
        for (int i = 0; i <= deg; i++)
            coeffs[i] = coefficients[i];
    }

    ~Polynomial() {
        if (coeffs) {
            delete[] coeffs;
        }
    }

    Polynomial(const Polynomial& p2) : deg(p2.deg) {
        coeffs = new double[deg + 1];
        for (int i = 0; i <= deg; i++) {
            coeffs[i] = p2.coeffs[i];
        }
    }

    Polynomial(Polynomial&& p3) noexcept : deg(p3.deg), coeffs(p3.coeffs) {
        p3.deg = 0;
        p3.coeffs = nullptr;
    }

    int getDegree() const {
        return deg;
    }

    double evaluate(double x) const {
        double result = 0;
        for (int i = 0; i <= deg; i++) {
            result += coeffs[i] * pow(x, i);
        }
        return result;
    }

    Polynomial add(const Polynomial& p) const 
    {
        int maxDegree = max(deg, p.deg);
        double* newCoeffs = new double[maxDegree + 1]();
    
        for (int i = 0; i <= maxDegree; ++i) 
        {
            if (i <= deg)
            newCoeffs[i] += coeffs[i];
            if (i <= p.deg)
            newCoeffs[i] += p.coeffs[i];
        }
    
        return Polynomial(maxDegree, newCoeffs);
    }
    
    Polynomial multiply(const Polynomial& p) const
    {
        int newDegree = deg + p.deg;
        double* newCoeffs = new double[newDegree + 1]();
    
        for (int i = 0; i <= deg; ++i)
        {
            for (int j = 0; j <= p.deg; ++j)
            {
                newCoeffs[i + j] += coeffs[i] * p.coeffs[j];
            }
        }
    
        return Polynomial(newDegree, newCoeffs);
    }
    
    void print() const
    {
        bool firstTerm = true;
        bool hasNonZero = false;
        for (int i = deg; i >= 0; --i)
        {
            if (coeffs[i] != 0)
            {
                hasNonZero = true;
                if (!firstTerm && coeffs[i] > 0) 
                cout << " + ";
                if (i > 0) 
                {
                    cout << coeffs[i] << "x^" << i;
                }
                else
                {
                    cout << coeffs[i];
                }
                firstTerm = false;
            }
        }
        if (!hasNonZero)
            cout << "0";
        cout << endl;
    }
};

int main()
{
    double coeff1[] = {3, 2, 1};
    Polynomial p1(2, coeff1);

    double coeff2[] = {1, 0, -1};
    Polynomial p2(2, coeff2);

    cout << "Polynomial 1: ";
    p1.print();

    cout << "Polynomial 2: ";
    p2.print();

    cout << "Polynomial 1 evaluated at x = 2: " << p1.evaluate(2) << endl;

    Polynomial sum = p1.add(p2);
    cout << "Sum of Polynomials: ";
    sum.print();

    Polynomial product = p1.multiply(p2);
    cout << "Product of Polynomials: ";
    product.print();

    return 0;
}
