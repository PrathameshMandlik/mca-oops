/*data-title="Slip oops_126: Write a Program to find Maximum out of Two Numbers using friend function.Note: Here one number is a member of one class and the other number is member of some other class."*/
#include <iostream>
using namespace std;

// Forward declaration of class B
class B;

class A {
private:
    int num1;

public:
    A(int n1) : num1(n1) {}

    // Declare the friend function
    friend void findMax(A a, B b);
};

class B {
private:
    int num2;

public:
    B(int n2) : num2(n2) {}

    // Declare the friend function
    friend void findMax(A a, B b);
};

// Friend function to find the maximum of two numbers
void findMax(A a, B b) {
    if (a.num1 > b.num2) {
        cout << "Maximum number is: " << a.num1 << endl;
    } else {
        cout << "Maximum number is: " << b.num2 << endl;
    }
}

int main() {
    int number1, number2;

    cout << "Enter the first number: ";
    cin >> number1;

    cout << "Enter the second number: ";
    cin >> number2;

    A objA(number1); // Create an object of class A
    B objB(number2); // Create an object of class B

    findMax(objA, objB); // Call the friend function

    return 0;
}