/*Slip oops_123: Use virtual function to calculate area for different shapes C++.*/
#include <iostream>
#include <cmath>
using namespace std;

// Base class
class Shape {
public:
    virtual void calculateArea() {
        cout << "Area calculation is not defined for the base shape." << endl;
    }
};

// Derived class for Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    void calculateArea() override {
        double area = M_PI * radius * radius;
        cout << "Area of Circle with radius " << radius << " is: " << area << endl;
    }
};

// Derived class for Rectangle
class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    void calculateArea() override {
        double area = length * width;
        cout << "Area of Rectangle with length " << length << " and width " << width << " is: " << area << endl;
    }
};

// Derived class for Triangle
class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}

    void calculateArea() override {
        double area = 0.5 * base * height;
        cout << "Area of Triangle with base " << base << " and height " << height << " is: " << area << endl;
    }
};

// Main function
int main() {
    Shape* shape; // Pointer to base class

    int choice;
    cout << "Select the shape to calculate area:\n";
    cout << "1. Circle\n2. Rectangle\n3. Triangle\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        double radius;
        cout << "Enter the radius of the circle: ";
        cin >> radius;
        Circle circle(radius);
        shape = &circle;
        shape->calculateArea();
        break;
    }
    case 2: {
        double length, width;
        cout << "Enter the length and width of the rectangle: ";
        cin >> length >> width;
        Rectangle rectangle(length, width);
        shape = &rectangle;
        shape->calculateArea();
        break;
    }
    case 3: {
        double base, height;
        cout << "Enter the base and height of the triangle: ";
        cin >> base >> height;
        Triangle triangle(base, height);
        shape = &triangle;
        shape->calculateArea();
        break;
    }
    default:
        cout << "Invalid choice! Please select a valid shape." << endl;
        break;
    }

    return 0;
}