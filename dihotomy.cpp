#include <cmath>
#include <iostream>

using namespace std;

int max_iter = 150;

// ������� ��� ���������� �������� ������� �������
double function(double x) {
    return x * exp(-(x * x) / 2);
}



// ����� ��������� ��� ������ �������� �������
void dichotomy(float a, float b, float e) {
    int iter = 0; // ������� ����� ��������

    while (true) {
        iter++;
        if (iter == max_iter) {
            cout << "\n\n��������: " << iter << "\nx = " << (a + b) / 2 << " f(x) = " << function((a + b) / 2) << endl;
            break;
        }
        float en = (b - a) / 2; // �������� �������� �������
        if (en <= e) { // �������� ���������� ���������
            cout << "\n\n��������: " << iter << "\nx = " << (a + b) / 2 << " f(x) = " << function((a + b) / 2) << endl;
            break;
        }

        float x1 = (a + b - e) / 2;
        float x2 = (a + b + e) / 2;

        // ����� �������� ��������� ��������� � ����������� �����
        cout << "�������� |" << iter << "| a = " << a << " | b = " << b << " | x1 = " << x1
            << " | x2 = " << x2 << " | f(x1) = " << function(x1) << " | f(x2) = " << function(x2) << endl;

        // ��������� ������ ���������
        if (function(x1) <= function(x2)) {
            b = x2; // ������ �������� � [a, x2]
        }
        else {
            a = x1; // ������ �������� � [x1, b]
        }
    }
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
    cout << endl;
    dichotomy(a, b, e);
    system("pause");
    system("cls");
    main();
}
