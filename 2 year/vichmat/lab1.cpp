#include <iostream>
#include <cmath>
using namespace std;

double a, b;

double check() {
    double n;
    cin >> n;
    while (cin.fail() || cin.get() != '\n') {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Error!";
        cin >> n;
    }
    return n;
}

double func(double x)
{
    double f;
    f = pow(a, x) + b * x * sin(x);
    return f;
}

double hordamore0(double x, double end)
{
    double f;
    f = x - func(x) * ((end - x) / (func(end) - func(x)));
    return f;
}

double hordaless0(double x, double start)
{
    double f;
    f = x - func(x) * ((x - start) / (func(x) - func(start)));
    return f;
}

bool check(double end, double start)
{
    if (end <= start || func(end) * func(start) > 0)
        return true;
    else
        return false;
}

double checkfirstdif(double x)
{
    double h = 0.1;
    double f;
    f = (func(x + h) - func(x - h)) / h;
    return f;

}

double checkdoubledif(double x)
{
    double h = 0.1;
    double f;
    f = (func(x + h) - 2 * func(x) + func(x - h)) / h;
    return f;
}

int main()
{
    // a = 2.01
    // b = -1
    // e = 0.00001
    // интервал -3.4 -2.5  и  -6.5 -5.5
    setlocale(0, "");
    double result;
    double start, end;
    double x0, x, e;
    cout << "Введите значение коэффицентов a и b \n";
    a = check();
    b = check();
    cout << "Введите погрешность:  ";
    e = check();
    int sw = 1;
    int iter = 0;

    while (sw == 1)
    {
        cout << "Введите начало и конец интервала!\n";
        start = check();
        end = check();
        if (check(end, start) || checkfirstdif(start) * checkfirstdif(end) <= 0 || checkdoubledif(start) * checkdoubledif(end) < 0)
        {
            cout << "root doesnt exist on this interval!" << endl;
        }

        else
        {
            if (checkfirstdif(end) * checkdoubledif(end) > 0)
            {
                x0 = start;
                result = hordamore0(x0, end);
                while (abs(x0 - result) >= e)
                {
                    x0 = result;
                    result = hordamore0(x0, end);
                    iter++;
                }
            }
            else
            {
                x0 = end;
                result = hordaless0(x0, start);
                while (abs(x0 - result) >= e)
                {
                    x0 = result;
                    result = hordaless0(x0, start);
                    iter++;
                }
            }
        }




        cout << "\n" << "X = " <<  result << "\nКол-во итераций " << iter << endl;

        cout << "\nФункция f(x) = " << func(result) << endl;
        cout << "\nХотите найти еще один корень?\n";
        cout << "Если да, введите 1, если нет, то 0.\n";
        cin >> sw;

    }

    return 0;
}