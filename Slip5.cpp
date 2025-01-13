// Develop an object-oriented program in C++ to create a database of student information system.
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string className;
    char division;
    string dob;
    string bloodGroup;
    string address;
    string telephone;
    string drivingLicense;
    static int studentCount; // Static member

public:
    // Default constructor
    Student() {
        name = "Unknown";
        rollNumber = 0;
        className = "Unknown";
        division = 'U';
        dob = "00-00-0000";
        bloodGroup = "Unknown";
        address = "Unknown";
        telephone = "Unknown";
        drivingLicense = "Unknown";
        studentCount++;
    }

    // Parameterized constructor
    Student(string name, int roll, string cls, char div, string dob, string bg, string addr, string tel, string dl) :
        name(name), rollNumber(roll), className(cls), division(div), dob(dob), bloodGroup(bg), address(addr), telephone(tel), drivingLicense(dl) {
        studentCount++;
    }

    // Copy constructor
    Student(const Student& other) {
        name = other.name;
        rollNumber = other.rollNumber;
        className = other.className;
        division = other.division;
        dob = other.dob;
        bloodGroup = other.bloodGroup;
        address = other.address;
        telephone = other.telephone;
        drivingLicense = other.drivingLicense;
        studentCount++;
    }

    // Destructor
    ~Student() {
        studentCount--;
    }

    // Static member function
    static int getStudentCount() {
        return studentCount;
    }

    // Inline function to display details
    void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << className << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Address: " << address << endl;
        cout << "Telephone: " << telephone << endl;
        cout << "Driving License: " << drivingLicense << endl;
    }

    // Dynamic memory allocation using new operator
    void* operator new(size_t size) {
        cout << "Allocating memory for Student object...\n";
        return ::operator new(size);
    }

    // Dynamic memory deallocation using delete operator
    void operator delete(void* ptr) {
        cout << "Deallocating memory for Student object...\n";
        ::operator delete(ptr);
    }
};

// Initialize static member
int Student::studentCount = 0;

int main() {
    Student* student1 = new Student("John Doe", 101, "MCA", 'A', "01-01-2000", "O+", "123 Street", "1234567890", "DL12345");
    cout << "Student Details:\n";
    student1->displayDetails();

    cout << "\nTotal Students: " << Student::getStudentCount() << endl;

    delete student1;

    cout << "\nTotal Students after deletion: " << Student::getStudentCount() << endl;

    return 0;
}

