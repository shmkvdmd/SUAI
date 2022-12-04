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

void main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));

	int choice = -1;

	int len{};
	std::vector<int> buff{};

	std::cout << "Введите длину вектора: ";
	std::cin >> len;
	std::cout << std::endl;

	for (int i = 0; i < len; i++)
	{

		buff.push_back(GetRandomNumber(-10, 10));

	}

	Data data{ buff };

	while (choice != 0)
	{
		std::cout << std::endl;
		data.showData();
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "Выберите действие: " << std::endl;
		std::cout << "1 - Получить сумму всех элементов вектора" << std::endl;
		std::cout << "2 - Для каждого элемента вычислить 2x + 5" << std::endl;
		std::cout << "3 - Заменить элементы, которые больше или равны 20 на значение 10" << std::endl;
		std::cout << "0 - Закончить работу" << std::endl;

		std::cout << "Введите номер действия: ";
		std::cin >> choice;

		if (choice == 1)
		{

			std::cout << "Сумма всех элементов вектора равна " << data.getSum() << std::endl;

		}

		if (choice == 2)
		{

			std::cout << "Исходный массив: " << std::endl;
			data.showData();
			std::cout << std::endl;
			std::cout << "Преобразованный массив: " << std::endl;
			data.calc();
			std::cout << std::endl;

		}

		if (choice == 3)
		{

			std::cout << "Исходный массив: " << std::endl;
			data.showData();
			std::cout << std::endl;
			data.change();
			std::cout << std::endl;

		}

	}

}
