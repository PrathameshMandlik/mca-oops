// Implement a class Quadratic that represents degree two polynomials.
// 1. Constructor (including a default constructor which creates the 0 polynomial).
// 2. Overloaded operator+ to add two polynomials of degree 2.
// 3. Overloaded << and >> to print and read polynomials.
// 4. A function eval that computes the value of a polynomial for a given value of x.
// 5. A function that computes the two solutions of the equation ax^2 + bx + c = 0.
#include <iostream>
#include <cmath>
using namespace std;

class Quadratic {
private:
    double a, b, c;

public:
    // Default constructor
    Quadratic() : a(0), b(0), c(0) {}

    // Parameterized constructor
    Quadratic(double a, double b, double c) : a(a), b(b), c(c) {}

    // Overloaded operator+ to add two polynomials
    Quadratic operator+(const Quadratic& other) {
        return Quadratic(a + other.a, b + other.b, c + other.c);
    }

    // Overloaded >> to input a polynomial
    friend istream& operator>>(istream& in, Quadratic& q) {
        cout << "Enter coefficient of x^2: ";
        in >> q.a;
        cout << "Enter coefficient of x: ";
        in >> q.b;
        cout << "Enter constant term: ";
        in >> q.c;
        return in;
    }

    // Overloaded << to output a polynomial
    friend ostream& operator<<(ostream& out, const Quadratic& q) {
        out << q.a << "x^2 ";
        out << (q.b >= 0 ? "+ " : "") << q.b << "x ";
        out << (q.c >= 0 ? "+ " : "") << q.c;
        return out;
    }

    // Function to evaluate the polynomial for a given x
    double eval(double x) {
        return a * x * x + b * x + c;
    }

    // Function to find the roots of the polynomial
    void findRoots() {
        double discriminant = b * b - 4 * a * c;
        if (discriminant > 0) {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Roots are real and distinct: " << root1 << " and " << root2 << endl;
        } else if (discriminant == 0) {
            double root = -b / (2 * a);
            cout << "Roots are real and equal: " << root << endl;
        } else {
            double realPart = -b / (2 * a);
            double imagPart = sqrt(-discriminant) / (2 * a);
            cout << "Roots are complex: " << realPart << "+" << imagPart << "i and "
                 << realPart << "-" << imagPart << "i" << endl;
        }
    }
};

int main() {
    Quadratic q1, q2;
    cout << "Enter first quadratic polynomial:\n";
    cin >> q1;
    cout << "Enter second quadratic polynomial:\n";
    cin >> q2;

    Quadratic sum = q1 + q2;
    cout << "Sum of polynomials: " << sum << endl;

    double x;
    cout << "Enter a value for x to evaluate the first polynomial: ";
    cin >> x;
    cout << "Value: " << q1.eval(x) << endl;

    cout << "Finding roots of the first polynomial:\n";
    q1.findRoots();

    return 0;
}
