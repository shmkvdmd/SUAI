#include <iostream>
using namespace std;

#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <climits>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
#include <vector>

#include "Data.h"

int GetRandomNumber(int min, int max)
{

	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	return static_cast<int>(rand() * fraction * (max - min + 1) + min);

}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int choice = -1;

	int len{};
	std::vector<int> buff{};

	cout << "Введите длину вектора: ";
	cin >> len;
	cout << endl;

	for (int i = 0; i < len; i++)
	{

		buff.push_back(GetRandomNumber(-10, 10));

	}

	Data data{ buff };
	data.showData();
	while (choice != 0)
	{
		cout << endl;
		cout << endl;
		cout << endl;

		cout << "Выберите действие: " << endl;
		cout << "1 - Удалить элементы равные 0" << endl;
		cout << "2 - Умножить все элементы на 2" << endl;
		cout << "3 - Заменить элементы, которые больше или равны 10 на значение 0" << endl;
		cout << "0 - Закончить работу" << endl;

		cout << "Введите номер действия: ";
		cin >> choice;

		if (choice == 1)
		{

			cout << "Удалить элементы равные 0 " << endl;
			data.zerodelete();
			data.showData();

		}

		if (choice == 2)
		{

			cout << "Исходный массив: " << endl;
			data.showData();
			cout << endl;
			cout << "Преобразованный массив: " << endl;
			data.calc();
			data.showData();
			cout << endl;

		}

		if (choice == 3)
		{

			cout << "Исходный массив: " << endl;
			data.showData();
			cout << endl;
			data.change();
			cout << endl;

		}

	}

}
