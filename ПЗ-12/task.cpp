#include <iostream>
using namespace std;

int n, m;

char a[100][100];
bool used[100][100];

int ans = -1;

// Функция поиска пути
void dfs(int x, int y, int count) {

    // Проверяем, не вышли ли за границы лабиринта
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;

    // Если стена или уже были в этой клетке
    if (a[x][y] == '1' || used[x][y] == true)
        return;

    // Если нашли PDF, увеличиваем счётчик
    if (a[x][y] == 'P')
        count++;

    // Если нашли выход
    if (a[x][y] == 'E') {
        if (count > ans)
            ans = count;

        return;
    }

    // Отмечаем клетку как посещённую
    used[x][y] = true;

    // Пробуем пойти вверх
    dfs(x - 1, y, count);

    // Пробуем пойти вниз
    dfs(x + 1, y, count);

    // Пробуем пойти влево
    dfs(x, y - 1, count);

    // Пробуем пойти вправо
    dfs(x, y + 1, count);

    // Снимаем отметку о посещении
    used[x][y] = false;
}

int main() {

    cin >> n >> m;

    // Считываем лабиринт
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Начинаем с первой клетки
    dfs(0, 0, 0);

    // Выводим максимальное количество PDF
    cout << ans;

    return 0;
}