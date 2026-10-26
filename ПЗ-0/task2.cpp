#include <iostream>
using namespace std;

int main() {
    double x, y;
    cin >> x >> y;

    int day = 1;
    double sum = x;

    // сначала проверка, потом тело
    while (sum < y) {
        sum *= 1.1;
        day++;
    }

    cout << day << "\n";
    return 0;
}
