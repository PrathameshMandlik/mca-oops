/*Slip oops_120: Write a C++ program to create an array of pointers. Invoke functions using array objects.*/
#include <iostream>
using namespace std;

class A {
public:
    virtual void show() {
        cout << "A\n";
    }
};

class B : public A {
public:
    void show() override {
        cout << "B\n";
    }
};

class C : public A {
public:
    void show() override {
        cout << "C\n";
    }
};

class D : public A {
public:
    void show() override {
        cout << "D\n";
    }
};

class E : public A {
public:
    void show() override {
        cout << "E\n";
    }
};

int main() {
    A a;
    B b;
    C c;
    D d;
    E e;
    A* p[] = {&a, &b, &c, &d, &e};  // Array of pointers to base class A

    for (int j = 0; j < 5; j++) {
        p[j]->show();  // Polymorphic behavior
    }

    return 0;
}

