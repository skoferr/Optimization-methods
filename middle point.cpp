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

// ������� ��� ���������� �������� ������� ������� �����
double middle_point(double a, double b, double e) {

    double x;     // ����� �������� ���������
    int iter = 0; // ������� ����� ��������

    // ������ �������� �� ���������� ����������� ��������
    while ((b - a) / 2 > e) {
        x = (a + b) / 2; // ���������� ������� �����
        double df_x = derivative(x); // ���������� ����������� � ������� �����
        iter++;

        if (iter == max_iter) break;

        // ����� ������� ��������
        cout << "�������� |" << iter << "| a = " << a << " | b = " << b << " | x = " << x << " | f'(x) = " << derivative(x) << endl;

        // ����� ����� ������� ���������
        if (df_x < 0) {
            a = x;
        }
        else {
            b = x;
        }
    }
    cout << "\n\n��������: " << iter << endl;
    return (a + b) / 2;
}

int main() {
    setlocale(LC_ALL, "RU"); // ������������� ������� �����������
    double a, b; // �������� ������ �������� (� ������ ����� ������: [-8; 2])
    double e; // �������� (� ����� ������: 0.06)
    // ���� ������ � �������� � ����������
    cout << "������� ����� �������: ";
    cin >> a;
    cout << "������� ������ �������: ";
    cin >> b;
    cout << "������� ��������: ";
    cin >> e;
    double min_x;
    min_x = middle_point(a, b, e);
    cout << "x = " << min_x << " f(x) = " << function(min_x) << endl;
    system("pause");
    system("cls");
    main();
    return 0;
}
