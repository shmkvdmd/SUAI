#include <iostream>
#include "array.h"
#include "Errors.h"
using namespace std;

//void inputlength(int& length)
//{
//	int tmp;
//	cout << "Введите длину массива: ";
//	cin >> tmp;
//	length = tmp;
//}

void fillarray(Array& arr)
{
	int tmp = 0;
	cout << "Заполните массив" << endl;
	for (int i = 0; i < 12; i++)
	{
		cout << "[" << i << "] = ";
		cin >> tmp;
		arr.setElem(tmp, i);
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	//int length;
	//inputlength(length);
	Array arr = 12;
	int choice = -1;
	bool flag = false;
	fillarray(arr);
	while (choice != 0)
	{

		cout << "Выберите действие: " << endl;
		cout << "1 - Вывести максимальный по модулю элемент массива" << endl;
		cout << "2 - Вывести сумму элементов массива, расположенных до последнего положительного элемента" << endl;
		cout << "3 -  Преобразовать массив" << endl;
		cout << "0 - Закончить выполнение программы" << endl;
		cout << "Ваш выбор: ";

		while (flag == false)
		{

			try
			{

				cin >> choice;
				if ((!std::cin.good() || std::cin.peek() != '\n') || choice < 0 || choice > 3)
				{

					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					throw Errors("неверное значение", 1);

				}
				flag = true;

			}
			catch (Errors& ex)
			{
				cerr << "Error: " << ex.what() << endl;
				ex.getInfo();
				cout << "Выберите действие: " << endl;
				cout << "1 - Вывести максимальный элемент массива" << endl;
				cout << "2 - Вывести сумму элементов массива, расположенных до последнего положительного элемента" << endl;
				cout << "3 - Преобразовать массив" << endl;
				cout << "0 - Закончить выполнение программы" << endl;

				cout << "Ваш выбор: ";

			}

		}
		flag = false;
		if (choice == 1)
		{
			arr.showArr();
			int i = arr.getmax();
			cout << "Максимальный элемент " << i << endl;
		}
		if (choice == 2)
		{
			try
			{
				int count = 0;
				for (int i = 0; i < arr.getLength(); i++)
				{
					if (arr.getElem(i) > 0)
					{

						count++;
					}
				}
				if (count == 0)
				{
					throw Errors("нет положительных элементов", 2);
				}
				int summa = arr.getsum();
				cout << "Сумма элементов массива, расположенных до последнего положительного элемента = " << summa << endl;
			}
			catch (Errors& ex)
			{
				std::cerr << "Error: " << ex.what() << std::endl;
				ex.getInfo();
			}
		}
		if (choice == 3)
		{
			cout << "Исходный массив: " << endl;
			arr.showArr();
			cout << "\nПолученный массив: \n";
			arr.reshapearr(1, 5);
		}
	}

}