#include <iostream>
using namespace std;

int main() {
    double x, y;
    cin >> x >> y;

    int day;
    double sum = x;

    for (day = 1; sum < y; day++) {
        sum *= 1.1;
    }

    cout << day << "\n";
    return 0;
}
