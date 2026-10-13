// Лабораторна робота № 5.2
// Клак Соломія
// Варіант 14
// Перший доданок: a(0) = 1
// Рекурентне співвідношення: a(n) = a(n-1) * R,  R = -x*x / ((2n-1)*2n)

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

void S(const double x, const double eps, int& n, double& s);
void A(const double x, const int n, double& a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = ";  cin >> xp;
    cout << "xk = ";  cin >> xk;
    cout << "dx = ";  cin >> dx;
    cout << "eps = "; cin >> eps;

    // ширини колонок таблиці (однакові для шапки та рядків)
    const int wx = 8, wc = 12, ws = 12, wn = 5;
    const string line = "+" + string(wx + 2, '-')
        + "+" + string(wc + 2, '-')
        + "+" + string(ws + 2, '-')
        + "+" + string(wn + 2, '-') + "+";

    cout << fixed;
    cout << "Taylor series: cos(x)" << endl;       // заголовок таблиці
    cout << line << endl;
    cout << "| " << setw(wx) << "x"                   // шапка таблиці
        << " | " << setw(wc) << "cos(x)"
        << " | " << setw(ws) << "S"
        << " | " << setw(wn) << "n" << " |" << endl;
    cout << line << endl;

    x = xp;
    while (x <= xk)
    {
        S(x, eps, n, s);

        cout << "| " << setw(wx) << setprecision(2) << x
            << " | " << setw(wc) << setprecision(6) << cos(x)
            << " | " << setw(ws) << setprecision(6) << s
            << " | " << setw(wn) << n << " |" << endl;
        x += dx;
    }
    cout << line << endl;

    return 0;
}

// Сума ряду Тейлора: n - кількість доданків, s - сума (посилання)
void S(const double x, const double eps, int& n, double& s)
{
    n = 0;              // номер поточного доданка
    double a = 1;       // перший доданок
    s = a;
    do {
        n++;
        A(x, n, a);     // наступний доданок
        s += a;
    } while (fabs(a) >= eps);
}

// Наступний доданок a за рекурентним співвідношенням (a - посилання)
void A(const double x, const int n, double& a)
{
    double R = -x * x / ((2. * n - 1) * 2 * n);   // коеф. рекурентності
    a *= R;
}
