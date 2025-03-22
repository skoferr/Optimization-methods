#include <iostream>
#include <cmath>

using namespace std;

int max_iter = 150;

// Исходная функция
double function(double x) {
    return x * exp(-(x * x) / 2);
}

// Метод поразрядного поиска минимума
double bitwiseSearch(double a, double b, double e) {
    double step = (b - a) / 4; //Дельта
    double x0 = a;//Начальная / левая граница
    double x_new, f0, f_new;
    int iter = 0;
    f0 = function(x0);
    while (step > e) {

        cout << endl << "Вправо" << endl;

        while (true) { //Цикл двигается вправо
            x_new = x0 + step;

            f_new = function(x_new);

            cout << "Итерация |" << iter << "| " << "| step " << step << " | x = " << x_new << " | f(x) " << f_new << endl;
            iter++;
            if (iter == max_iter) return x0;
            if (f0 > f_new) {
                x0 = x_new;
                f0 = f_new;

                if (x0 < a)
                    x0 = a;
                else if (x0 >= b)
                    x0 = b;

            }
            else {
                break;
            }
        }
        step /= 4; //Уменьшение шага

        x0 = x_new;
        f0 = function(x0);

        cout << endl << "Влево" << endl;

        while (true) //Цикл движется влево
        {
            x_new = x0 - step;
            f_new = function(x_new);

            cout << "Итерация | " << iter << " | " << " | step " << step << " | x = " << x_new << " | f(x) " << f_new << endl;
            iter++;
            if (iter == max_iter) return x0;

            if (f0 > f_new) {
                b = x0;
                x0 = x_new;
                f0 = f_new;

                if (x0 < a)
                    x0 = a;
                else if (x0 > b)
                    x0 = b;
            }
            else {
                break;
            }


        }
    }
    return x0;
    cout << "\n\nИтераций: " << iter << endl;
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
    double min_x;
    min_x = bitwiseSearch(a, b, e);
    cout << "x = " << min_x << " f(x) = " << function(min_x) << endl;
    system("pause");
    system("cls");
    main();
}

