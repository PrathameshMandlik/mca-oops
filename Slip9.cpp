// Write a function to count and display the number of lines not starting with 'A' in a text file.
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

void countLinesNotStartingWithA() {
    ifstream file("STORY.TXT");
    if (!file) {
        cerr << "Error: Unable to open file STORY.TXT" << endl;
        return;
    }

    string line;
    int count = 0;

    while (getline(file, line)) {
        if (line.empty() || toupper(line[0]) != 'A') {
            count++;
        }
    }

    file.close();
    cout << "Number of lines not starting with 'A': " << count << endl;
}

int main() {
    countLinesNotStartingWithA();
    return 0;
}
