#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k, l;
    cin >> n >> k >> l;

    int a[100];

    // Считываем стоимости
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Сортируем по убыванию
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] < a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    int sum = 0;
    int count = 0;

    // Выбираем растения
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {

            if (count < k) {
                sum += a[i];
                count++;
            }
        }
    }

    cout << sum;

    return 0;
}