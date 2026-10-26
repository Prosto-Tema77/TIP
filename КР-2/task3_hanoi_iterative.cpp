#include <iostream>
#include <vector>
using namespace std;

// Салфетки 1, 2, 3 (элемент 0 не используем, чтобы номера совпадали).
// Каждая салфетка — список ингредиентов снизу вверх:
// napkin[1] = {3, 2, 1} значит: снизу 3, сверху 1.
vector<int> napkin[4];

// Перекладывает верхний ингредиент с одной салфетки на другую и печатает ход
void shift(int from_napkin, int to_napkin) {
    int ingredient = napkin[from_napkin].back();  // верхний ингредиент
    napkin[from_napkin].pop_back();               // убираем его отсюда
    napkin[to_napkin].push_back(ingredient);      // кладём сверху туда
    cout << "Ingredient " << ingredient << " move from " << from_napkin << " to " << to_napkin << endl;
}

int main() {
    int n;
    cin >> n;

    // в начале все ингредиенты на салфетке 1: снизу n, сверху 1
    for (int i = n; i >= 1; i--) {
        napkin[1].push_back(i);
    }

    // Правило перекладывания:
    // - нечётный ход (1-й, 3-й, 5-й ...) — двигаем самый маленький ингредиент
    //   на следующую салфетку по кругу;
    // - чётный ход — самый маленький не трогаем. Остаются две другие салфетки,
    //   и между ними можно сделать только один ход: меньший верхний ингредиент
    //   кладём на другую салфетку.
    // Направление круга зависит от n:
    //   n чётное:   1 -> 2 -> 3 -> 1 ...
    //   n нечётное: 1 -> 3 -> 2 -> 1 ...
    int smallest = 1;   // на какой салфетке сейчас лежит самый маленький
    int move_number = 1;

    // работаем, пока все ингредиенты не окажутся на салфетке 3
    while ((int)napkin[3].size() < n) {
        if (move_number % 2 == 1) {
            // ход самым маленьким: по кругу на следующую салфетку
            int next;
            if (n % 2 == 0) {
                next = smallest % 3 + 1;        // 1->2, 2->3, 3->1
            } else {
                next = (smallest + 1) % 3 + 1;  // 1->3, 3->2, 2->1
            }
            shift(smallest, next);
            smallest = next;
        } else {
            // две салфетки, на которых нет самого маленького
            int a = smallest % 3 + 1;
            int b = a % 3 + 1;
            // меньший верхний — на другую салфетку (на пустую можно класть всегда)
            if (napkin[a].empty()) {
                shift(b, a);
            } else if (napkin[b].empty()) {
                shift(a, b);
            } else if (napkin[a].back() < napkin[b].back()) {
                shift(a, b);
            } else {
                shift(b, a);
            }
        }
        move_number++;
    }
    return 0;
}
