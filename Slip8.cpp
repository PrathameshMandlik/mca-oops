// Imagine a publishing company that handles books and tapes.
#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0f) {}

    void getData() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    void displayData() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Book : public Publication {
private:
    int pageCount;

public:
    Book() : pageCount(0) {}

    void getData() {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
    }

    void displayData() const {
        Publication::displayData();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication {
private:
    float playingTime;

public:
    Tape() : playingTime(0.0f) {}

    void getData() {
        Publication::getData();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
    }

    void displayData() const {
        Publication::displayData();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book book;
    Tape tape;

    try {
        cout << "Enter book details:\n";
        book.getData();
        cout << "\nEnter tape details:\n";
        tape.getData();

        cout << "\nBook Details:\n";
        book.displayData();

        cout << "\nTape Details:\n";
        tape.displayData();
    } catch (...) {
        cout << "An error occurred! Resetting all values to zero.\n";
        book = Book();
        tape = Tape();
    }

    return 0;
}
