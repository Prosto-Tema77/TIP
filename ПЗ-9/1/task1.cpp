#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    string bad = "useragreement";
    char c;
    while (in.get(c)) {
        if (bad.find(tolower(c)) == string::npos) {
            out << c;
        }
    }
    return 0;
}
