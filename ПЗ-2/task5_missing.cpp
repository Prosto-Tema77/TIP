#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "n = ";
    cin >> n;

    int a[100];
    long long sum = 0;

    cout << "Введите " << n << " чисел:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum = sum + a[i];   // сумму считаю сразу при вводе
    }

    // если бы ничего не пропало, сумма была бы 0 + 1 + ... + n
    long long full = (long long)n * (n + 1) / 2;

    cout << "Пропущено число " << full - sum << endl;
    return 0;
}
