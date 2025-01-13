/*Slip oops_127: Write a Program to find Maximum out of Two Numbers using friend function*/
#include <iostream>
using namespace std;

class Numbers {
private:
    int num1, num2;

public:
    // Constructor to initialize numbers
    Numbers(int n1, int n2) : num1(n1), num2(n2) {}

    // Friend function declaration
    friend int findMax(Numbers n);
};

// Friend function to find the maximum of two numbers
int findMax(Numbers n) {
    return (n.num1 > n.num2) ? n.num1 : n.num2;
}

int main() {
    int number1, number2;

    cout << "Enter the first number: ";
    cin >> number1;

    cout << "Enter the second number: ";
    cin >> number2;

    Numbers nums(number1, number2); // Create an object of the class

    // Find and display the maximum number
    cout << "The maximum number is: " << findMax(nums) << endl;

    return 0;
}