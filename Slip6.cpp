/*Slip oops_106: Create a class template to represent a generic vector. Include the following member functions:
1. To create the vector.
2. To modify the value of a given element.
3. To multiply by a scalar value.
4. To display the vector in the form (10,20,30,…).*/
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class GenericVector {
private:
    vector<T> elements;

public:
    // 1. Constructor to create the vector
    GenericVector(const vector<T>& elems) : elements(elems) {}

    // 2. Modify the value of a given element
    void modify(size_t index, const T& value) {
        if (index >= elements.size()) {
            throw out_of_range("Index out of range");
        }
        elements[index] = value;
    }

    // 3. Multiply the vector by a scalar value
    void multiplyByScalar(const T& scalar) {
        for (T& elem : elements) {
            elem *= scalar;
        }
    }

    // 4. Display the vector in the form (10,20,30,…)
    void display() const {
        cout << "(";
        for (size_t i = 0; i < elements.size(); ++i) {
            cout << elements[i];
            if (i < elements.size() - 1) {
                cout << ",";
            }
        }
        cout << ")" << endl;
    }
};

int main() {
    try {
        // Create a vector of integers
        GenericVector<int> intVector({10, 20, 30, 40});
        cout << "Initial vector: ";
        intVector.display();

        // Modify an element
        intVector.modify(2, 35); // Change the 3rd element to 35
        cout << "After modification: ";
        intVector.display();

        // Multiply by a scalar
        intVector.multiplyByScalar(2); // Multiply all elements by 2
        cout << "After multiplying by scalar: ";
        intVector.display();

        // Create a vector of doubles
        GenericVector<double> doubleVector({1.1, 2.2, 3.3});
        cout << "\nInitial double vector: ";
        doubleVector.display();

        // Modify an element
        doubleVector.modify(1, 4.4); // Change the 2nd element to 4.4
        cout << "After modification: ";
        doubleVector.display();

        // Multiply by a scalar
        doubleVector.multiplyByScalar(1.5); // Multiply all elements by 1.5
        cout << "After multiplying by scalar: ";
        doubleVector.display();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
