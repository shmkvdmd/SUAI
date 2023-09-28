#include <iostream>
#include "B1.h"
#include "B2.h"
#include "D1.h"
#include "D2.h"
#include "D3.h"
using namespace std;
//2var

void WorkWithB1()
{
	int value;

	cout << "Создание объекта класса B1" << endl;
	cout << "Введите целое число для объекта: ";
	cin >> value;
	B1 objB1{ value };
}

void WorkWithB2()
{
	int value;

	cout << "Создание объекта класса B2" << endl;
	cout << "Введите целое число для объекта: ";
	cin >> value;
	B2 objB2{ value };
}
void WorkWithD1()
{

	int iValue;
	int valueB1;
	int valueB2;

	cout << "Создание объекта класса D1" << endl;
	cout << "Введите целое число для поля объекта: ";
	cin >> iValue;
	cout << endl;

	cout << "Введите целое число для B1: ";
	cin >> valueB1;
	cout << endl;
	cout << "Введите целое число для B2: ";
	cin >> valueB2;
	cout << endl;

	cout << "Иерархия классов: " << endl;

	D1 objD1{ iValue, valueB1, valueB2 };
}

void WorkWithD2()
{

	int iValue;
	int valueB1;
	int valueB2;
	int valueD1;

	cout << "Создание объекта класса D2" << endl;
	cout << "Введите целое число для поля объекта: ";
	cin >> iValue;

	cout << endl;
	cout << "Введите целое число для D1: ";
	cin >> valueD1;
	cout << endl;

	cout << "Введите целое число для B1: ";
	cin >> valueB1;
	cout << endl;

	cout << "Введите целое число для B2: ";
	cin >> valueB2;
	cout << endl;

	cout << "Иерархия классов: " << endl;

	D2 objD2{ iValue, valueD1, valueB1, valueB2 };

}
void WorkWithD3()
{

	int iValue;
	int valueB1;
	int valueB2;
	int valueD1;

	cout << "Создание объекта класса D3" << endl;
	cout << "Введите целое число для поля объекта: ";
	cin >> iValue;

	cout << endl;
	cout << "Введите целое число для D1: ";
	cin >> valueD1;
	cout << endl;

	cout << "Введите целое число для B1: ";
	cin >> valueB1;
	cout << endl;

	cout << "Введите целое число для B2: ";
	cin >> valueB2;
	cout << endl;

	cout << "Иерархия классов: " << endl;

	D3 objD3{ iValue, valueD1, valueB1, valueB2 };

}
int main()
{
	setlocale(LC_ALL, "RU");
	int choice = -1;
	while (choice != 0)
	{

		cout << "Выберите действие: " << endl;
		cout << "0 - Выйти из программы;" << endl;
		cout << "1 - Создать объект класса В1;" << endl;
		cout << "2 - Создать объект класса B2;" << endl;
		cout << "3 - Создать объект класса D1;" << endl;
		cout << "4 - Создать объект класса D2;" << endl;
		cout << "5 - Создать объект класса D3." << endl;
		cout << "Введите номер действия: ";
		cin >> choice;
		cout << endl;

		if (choice == 1)
		{
			WorkWithB1();
		}
		if (choice == 2)
		{
			WorkWithB2();
		}
		if (choice == 3)
		{
			WorkWithD1();
		}
		if (choice == 4)
		{
			WorkWithD2();
		}
		if (choice == 5)
		{
			WorkWithD3();
		}
	}
	return 0;
}