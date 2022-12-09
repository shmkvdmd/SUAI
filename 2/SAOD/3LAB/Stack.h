#pragma once

#include "Task.h"

class Stack
{

private:

	Task *m_head;
	int m_count;

public:

	Stack();
	~Stack();

	void pushBack(Task);
	Task popBack();
	bool isEmpty(){ return m_count == 0; };
	void getInfo();

};



// START OF DESTRUCTORS AND CONSTRUCTORS

Stack::Stack(): m_head{nullptr}, m_count{0}
{}

Stack::~Stack()
{}

// END OF DESTRUCTORS AND CONSTRUCTORS



// START OF METHODS

void Stack::pushBack(Task task)
{

	if (m_head == nullptr)
	{

		m_head = new Task(task.m_taskPriority, task.m_taskDuration, task.m_taskTime);

	}

	else
	{

		Task *current = m_head;

		while (current -> m_ptrNext != nullptr)
		{

			current = current -> m_ptrNext;

		}

		current->m_ptrNext = new Task(task.m_taskPriority, task.m_taskDuration, task.m_taskTime);

	}

	m_count++;

}



Task Stack::popBack()
{

	Task *current = m_head;
	Task *previous = m_head;

	if (current -> m_ptrNext == nullptr)
	{

		Task *res = current;

		m_count--;

		m_head = nullptr;

		return *res;

	}

	while (current -> m_ptrNext != nullptr)
	{
		
		previous = current -> m_ptrNext;
		current = current -> m_ptrNext;

	}

	Task *res = current;

	previous -> m_ptrNext = nullptr;

	m_count--;

	return *res;

}



void Stack::getInfo()
{

	Task *current = this->m_head;

	if (m_count == 0)
	{

		std::cout << "Стэк пуст!" << std::endl;
		std::cout << std::endl;

	}

	else
	{

		std::cout << "Задач в стэке:  " << m_count << std::endl;

		while (current != nullptr)
		{

			std::cout << "Задача " << current->m_taskTime << std::endl;
			std::cout << "Тип задачи: " << current->m_taskPriority << std::endl;
			std::cout << "Длительность задачи: " << current->m_taskDuration << std::endl;
			std::cout << std::endl;

			current = current -> m_ptrNext;

		}

	}

}

// END OF METHODS