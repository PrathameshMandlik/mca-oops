/*Slip oops_116: Write a C++ to illustrate the concepts of console I/O operation*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
int main()
{
string filename = "test.txt";
ofstream fout(filename.c_str()); // default mode is ios::out | ios::trunc
if (!fout)
{
cerr << "error: open file for output failed!" << endl;
abort(); // in <cstdlib> header
}
fout << "apple" << endl;
fout << "orange" << endl;
fout << "banana" << endl;
fout.close();
ifstream fin(filename.c_str()); // default mode ios::in
if (!fin)
{
cerr << "error: open file for input failed!" << endl;
abort();
}
char ch;
while (fin.get(ch))
{ // till end-of-file
cout << ch;
}

fin.close();
return 0;
}
