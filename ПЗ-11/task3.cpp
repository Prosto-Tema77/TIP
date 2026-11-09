#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k, l;

    cin >> n >> k >> l;

    vector<int> a(n);

    // Считываем стоимости растений
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Сортируем от дорогих к дешёвым
    sort(a.begin(), a.end(), greater<int>());

    int sum = 0;
    int count = 0;

    // Перебираем все виды растений
    for (int i = 0; i < n; i++) {

        // Берём не больше L растений одного вида
        for (int j = 0; j < l; j++) {

            // Если уже набрали K растений
            if (count == k)
                break;

            sum += a[i];
            count++;
        }

        // Если букет уже готов
        if (count == k)
            break;
    }

    cout << sum;

    return 0;
}