// Контрольная работа №1, задание №3, вариант 17
// Исходное выражение:  8(6x - 7) - 17x
// Упрощение:           8*6x - 8*7 - 17x = 48x - 56 - 17x = 31x - 56
// В программе используется уже упрощённая формула: 31x - 56

#include <iostream>

// Вычисляет значение упрощённого выражения 31x - 56
double calculateExpression(double x)
{
    return 31.0 * x - 56.0;
}

int main()
{
    // Ввод значения переменной x с клавиатуры
    double x = 0.0;
    std::cout << "Enter x: ";

    // Проверка корректности ввода (например, если ввели буквы вместо числа)
    if (!(std::cin >> x))
    {
        std::cout << "Error: x must be a number." << std::endl;
        return 1;
    }

    // Вычисление и вывод результата
    double result = calculateExpression(x);
    std::cout << "8(6x - 7) - 17x = 31x - 56 = " << result << std::endl;

    return 0;
}
