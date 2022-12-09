#define NOMINMAX

#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include <stdio.h>

#include "Task.h"
#include "Generator.h"
#include "Queue.h"
#include "Distributor.h"
#include "Stack.h"
#include "Processor.h"

int GetRandomNumber(int min, int max)
{

	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	return static_cast<int>(rand() * fraction * (max - min + 1) + min);

}

void CheckInput(int &input_buff, const int &flag)
{

	if (flag == 0)
	{

		while ((!std::cin.good() || std::cin.peek() != '\n') || (input_buff < 1 || input_buff > 2))		//Проверка на то, что int
		{

			std::cerr << "Некорректный ввод данных!!!" << std::endl;
			std::cout << "Вводимое поле должно быть равно 1 или 2!!!" << std::endl;
			std::cout << "Повторите ввод!!!" << std::endl;

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Введите число: ";
			std::cin >> input_buff;
			std::cout << std::endl;

		}

	}

	if (flag == 1)
	{

		while (!std::cin.good() || std::cin.peek() != '\n' || input_buff < 1)		//Проверка на то, что int
		{

			std::cerr << "Некорректный ввод данных!!!" << std::endl;
			std::cout << "Вводимое поле должно быть целым положительным числом!!!" << std::endl;
			std::cout << "Повторите ввод!!!" << std::endl;

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Введите количество задач: ";
			std::cin >> input_buff;
			std::cout << std::endl;

		}

	}

	if (flag == 2)
	{

		while (!std::cin.good() || std::cin.peek() != '\n' || (input_buff < 0 || input_buff > 2))		//Проверка на то, что int
		{

			std::cerr << "Некорректный ввод данных!!!" << std::endl;
			std::cout << "Вводимое поле должно быть равно 0, 1 или 2!!!" << std::endl;
			std::cout << "Повторите ввод!!!" << std::endl;

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Тип задачи(от 0 до 2): ";
			std::cin >> input_buff;
			std::cout << std::endl;

		}

	}

	if (flag == 3)
	{

		while (!std::cin.good() || std::cin.peek() != '\n' || (input_buff < 1 || input_buff > 5))		//Проверка на то, что int
		{

			std::cerr << "Некорректный ввод данных!!!" << std::endl;
			std::cout << "Вводимое поле должно быть целым положительным числом в диапозоне от 1 до 5" << std::endl;
			std::cout << "Повторите ввод!!!" << std::endl;

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Длительность задачи(от 1 до 5): ";
			std::cin >> input_buff;
			std::cout << std::endl;

		}

	}

}

void InputWidth(int &out_width)
{

	std::cout << "Введите количество задач: ";

	std::cin >> out_width;

	CheckInput(out_width, 1);

	std::cout << std::endl;

}

void AutoGenerateTasks(Generator &generator, const int &width)
{

	for (int i = 0; i < width; i++)
	{

		generator.pushBack(GetRandomNumber(0,2), GetRandomNumber(1,5), i);

	}

}

void ManualGenerateTasks(Generator &generator, const int &width)
{

	int priority{};
	int duration{};

	std::cout << std::endl;
	std::cout << "Введите параметры задач: " << std::endl;

	for (int i = 0; i < width; i++)
	{

		std::cout << "Задача " << i << ": " << std::endl;
		std::cout << "Тип задачи(от 0 до 2): ";
		std::cin >> priority;

		CheckInput(priority, 2);

		std::cout << std::endl;
		std::cout << "Длительность задачи(от 1 до 5): ";
		std::cin >> duration;

		CheckInput(duration, 3);

		std::cout << std::endl;
		std::cout << std::endl;

		generator.pushBack(priority, duration, i);

	}

}

void ShowTasks(Generator &ListOfTasks, const int &width)
{

	std::cout << std::endl;
	std::cout << "Исходный список задач: " << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < width; i++)
	{

		std::cout << "Задача " << i << std::endl;
		std::cout << "Тип задачи: " << ListOfTasks(i, 1) << std::endl;
		std::cout << "Длительность задачи: " << ListOfTasks(i, 2) << std::endl;
		std::cout << std::endl;

	}

}

