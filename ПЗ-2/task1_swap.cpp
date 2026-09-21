#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    // меняем местами без третьей переменной
    a = a + b;
    b = a - b;
    a = a - b;

    cout << "После обмена: a = " << a << ", b = " << b << endl;
    return 0;
}