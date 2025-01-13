// Implement a class CppArray which is identical to a one-dimensional C++ array.
// 1. It performs range checking.
// 2. It allows assignment of one array to another using the assignment operator.
// 3. It supports a function to return the size of the array.
// 4. It allows reading and printing of the array using cout and cin.
#include <iostream>
#include <stdexcept>
using namespace std;

class CppArray {
private:
    int* arr;
    int size;

public:
    // Constructor
    CppArray(int size) : size(size) {
        if (size <= 0) throw invalid_argument("Size must be positive.");
        arr = new int[size];
    }

    // Destructor
    ~CppArray() {
        delete[] arr;
    }

    // Overloaded [] operator for range checking
    int& operator[](int index) {
        if (index < 0 || index >= size) throw out_of_range("Index out of range.");
        return arr[index];
    }

    // Assignment operator
    CppArray& operator=(const CppArray& other) {
        if (this == &other) return *this;
        delete[] arr;
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; ++i) arr[i] = other.arr[i];
        return *this;
    }

    // Function to get size
    int getSize() const {
        return size;
    }

    // Overloaded >> operator for input
    friend istream& operator>>(istream& in, CppArray& array) {
        for (int i = 0; i < array.size; ++i) {
            cout << "Enter element " << i + 1 << ": ";
            in >> array.arr[i];
        }
        return in;
    }

    // Overloaded << operator for output
    friend ostream& operator<<(ostream& out, const CppArray& array) {
        out << "[ ";
        for (int i = 0; i < array.size; ++i) out << array.arr[i] << " ";
        out << "]";
        return out;
    }
};

int main() {
    try {
        CppArray array1(5), array2(5);
        cout << "Enter elements for array1:\n";
        cin >> array1;
        cout << "Array1: " << array1 << endl;

        // Test range checking
        cout << "Accessing element at index 2: " << array1[2] << endl;

        // Test assignment operator
        array2 = array1;
        cout << "Array2 after assignment: " << array2 << endl;

        // Test size function
        cout << "Size of array1: " << array1.getSize() << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