void TickInfo(Generator &generator, Queue &queue, Distributor &distributor, Stack &stack, 
	Processor &processorOne, Processor &processorTwo, Processor &processorThree, const int &timer)
{

	std::cout << std::endl;
	std::cout << "Состояние задач на " << timer << " такт:" << std::endl;
	std::cout << std::endl;

	std::cout << "Состояние генератора: " << std::endl;
	generator.getInfo();
	std::cout << std::endl;

	std::cout << "Состояние очереди: " << std::endl;
	queue.getInfo();
	std::cout << std::endl;

	std::cout << "Состояние распределителя: " << std::endl;
	distributor.getInfo();
	std::cout << std::endl;

	std::cout << "Состояние стэка: " << std::endl;
	stack.getInfo();
	std::cout << std::endl;

	processorOne.getInfo();
	std::cout << std::endl;

	processorTwo.getInfo();
	std::cout << std::endl;

	processorThree.getInfo();
	std::cout << std::endl;

}

void EmulateSystem(Generator &generator)
{

	Queue queue{};
	Stack stack{};
	Processor processorOne{ 0, 0 };
	Processor processorTwo{ 1, 0 };
	Processor processorThree{ 2, 0 };
	Distributor distributor{};

	int timer{};

	TickInfo(generator, queue, distributor, stack, processorOne, processorTwo, processorThree, timer);

	while (true)
	{

		if (!generator.allTasksGone())
		{

			if (queue.isEmpty())
			{

				queue.pushBack(generator.popFront());

			}

		}

		if (queue.isFull())
		{

			distributor = queue.popFront();

		}

		else
		{

			if (queue.isEmpty() && !stack.isEmpty())
			{

				distributor = stack.popBack();

			}

		}

		if (!distributor.isFree())
		{

			if ((distributor.getPriority() == processorOne.getPrio()) && processorOne.isFree())
			{

				processorOne.push(distributor.push());

			}

			else
			{

				if (distributor.getPriority() == processorOne.getPrio())
				{

					stack.pushBack(distributor.push());

				}

			}

			if ((distributor.getPriority() == processorTwo.getPrio()) && processorTwo.isFree())
			{

				processorTwo.push(distributor.push());

			}

			else
			{

				if (distributor.getPriority() == processorTwo.getPrio())
				{

					stack.pushBack(distributor.push());

				}

			}

			if ((distributor.getPriority() == processorThree.getPrio()) && processorThree.isFree())
			{

				processorThree.push(distributor.push());

			}

			else
			{

				if (distributor.getPriority() == processorThree.getPrio())
				{

					stack.pushBack(distributor.push());

				}

			}

		}

		if (!processorOne.isFree())
		{

			processorOne.tick();

		}

		if (!processorTwo.isFree())
		{

			processorTwo.tick();

		}

		if (!processorThree.isFree())
		{

			processorThree.tick();

		}

		timer++;

		TickInfo(generator, queue, distributor, stack, processorOne, processorTwo, processorThree, timer);

		if (generator.allTasksGone() && queue.isEmpty() && stack.isEmpty() && processorOne.isFree()
			&& processorTwo.isFree() && processorThree.isFree() && distributor.isFree())
		{

			std::cout << "Система выполнила все задачи. Завершение работы системы." << std::endl;

			break;

		}

	}

}


void main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));

	Generator generator{};
	
	int choice{0};
	int width{0};

	std::cout << "Выберите режим создания задач: " << std::endl;
	std::cout << "1 - Автоматически" << std::endl;
	std::cout << "2 - Вручную" << std::endl;
	std::cout << "Введите число: ";
	std::cin  >> choice;

	CheckInput(choice, 0);

	std::cout << std::endl;

	if (choice == 1)
	{

		InputWidth(width);
		AutoGenerateTasks(generator, width);
		ShowTasks(generator, width);

	}

	if (choice == 2)
	{

		InputWidth(width);
		ManualGenerateTasks(generator, width);
		ShowTasks(generator, width);

	}

	EmulateSystem(generator);

}