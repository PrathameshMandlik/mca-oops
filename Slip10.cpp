// Write a C++ program using a base class 'convert' with pure virtual function 'compute'.
#include <iostream>
using namespace std;

class Convert {
protected:
    double val1; // Initial value
    double val2; // Converted value

public:
    Convert(double v) : val1(v), val2(0) {}

    virtual void compute() = 0; // Pure virtual function

    double getInit() const {
        return val1;
    }

    double getConv() const {
        return val2;
    }

    virtual ~Convert() {}
};

class CelsiusToFahrenheit : public Convert {
public:
    CelsiusToFahrenheit(double celsius) : Convert(celsius) {}

    void compute() override {
        val2 = (val1 * 9 / 5) + 32; // Conversion formula
    }
};

class MetersToFeet : public Convert {
public:
    MetersToFeet(double meters) : Convert(meters) {}

    void compute() override {
        val2 = val1 * 3.28084; // Conversion formula
    }
};

int main() {
    double celsius, meters;

    cout << "Enter temperature in Celsius: ";
    cin >> celsius;
    CelsiusToFahrenheit cToF(celsius);
    cToF.compute();
    cout << celsius << " Celsius = " << cToF.getConv() << " Fahrenheit" << endl;

    cout << "Enter distance in meters: ";
    cin >> meters;
    MetersToFeet mToF(meters);
    mToF.compute();
    cout << meters << " meters = " << mToF.getConv() << " feet" << endl;

    return 0;
}
