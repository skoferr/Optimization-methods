#include <iostream>
#include <cmath>

using namespace std;

// Исходная функция
double f(double x) {
    return x * exp(-(x * x) / 2);
}

// Первая производная функции
double df(double x) {
    return exp(-(x * x) / 2) - x * x * exp(-(x * x) / 2);
}

// Вторая производная функции
double d2f(double x) {
    return -x * exp(-(x * x) / 2) - x * exp(-(x * x) / 2) + x * x * x * exp(-(x * x) / 2);
}

// Метод Ньютона для оптимизации
double newtonOptimization(double x0, double eps1, double eps2, int maxIter) {
    double x = x0;
    double xPrev;
    int iter = 0;

    do {
        xPrev = x;
        double dfx = df(xPrev);
        double d2fx = d2f(xPrev);

        // Проверка, чтобы избежать деления на ноль
        if (fabs(d2fx) < 1e-10) {
            cout << "Вторая производная близка к нулю. Метод может не сходиться." << endl;
            break;
        }

        x = xPrev - dfx / d2fx; // Формула Ньютона для оптимизации
        iter++;

        // Вывод текущей итерации
        cout << "Итерация | " << iter
            << " | x = " << x
            << " | f(x) = " << f(x)
            << " | f'(x) = " << df(x)
            << " | f''(x) = " << d2f(x) << endl;

        // Проверка критериев останова
        if (iter >= maxIter) {
            cout << "Достигнуто максимальное количество итераций." << endl;
            break;
        }
    } while (fabs(df(x)) > eps1 && fabs(x - xPrev) > eps2);

    cout << "\n\nИтераций: " << iter << endl;
    return x;
}

int main() {
    setlocale(LC_ALL, "RUS");
    double x0;
    double eps1;
    double eps2 = 0.06; // Точность по изменению аргумента
    int maxIter = 150; // Максимальное количество итераций

    cout << "Введите начальное приближение: "; // -1.05 Начальное приближение
    cin >> x0;
    cout << "Введите точность: "; // = 0.06 Точность по градиенту
    cin >> eps1;

    double extremum = newtonOptimization(x0, eps1, eps2, maxIter);
    cout << "x = " << extremum << " f(x) = " << f(extremum) << endl;

    return 0;
}
