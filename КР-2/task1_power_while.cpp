#include <iostream>
using namespace std;

// Возводит a в степень n.
// Используем две школьные формулы:
//   n чётное:   a^n = (a*a)^(n/2)  — возводим a в квадрат, степень вдвое меньше
//   n нечётное: a^n = a * a^(n-1)  — одно a забираем в ответ, степень на 1 меньше
// После нечётного шага n становится чётным, и следующий шаг делит его пополам,
// поэтому шагов около 2 * log2(n).
long long power(long long a, long long n) {
    long long res = 1;  // сюда собираем ответ
    while (n > 0) {
        if (n % 2 == 0) {
            a = a * a;
            n = n / 2;
        } else {
            res = res * a;
            n = n - 1;
        }
    }
    return res;
}

int main() {
    long long a, n;
    cout << "a = ";
    cin >> a;
    cout << "n = ";
    cin >> n;

    cout << a << "^" << n << " = " << power(a, n) << endl;
    return 0;
}
