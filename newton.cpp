#include <iostream>
#include <cmath>

using namespace std;

// �������� �������
double f(double x) {
    return x * exp(-(x * x) / 2);
}

// ������ ����������� �������
double df(double x) {
    return exp(-(x * x) / 2) - x * x * exp(-(x * x) / 2);
}

// ������ ����������� �������
double d2f(double x) {
    return -x * exp(-(x * x) / 2) - x * exp(-(x * x) / 2) + x * x * x * exp(-(x * x) / 2);
}

// ����� ������� ��� �����������
double newtonOptimization(double x0, double eps1, double eps2, int maxIter) {
    double x = x0;
    double xPrev;
    int iter = 0;

    do {
        xPrev = x;
        double dfx = df(xPrev);
        double d2fx = d2f(xPrev);

        // ��������, ����� �������� ������� �� ����
        if (fabs(d2fx) < 1e-10) {
            cout << "������ ����������� ������ � ����. ����� ����� �� ���������." << endl;
            break;
        }

        x = xPrev - dfx / d2fx; // ������� ������� ��� �����������
        iter++;

        // ����� ������� ��������
        cout << "�������� | " << iter
            << " | x = " << x
            << " | f(x) = " << f(x)
            << " | f'(x) = " << df(x)
            << " | f''(x) = " << d2f(x) << endl;

        // �������� ��������� ��������
        if (iter >= maxIter) {
            cout << "���������� ������������ ���������� ��������." << endl;
            break;
        }
    } while (fabs(df(x)) > eps1 && fabs(x - xPrev) > eps2);

    cout << "\n\n��������: " << iter << endl;
    return x;
}

int main() {
    setlocale(LC_ALL, "RUS");
    double x0;
    double eps1;
    double eps2 = 0.06; // �������� �� ��������� ���������
    int maxIter = 150; // ������������ ���������� ��������

    cout << "������� ��������� �����������: "; // -1.05 ��������� �����������
    cin >> x0;
    cout << "������� ��������: "; // = 0.06 �������� �� ���������
    cin >> eps1;

    double extremum = newtonOptimization(x0, eps1, eps2, maxIter);
    cout << "x = " << extremum << " f(x) = " << f(extremum) << endl;

    return 0;
}
