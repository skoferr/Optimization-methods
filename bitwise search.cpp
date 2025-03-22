#include <iostream>
#include <cmath>

using namespace std;

int max_iter = 150;

// �������� �������
double function(double x) {
    return x * exp(-(x * x) / 2);
}

// ����� ������������ ������ ��������
double bitwiseSearch(double a, double b, double e) {
    double step = (b - a) / 4; //������
    double x0 = a;//��������� / ����� �������
    double x_new, f0, f_new;
    int iter = 0;
    f0 = function(x0);
    while (step > e) {

        cout << endl << "������" << endl;

        while (true) { //���� ��������� ������
            x_new = x0 + step;

            f_new = function(x_new);

            cout << "�������� |" << iter << "| " << "| step " << step << " | x = " << x_new << " | f(x) " << f_new << endl;
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
        step /= 4; //���������� ����

        x0 = x_new;
        f0 = function(x0);

        cout << endl << "�����" << endl;

        while (true) //���� �������� �����
        {
            x_new = x0 - step;
            f_new = function(x_new);

            cout << "�������� | " << iter << " | " << " | step " << step << " | x = " << x_new << " | f(x) " << f_new << endl;
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
    cout << "\n\n��������: " << iter << endl;
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
    double min_x;
    min_x = bitwiseSearch(a, b, e);
    cout << "x = " << min_x << " f(x) = " << function(min_x) << endl;
    system("pause");
    system("cls");
    main();
}
