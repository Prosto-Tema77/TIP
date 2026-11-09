#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // Считываем количество строк и столбцов

    // Создаём таблицу из n строк и m столбцов
    vector<vector<long long>> a(n, vector<long long>(m));

    // Считываем баллы в каждой клетке
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // dp[i][j] — максимальная сумма баллов на пути до клетки (i, j)
    vector<vector<long long>> dp(n, vector<long long>(m));

    // from[i][j] запоминает, откуда мы пришли:
    // 'U' — сверху, 'L' — слева
    vector<vector<char>> from(n, vector<char>(m));

    // В начальной клетке сумма равна её собственным баллам
    dp[0][0] = a[0][0];

    // Проходим по всем клеткам таблицы слева направо и сверху вниз
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Начальную клетку мы уже обработали
            if (i == 0 && j == 0) {
                continue;
            }

            if (i == 0) {
                // В клетки первой строки можно попасть только слева
                dp[i][j] = dp[i][j - 1] + a[i][j];
                from[i][j] = 'L';
            } else if (j == 0) {
                // В клетки первого столбца можно попасть только сверху
                dp[i][j] = dp[i - 1][j] + a[i][j];
                from[i][j] = 'U';
            } else {
                // Для остальных клеток сравниваем путь сверху и путь слева
                if (dp[i - 1][j] >= dp[i][j - 1]) {
                    // Путь сверху даёт большую или такую же сумму
                    dp[i][j] = dp[i - 1][j] + a[i][j];
                    from[i][j] = 'U';
                } else {
                    // Путь слева даёт большую сумму
                    dp[i][j] = dp[i][j - 1] + a[i][j];
                    from[i][j] = 'L';
                }
            }
        }
    }

    // Начинаем восстанавливать маршрут с правой нижней клетки
    vector<pair<int, int>> path;
    int i = n - 1;
    int j = m - 1;

for (int k = 0; k < n + m - 2; k++) {
    path.push_back({i, j});

    if (from[i][j] == 'U') {
        i--;
    } else {
        j--;
    }
}

path.push_back({0, 0});

    // Сейчас маршрут записан от финиша к старту, поэтому переворачиваем его
    reverse(path.begin(), path.end());

    // Выводим координаты клеток в порядке от старта к финишу
    for (int k = 0; k < path.size(); k++) {
        cout << path[k].first << ' ' << path[k].second << '\n';
    }

    return 0;
}
