#include <iostream>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode, currencySymbol;
public:
    Currency(double amt, string code, string symbol) : amount(amt), currencyCode(code), currencySymbol(symbol) {}
    virtual double convertToBase() = 0;
    virtual double convertTo(Currency* targetCurrency) = 0;
    virtual void displayCurrency() {
        cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

class Dollar : public Currency {
private:
    double exchangeRateToBase;
public:
    Dollar(double amt) : Currency(amt, "USD", "$"), exchangeRateToBase(1.0) {}
    double convertToBase() override {
        return amount * exchangeRateToBase;
    }
    double convertTo(Currency* targetCurrency) override {
        return convertToBase() / targetCurrency->convertToBase();
    }
};

class Euro : public Currency {
private:
    double exchangeRateToBase;
public:
    Euro(double amt) : Currency(amt, "EUR", "€"), exchangeRateToBase(1.1) {}
    double convertToBase() override {
        return amount * exchangeRateToBase;
    }
    double convertTo(Currency* targetCurrency) override {
        return convertToBase() / targetCurrency->convertToBase();
    }
};

class Rupee : public Currency {
private:
    double exchangeRateToBase;
public:
    Rupee(double amt) : Currency(amt, "INR", "₹"), exchangeRateToBase(0.012) {}
    double convertToBase() override {
        return amount * exchangeRateToBase;
    }
    double convertTo(Currency* targetCurrency) override {
        return convertToBase() / targetCurrency->convertToBase();
    }
};

int main() {
    Dollar usd(100);
    Euro eur(100);
    Rupee inr(100);
    
    cout << "Converting 100 USD to EUR: " << usd.convertTo(&eur) << " EUR" << endl;
    cout << "Converting 100 USD to INR: " << usd.convertTo(&inr) << " INR" << endl;
    cout << "Converting 100 EUR to USD: " << eur.convertTo(&usd) << " USD" << endl;
    
    return 0;
}
