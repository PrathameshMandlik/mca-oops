// Write a C++ program to create a calculator for arithmetic operators (+, -, *, /).
// The program takes two operands and performs operations based on user input.
#include <iostream>
using namespace std;

int main() {
    char choice;
    do {
        double num1, num2, result;
        char op;

        cout << "Enter first number, operator, second number: ";
        cin >> num1 >> op >> num2;

        switch (op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0) {
                    cout << "Error: Division by zero!\n";
                    continue;
                }
                result = num1 / num2;
                break;
            default:
                cout << "Invalid operator!\n";
                continue;
        }

        cout << "Answer = " << result << endl;
        cout << "Do another (y/n)? ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Goodbye!" << endl;
    return 0;
}
