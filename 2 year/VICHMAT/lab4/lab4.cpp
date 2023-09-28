#include <iostream>
#include <math.h>
using namespace std;

double f(double x)
{
	return tan(pow(x, 2) + 0.1) / (2 + pow(x, 2));
}

double res(double a, double b, double n)
{
	double h = (b - a) / n;
	double s = 0;
	double x = a + h;
	for (int i = 0; i < n; i++)
	{
		s += f(x);
		x += h;
	}
	return s * h;
}

int main()
{
	setlocale(0, "");
	double a, b, n, h;
	cout << "Введите интервалы интегрирования: \n";
	cin >> a >> b;
	cout << "Введите количесвто интервалов разбиения: ";
	cin >> n;
	cout << "Значение интеграла: " << res(a, b, n);
	return 0;
}