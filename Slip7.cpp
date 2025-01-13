/*Slip oops_107: Create a class Rational Number (fractions) with the following capabilities:
a) Create a constructor that prevents a 0 denominator in a fraction, reduces or simplifies fractions that are not in reduced form and avoids negative denominators.
b) Overload the addition, subtraction, multiplication and division operators for this class.
c) Overload the relational and equality operators for this class.*/
#include <iostream>
#include <stdexcept> // For std::invalid_argument
using namespace std;

// Helper function to calculate GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Rational {
private:
    int numerator;
    int denominator;

    // Helper function to simplify the fraction
    void simplify() {
        int gcdValue = gcd(abs(numerator), abs(denominator)); // Use absolute values for GCD
        numerator /= gcdValue;
        denominator /= gcdValue;
        if (denominator < 0) { // Avoid negative denominators
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Constructor
    Rational(int num = 0, int denom = 1) {
        if (denom == 0) throw invalid_argument("Denominator cannot be zero.");
        numerator = num;
        denominator = denom;
        simplify();
    }

    // Overload + operator
    Rational operator+(const Rational& other) const {
        return Rational(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    // Overload - operator
    Rational operator-(const Rational& other) const {
        return Rational(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    // Overload * operator
    Rational operator*(const Rational& other) const {
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }

    // Overload / operator
    Rational operator/(const Rational& other) const {
        if (other.numerator == 0) throw invalid_argument("Division by zero.");
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }

    // Overload relational operators
    bool operator==(const Rational& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator<(const Rational& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Rational& other) const {
        return other < *this;
    }

    bool operator<=(const Rational& other) const {
        return !(*this > other);
    }

    bool operator>=(const Rational& other) const {
        return !(*this < other);
    }

    // Friend function for output
    friend ostream& operator<<(ostream& out, const Rational& r) {
        if (r.denominator == 1) {
            out << r.numerator;
        } else {
            out << r.numerator << "/" << r.denominator;
        }
        return out;
    }
};

int main() {
    try {
        Rational r1(6, 8); // Automatically simplified to 3/4
        Rational r2(4, 5);

        cout << "R1: " << r1 << endl; // Should print 3/4
        cout << "R2: " << r2 << endl; // Should print 4/5

        cout << "Addition: " << (r1 + r2) << endl; // Addition of fractions
        cout << "Subtraction: " << (r1 - r2) << endl; // Subtraction of fractions
        cout << "Multiplication: " << (r1 * r2) << endl; // Multiplication of fractions
        cout << "Division: " << (r1 / r2) << endl; // Division of fractions

        cout << "Comparison (R1 < R2): " << (r1 < r2) << endl; // Relational operator
        cout << "Comparison (R1 == R2): " << (r1 == r2) << endl; // Equality operator

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
