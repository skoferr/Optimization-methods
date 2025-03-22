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

// Метод хорд
double chord_method(double a, double b, double e) {
    double x_tilda;
    int iter = 0;
    if (derivative(a) < 0 && derivative(b) < 0) return b;
    if (derivative(a) > 0 && derivative(b) > 0) return a;
    while (fabs(b - a) > e) {
        iter++; // Увеличиваем счётчик итераций
        if (iter == max_iter) break;
        // Проверка на деление на ноль
        if (fabs(derivative(a) - derivative(b)) < 1e-9) {
            cerr << "Ошибка: деление на ноль при вычислении x_tilda" << endl;
            return (a + b) / 2;
        }

        // Вычисляем новую точку по формуле метода хорд
        x_tilda = a - derivative(a) * (a - b) / (derivative(a) - derivative(b));

        cout << "Итерация |" << iter
            << " | a = " << a << " | b = " << b << " | x = " << x_tilda
            << " | f'(x) = " << derivative(x_tilda)
            << " | f(x) = " << function(x_tilda) << endl;

        // Проверяем условие завершения
        if (fabs(derivative(x_tilda)) <= e) {
            cout << "\n\nИтераций: " << iter << endl;
            return x_tilda;
        }

        // Определяем новый интервал поиска
        if (derivative(x_tilda) > 0) {
            b = x_tilda;
        }
        else {
            a = x_tilda;
        }
    }

    cout << "\n\nИтераций: " << iter << endl;


    return (a + b) / 2; // Возвращаем середину оставшегося интервала
}


int main() {
    setlocale(LC_ALL, "RU");
    double a, b; // Интервал поиска минимума (в случае нашей задачи: [-3; 0.5])
    double e; // Точность (в нашей задаче: 0.06)
    // Ввод границ и точности с клавиатуры
    cout << "Введите левую границу: ";
    cin >> a;
    cout << "Введите правую границу: ";
    cin >> b;
    cout << "Введите точность: ";
    cin >> e;
    double min_x;
    min_x = chord_method(a, b, e);
    cout << "x = " << min_x << " f(x) = " << function(min_x) << endl;
    system("pause");
    system("cls");
    main();
}

