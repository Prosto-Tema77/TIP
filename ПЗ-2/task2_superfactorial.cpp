#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "n = ";
    cin >> n;

    unsigned long long f = 1;    // здесь копится факториал
    unsigned long long res = 1;  // а здесь сам ответ
    // больше n = 8 уже не влезает в unsigned long long

    for (int i = 1; i <= n; i++) {
        f = f * i;
        res = res * f;
    }

    cout << "F(" << n << ") = " << res << endl;
    return 0;
}
