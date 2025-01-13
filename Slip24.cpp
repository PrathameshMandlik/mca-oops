/*Slip oops_124: Write a C++ program for Exception handling divide by zero using C++.*/
#include <iostream>
#include <stdexcept>
using namespace std;

double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw runtime_error("Division by zero is not allowed.");
    }
    return numerator / denominator;
}

int main() {
    double numerator, denominator, result;

    cout << "Enter the numerator: ";
    cin >> numerator;

    cout << "Enter the denominator: ";
    cin >> denominator;

    try {
        result = divide(numerator, denominator);
        cout << "Result: " << numerator << " / " << denominator << " = " << result << endl;
    } catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}