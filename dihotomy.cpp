#include <cmath>
#include <iostream>

using namespace std;

int max_iter = 150;

// Функция для вычисления значения целевой функции
double function(double x) {
    return x * exp(-(x * x) / 2);
}



// Метод дихотомии для поиска минимума функции
void dichotomy(float a, float b, float e) {
    int iter = 0; // Счетчик числа итераций

    while (true) {
        iter++;
        if (iter == max_iter) {
            cout << "\n\nИтераций: " << iter << "\nx = " << (a + b) / 2 << " f(x) = " << function((a + b) / 2) << endl;
            break;
        }
        float en = (b - a) / 2; // Половина текущего отрезка
        if (en <= e) { // Критерий завершения алгоритма
            cout << "\n\nИтераций: " << iter << "\nx = " << (a + b) / 2 << " f(x) = " << function((a + b) / 2) << endl;
            break;
        }

        float x1 = (a + b - e) / 2;
        float x2 = (a + b + e) / 2;

        // Вывод текущего состояния интервала и вычисленных точек
        cout << "Итерация |" << iter << "| a = " << a << " | b = " << b << " | x1 = " << x1
            << " | x2 = " << x2 << " | f(x1) = " << function(x1) << " | f(x2) = " << function(x2) << endl;

        // Уточнение границ интервала
        if (function(x1) <= function(x2)) {
            b = x2; // Сужаем интервал к [a, x2]
        }
        else {
            a = x1; // Сужаем интервал к [x1, b]
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU"); // Устанавливаем русскую локализацию
    double a, b; // Интервал поиска минимума (в случае нашей задачи: [-8; 0.5])
    double e; // Точность (в нашей задаче: 0.06)
    // Ввод границ и точности с клавиатуры
    cout << "Введите левую границу: ";
    cin >> a;
    cout << "Введите правую границу: ";
    cin >> b;
    cout << "Введите точность: ";
    cin >> e;
    cout << endl;
    dichotomy(a, b, e);
    system("pause");
    system("cls");
    main();
}

