#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream in1("input1.txt");
    ifstream in2("input2.txt");
    string x, y;
    in1 >> x;
    in2 >> y;
    if (x.find(y) != string::npos) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}