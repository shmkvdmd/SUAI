#pragma once

#include <iostream>

#include "Task.h"

class Generator
{

private:

	int m_count;
	Task *m_head;


public:

	Generator();
	~Generator();

	int &operator()(const int index, const int flag);

	void pushBack(int taskPriority, int taskDuration, int taskTime);
	Task *popFront();
	bool allTasksGone(){ return m_count == 0; };
	void getInfo();

};



// START OF CONSTRUCTORS AND DESTRUCTORS

Generator::Generator(): m_count{0}, m_head{nullptr}
{}



Generator::~Generator()
{}

// END OF CONSTRUCTORS AND DESTRUCTORS



// START OF METHODS FOR GENERATOR

void Generator::pushBack(int taskPriority, int taskDuration, int taskTime)
{

	if (m_head == nullptr)
	{

		m_head = new Task(taskPriority, taskDuration, taskTime);

	}

	else
	{

		Task *current = m_head;

		while (current -> m_ptrNext != nullptr)
		{

			current = current -> m_ptrNext;

		}

		current -> m_ptrNext = new Task(taskPriority, taskDuration, taskTime);

	}

	m_count++;

}



Task *Generator::popFront()
{

	Task *tmp = m_head;

	m_head = m_head -> m_ptrNext;

	m_count--;

	tmp -> m_ptrNext = nullptr;

	return tmp;

}



void Generator::getInfo()
{

	Task *current = this -> m_head;

	if (m_count == 0)
	{

		std::cout << "Генератор задач пуст!" << std::endl;
		std::cout << std::endl;

	}

	else
	{

		std::cout << "В генераторе задач находится " << m_count << " задач." << std::endl;
		std::cout << std::endl;

		while (current != nullptr)
		{

			std::cout << "Задача " << current -> m_taskTime << std::endl;
			std::cout << "Тип задачи: " << current -> m_taskPriority << std::endl;
			std::cout << "Длительность задачи: " << current -> m_taskDuration << std::endl;
			std::cout << std::endl;

			current = current -> m_ptrNext;

		}

	}
	

}

// END OF METHODS FOR GENERATOR



// START OF OVERLOADS

int &Generator::operator()(const int index, const int flag)
{

	Task *current = this->m_head;

	int counter{ 0 };

	while (current != nullptr)
	{

		if (counter == index && flag == 0)
		{

			return current -> m_taskTime;

		}

		if (counter == index && flag == 1)
		{

			return current -> m_taskPriority;

		}

		if (counter == index && flag == 2)
		{

			return current -> m_taskDuration;

		}

		current = current->m_ptrNext;
		counter++;

	}

}

// END OF OVERLOADS