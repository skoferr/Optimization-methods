#include <cmath>
#include <iostream>

using namespace std;

int max_iter = 150;

// Функция для вычисления значения целевой функции

double function(double x) {
    return x * exp(-(x * x) / 2);
}

// Производная функции
double derivative(double x) {
    return exp(-(x * x) / 2) - x * x * exp(-(x * x) / 2);
}

// Функция для нахождения минимума методом средней точки
double middle_point(double a, double b, double e) {

    double x;     // Точка середины интервала
    int iter = 0; // Счетчик числа итераций

    // Сужаем интервал до достижения необходимой точности
    while ((b - a) / 2 > e) {
        x = (a + b) / 2; // Вычисление средней точки
        double df_x = derivative(x); // Вычисление производной в средней точке
        iter++;

        if (iter == max_iter) break;

        // Вывод текущих значений
        cout << "Итерация |" << iter << "| a = " << a << " | b = " << b << " | x = " << x << " | f'(x) = " << derivative(x) << endl;

        // Выбор новой границы интервала
        if (df_x < 0) {
            a = x;
        }
        else {
            b = x;
        }
    }
    cout << "\n\nИтераций: " << iter << endl;
    return (a + b) / 2;
}

int main() {
    setlocale(LC_ALL, "RU");
    double a, b; // Интервал поиска минимума (в случае нашей задачи: [-8; 2])
    double e; // Точность (в нашей задаче: 0.06)
    // Ввод границ и точности с клавиатуры
    cout << "Введите левую границу: ";
    cin >> a;
    cout << "Введите правую границу: ";
    cin >> b;
    cout << "Введите точность: ";
    cin >> e;
    double min_x;
    min_x = middle_point(a, b, e);
    cout << "x = " << min_x << " f(x) = " << function(min_x) << endl;
    system("pause");
    system("cls");
    main();
    return 0;
}

