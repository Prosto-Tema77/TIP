#include <iostream>
using namespace std;

// Переносит n ингредиентов с салфетки from_napkin на салфетку to_napkin.
// free_napkin — оставшаяся свободная салфетка.
// Ингредиент n — самый большой из этих n, он лежит снизу.
void move(int n, int from_napkin, int to_napkin, int free_napkin) {
    // переносить нечего
    if (n == 0) {
        return;
    }

    // n-й лежит снизу, сразу его не взять.
    // Сначала переносим все, что лежит на нём, на свободную салфетку
    move(n - 1, from_napkin, free_napkin, to_napkin);

    // теперь n-й сверху — кладём его на нужную салфетку
    cout << "Ingredient " << n << " move from " << from_napkin << " to " << to_napkin << endl;

    // и переносим всё, что убирали, со свободной салфетки сверху на n-й
    move(n - 1, free_napkin, to_napkin, from_napkin);
}

int main() {
    int n;
    cin >> n;

    // с салфетки 1 на салфетку 3, свободная — 2
    move(n, 1, 3, 2);
    return 0;
}
