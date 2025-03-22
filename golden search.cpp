#include <cmath>
#include <iostream>

using namespace std;

int max_iter = 150;

// ������� ��� ���������� �������� ������� �������
double function(double x) {
    return x * exp(-(x * x) / 2);
}

// ����� �������� ������� ��� ������ �������� �������
double goldenSearch(double a, double b, double e) {
    const double phi = (sqrt(5) - 1) / 2;  // ����������� �������� ������� (~0.618)

    double x1 = a + (1 - phi) * (b - a);
    double x2 = a + phi * (b - a);
    double f1 = function(x1);
    double f2 = function(x2);

    int iter = 0; // �������� ������� ��������

    while (fabs(b - a) > e) { // �������� �������� ���������
        iter++;
        if (iter == max_iter) break;
        cout << "�������� |" << iter
            << "| a = " << a << " | b = " << b
            << " | x1 = " << x1 << " | x2 = " << x2
            << " | f(x1) = " << f1 << " | f(x2) = " << f2 << endl;

        if (f1 < f2) {
            b = x2;
            x2 = x1;
            f2 = f1;
            x1 = a + (1 - phi) * (b - a);
            f1 = function(x1);
        }
        else {
            a = x1;
            x1 = x2;
            f1 = f2;
            x2 = a + phi * (b - a);
            f2 = function(x2);
        }
    }
    cout << "\n\n��������: " << iter << endl;
    return (a + b) / 2; // ���������� ������������ �������� ��������
}


int main() {
    setlocale(LC_ALL, "RU"); // ������������� ������� �����������
    double a, b; // �������� ������ �������� (� ������ ����� ������: [-8; 0.5])
    double e; // �������� (� ����� ������: 0.06)
    // ���� ������ � �������� � ����������
    cout << "������� ����� �������: ";
    cin >> a;
    cout << "������� ������ �������: ";
    cin >> b;
    cout << "������� ��������: ";
    cin >> e;
    double min_x;
    min_x = goldenSearch(a, b, e);
    cout << "x = " << min_x << " f(x) = " << function(min_x) << endl;
    system("pause");
    system("cls");
    main();
}
