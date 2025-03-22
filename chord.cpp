#include <cmath>
#include <iostream>

using namespace std;

int max_iter = 150;

// ������� ��� ���������� �������� ������� �������
double function(double x) {
    return x * exp(-(x * x) / 2);
}

// ����������� �������
double derivative(double x) {
    return exp(-(x * x) / 2) - x * x * exp(-(x * x) / 2);
}

// ����� ����
double chord_method(double a, double b, double e) {
    double x_tilda;
    int iter = 0;
    if (derivative(a) < 0 && derivative(b) < 0) return b;
    if (derivative(a) > 0 && derivative(b) > 0) return a;
    while (fabs(b - a) > e) {
        iter++; // ����������� ������� ��������
        if (iter == max_iter) break;
        // �������� �� ������� �� ����
        if (fabs(derivative(a) - derivative(b)) < 1e-9) {
            cerr << "������: ������� �� ���� ��� ���������� x_tilda" << endl;
            return (a + b) / 2;
        }

        // ��������� ����� ����� �� ������� ������ ����
        x_tilda = a - derivative(a) * (a - b) / (derivative(a) - derivative(b));

        cout << "�������� |" << iter
            << " | a = " << a << " | b = " << b << " | x = " << x_tilda
            << " | f'(x) = " << derivative(x_tilda)
            << " | f(x) = " << function(x_tilda) << endl;

        // ��������� ������� ����������
        if (fabs(derivative(x_tilda)) <= e) {
            cout << "\n\n��������: " << iter << endl;
            return x_tilda;
        }

        // ���������� ����� �������� ������
        if (derivative(x_tilda) > 0) {
            b = x_tilda;
        }
        else {
            a = x_tilda;
        }
    }

    cout << "\n\n��������: " << iter << endl;


    return (a + b) / 2; // ���������� �������� ����������� ���������
}


int main() {
    setlocale(LC_ALL, "RU"); // ������������� ������� �����������
    double a, b; // �������� ������ �������� (� ������ ����� ������: [-3; 0.5])
    double e; // �������� (� ����� ������: 0.06)
    // ���� ������ � �������� � ����������
    cout << "������� ����� �������: ";
    cin >> a;
    cout << "������� ������ �������: ";
    cin >> b;
    cout << "������� ��������: ";
    cin >> e;
    double min_x;
    min_x = chord_method(a, b, e);
    cout << "x = " << min_x << " f(x) = " << function(min_x) << endl;
    system("pause");
    system("cls");
    main();
}
