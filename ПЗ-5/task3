#include <iostream>

using namespace std;

int main() {
    double x, y;
    if (!(cin >> x >> y)) return 0;

    double total = x;
    double current = x;
    int day = 1;

    // Если уже в первый день общая сумма достигла или превысила Y
    if (total >= y) {
        cout << day << "\n";
        return 0;
    }

    // Цикл do-while гарантирует выполнение тела хотя бы один раз перед проверкой условия
    do {
        current *= 1.1;
        total += current;
        day++;
    } while (total < y);

    cout << day << "\n";
    return 0;
}
