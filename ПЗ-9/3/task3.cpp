#include <fstream>
#include <string>
#include <cctype>
using namespace std;

string toBinary(unsigned long long n) {
    if (n == 0) return "0";
    string res = "";
    while (n > 0) {
        res = char('0' + n % 2) + res;
        n /= 2;
    }
    return res;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    string s;
    getline(in, s);
    string num = "";
    for (char c : s) {
        if (isdigit(c)) {
            num += c;
        } else {
            if (num != "") {
                out << toBinary(stoull(num));
                num = "";
            }
            out << c;
        }
    }
    if (num != "") {
        out << toBinary(stoull(num));
    }
    return 0;
}
