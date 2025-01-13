/*Slip oops_122: Write C++ Program to display the cube of the number upto a given integer using constructor overloading.*/
#include <iostream>
using namespace std;

class CubeCalculator {
public:
    // Default constructor
    CubeCalculator() {
        cout << "No number provided. Please provide a valid integer!" << endl;
    }

    // Parameterized constructor
    CubeCalculator(int n) {
        cout << "Calculating cubes of numbers from 1 to " << n << "..." << endl;
        for (int i = 1; i <= n; i++) {
            cout << "Cube of " << i << " is " << i * i * i << endl;
        }
    }
};

int main() {
    int choice;
    cout << "Do you want to calculate cubes? Enter 1 for YES, 0 for NO: ";
    cin >> choice;

    if (choice == 1) {
        int number;
        cout << "Enter the number up to which you want the cubes: ";
        cin >> number;

        // Invoking the parameterized constructor
        CubeCalculator calc(number);
    } else {
        // Invoking the default constructor
        CubeCalculator calc;
    }

    return 0;
}