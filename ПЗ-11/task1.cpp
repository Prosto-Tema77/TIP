#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    // Считываем таблицу с баллами
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Массив для хранения максимальных сумм
    vector<vector<long long>> dp(n, vector<long long>(m));

    // Запоминаем, откуда пришли в каждую клетку
    vector<vector<char>> prev(n, vector<char>(m));

    // Стартовая клетка
    dp[0][0] = a[0][0];

    // Заполняем таблицу
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (i == 0 && j == 0)
                continue;

            // Если находимся в первой строке
            if (i == 0) {
                dp[i][j] = dp[i][j - 1] + a[i][j];
                prev[i][j] = 'L';
            }

            // Если находимся в первом столбце
            else if (j == 0) {
                dp[i][j] = dp[i - 1][j] + a[i][j];
                prev[i][j] = 'U';
            }

            // Если можно прийти и сверху, и слева
            else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j] + a[i][j];
                    prev[i][j] = 'U';
                }
                else {
                    dp[i][j] = dp[i][j - 1] + a[i][j];
                    prev[i][j] = 'L';
                }
            }
        }
    }

    // Восстанавливаем маршрут
    vector<pair<int, int>> path;

    int x = n - 1;
    int y = m - 1;

    while (true) {
        path.push_back({x, y});

        if (x == 0 && y == 0)
            break;

        if (prev[x][y] == 'U')
            x--;
        else
            y--;
    }

    // Разворачиваем маршрут
    reverse(path.begin(), path.end());

    // Выводим координаты клеток
    for (int i = 0; i < path.size(); i++) {
        cout << path[i].first << " " << path[i].second << endl;
    }

    return 0;
}