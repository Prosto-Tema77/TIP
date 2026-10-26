#include <iostream>

using namespace std;

int main() {
    double x, y;
    if (!(cin >> x >> y)) return 0;

    int day = 1;

    // В инициализации объявляются total и current, в третьем блоке происходит обновление данных
    for (double total = x, current = x; total < y; current *= 1.1, total += current, day++);

    cout << day << "\n";
    return 0;
}
