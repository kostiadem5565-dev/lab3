#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

int main()
{
    // Настройка вывода русского языка в консоли
    setlocale(LC_ALL, "ru_RU.UTF-8");

    double x_start = 0.1;
    double x_end = 0.8;
    
    // Вычисляем точный шаг, чтобы за 10 шагов дойти от 0.1 до 0.8
    // dx = (0.8 - 0.1) / 9 = 0.0777778
    double dx = (x_end - x_start) / 9.0; 

    double x = x_start;

    // Цикл for выполняется ровно 10 раз
    for (int i = 1; i <= 10; i++)
    {
        // Вычисление точной функции y
        double y = x * atan(x) - log(sqrt(1.0 + x * x));

        // Вычисление суммы ряда
        double sumS = 0.0;
        for (int n = 1; n <= 10; n++)
        {
            double chislitel = pow(x, 2 * n);
            double znamenatel = 2 * n * (2 * n - 1);
            double chlen_ryada = chislitel / znamenatel;

            if (n % 2 == 0) {
                sumS -= chlen_ryada;
            } else {
                sumS += chlen_ryada;
            }
        }

        // Вывод результатов для текущего x
        cout << "Шаг " << i << " | x = " << x << " | y = " << y << " | S = " << sumS << endl;

        // Прибавляем шаг к x для следующей итерации
        x += dx;
    }
    return 0;
}
