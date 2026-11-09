
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Сортируем калорийность
    sort(a.begin(), a.end());

    // Бинарный поиск минимальной разницы
    long long left = 0;
    long long right = a[n - 1] - a[0];

    while (left < right) {
        long long mid = left + (right - left) / 2;

        int days = 1;
        int start = 0;

        // Проверяем, можно ли распределить пирожки
        for (int i = 1; i < n; i++) {
            if (a[i] - a[start] > mid) {
                days++;
                start = i;
            }
        }

        if (days <= d) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left;

    return 0;
}
