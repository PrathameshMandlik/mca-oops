/*Slip oops_125: Write a C++ program to use pointer for both base and derived classes and call the member function. Use Virtual keyword.*/
#include <iostream>
using namespace std;

// Base Class with pure virtual function (Abstract Class)
class Shape {
public:
    // Pure virtual function
    virtual void area() = 0;

    // Virtual destructor
    virtual ~Shape() {}
};

// Derived Class 1: Circle
class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) : radius(r) {}

    void area() override {
        cout << "Area of circle: " << 3.14 * radius * radius << " square units." << endl;
    }
};

// Derived Class 2: Rectangle
class Rectangle : public Shape {
private:
    float length, breadth;

public:
    Rectangle(float l, float b) : length(l), breadth(b) {}

    void area() override {
        cout << "Area of rectangle: " << length * breadth << " square units." << endl;
    }
};

int main() {
    Shape* shapePtr;

    // Dynamic memory allocation for Circle and Rectangle
    Circle* circleObj = new Circle(5);
    shapePtr = circleObj;
    cout << "Using pointer to base class to call area() for Circle:" << endl;
    shapePtr->area();  // Calls Circle's area()

    Rectangle* rectObj = new Rectangle(4, 6);
    shapePtr = rectObj;
    cout << "\nUsing pointer to base class to call area() for Rectangle:" << endl;
    shapePtr->area();  // Calls Rectangle's area()

    // Cleanup
    delete circleObj;
    delete rectObj;

    return 0;
}