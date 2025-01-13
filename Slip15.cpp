/*Slip oops_115: Write a C++ program to read the data of N employee and compute Net salary of each
employee (DA=52% of Basic and Income Tax (IT) =30% of the gross salary).*/
#include <iostream>
#include <string>
using namespace std;

class Employee {
    int emp_num;
    string emp_name;
    float emp_basic;
    float emp_da;
    float emp_it;
    float net_sal;

public:
    void get_details();
    void find_net_sal();
    void show_emp_details();
};

void Employee::get_details() {
    cout << "\nEnter employee number: ";
    cin >> emp_num;
    cin.ignore(); // Clear input buffer before reading a string
    cout << "Enter employee name: ";
    getline(cin, emp_name);
    cout << "Enter employee basic salary: ";
    cin >> emp_basic;
}

void Employee::find_net_sal() {
    emp_da = 0.52 * emp_basic;
    emp_it = 0.30 * (emp_basic + emp_da);
    net_sal = (emp_basic + emp_da) - emp_it;
}

void Employee::show_emp_details() {
    cout << "\n\nDetails of Employee: " << emp_name;
    cout << "\nEmployee Number: " << emp_num;
    cout << "\nBasic Salary: " << emp_basic;
    cout << "\nEmployee DA: " << emp_da;
    cout << "\nIncome Tax: " << emp_it;
    cout << "\nNet Salary: " << net_sal << endl;
}

int main() {
    Employee emp[10];
    int num;

    cout << "\nEnter the number of employees: ";
    cin >> num;

    if (num <= 0 || num > 10) {
        cout << "Invalid number of employees! Exiting program." << endl;
        return 1;
    }

    // Input details
    for (int i = 0; i < num; i++) {
        cout << "\nEnter details for employee " << i + 1 << ":\n";
        emp[i].get_details();
    }

    // Calculate net salary
    for (int i = 0; i < num; i++) {
        emp[i].find_net_sal();
    }

    // Display details
    cout << "\nEmployee Details:\n";
    for (int i = 0; i < num; i++) {
        emp[i].show_emp_details();
    }

    // Pause the screen (optional)
    cin.get(); // Wait for user input
    return 0;
}

