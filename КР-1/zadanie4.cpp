// Контрольная работа №1, задание №4, вариант 17
// Ввод: коэффициенты a, b, c многочлена a*x^2 + b*x + c, затем символ:
//   Q - вывести фамилию и имя студента;
//   d - вывести корни многочлена;
//   g - рассчитать стоимость покупки с учётом скидки.

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

// Выводит фамилию и имя студента на английском языке
void printStudentName()
{
    cout << "Proskurin Artem" << endl;
}

// Выводит один корень в виде "имя = значение"
void printRoot(const string& name, double value)
{
    if (value == 0)
        value = 0; // убираем "-0", который может получиться при делении

    cout << name << " = " << value << endl;
}

// Находит и выводит корни многочлена a*x^2 + b*x + c
void printRoots(double a, double b, double c)
{
    // a = 0: многочлен не квадратный, остаётся линейное уравнение b*x + c = 0
    if (a == 0)
    {
        if (b == 0 && c == 0)
            cout << "x is any real number" << endl;
        else if (b == 0)
            cout << "No roots" << endl;
        else
            printRoot("x", -c / b);
        return;
    }

    // a != 0: квадратное уравнение, решаем через дискриминант
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0)
    {
        printRoot("x1", (-b - sqrt(discriminant)) / (2 * a));
        printRoot("x2", (-b + sqrt(discriminant)) / (2 * a));
    }
    else if (discriminant == 0)
    {
        printRoot("x", -b / (2 * a));
    }
    else
    {
        cout << "No real roots" << endl;
    }
}

// Запрашивает стоимость и скидку, выводит стоимость с учётом скидки
void printPriceWithDiscount()
{
    double price, discount;
    cout << "Enter price and discount (%): ";
    cin >> price >> discount;

    double finalPrice = price - price * discount / 100;
    cout << "Price with discount: " << finalPrice << endl;
}

int main()
{
    // Ввод коэффициентов многочлена и символа-команды
    double a, b, c;
    char command;
    cin >> a >> b >> c;
    cin >> command;

    // Выбор действия по введённому символу
    switch (command)
    {
    case 'Q':
        printStudentName();
        break;
    case 'd':
        printRoots(a, b, c);
        break;
    case 'g':
        printPriceWithDiscount();
        break;
    default:
        cout << "Unknown command" << endl;
    }

    return 0;
}
