#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Проверяем, можно ли распределить пирожки
bool check(vector<int>& a, int n, int d, int difference) {

    int days = 1;

    // Самый низкокалорийный пирожок текущего дня
    int minimum = a[0];

    for (int i = 1; i < n; i++) {

        // Если разница слишком большая,
        // начинаем новый день
        if (a[i] - minimum > difference) {
            days++;
            minimum = a[i];
        }
    }

    // Проверяем, хватает ли нам дней
    return days <= d;
}

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> a(n);

    // Считываем калорийность пирожков
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Сортируем пирожки по калорийности
    sort(a.begin(), a.end());

    // Границы для бинарного поиска
    int left = 0;
    int right = a[n - 1] - a[0];

    // Ищем минимальную разницу
    while (left < right) {

        int mid = (left + right) / 2;

        if (check(a, n, d, mid)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    cout << left;

    return 0;
}