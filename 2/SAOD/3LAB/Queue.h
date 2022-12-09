#pragma once

#include "Task.h"

class Queue
{

private:

	Task m_queue;
	int m_count;

public:

	Queue();
	~Queue();

	void pushBack(Task *task);
	Task popFront();
	bool isEmpty(){ return m_count == 0; };
	bool isFull(){ return m_count == 1; };
	void getInfo();

};



// START OF DESTRUCTORS AND CONSTRUCTORS

Queue::Queue(): m_queue{}, m_count{0}
{}



Queue::~Queue()
{}

// END OF DESTRUCTORS AND CONSTRUCTORS



// START OF METHODS

void Queue::pushBack(Task *task)
{

	m_queue = Task(task -> m_taskPriority, task -> m_taskDuration, task -> m_taskTime);

	m_count++;

}



Task Queue::popFront()
{

	Task tmp{m_queue};

		m_count--;

		return tmp;

}

void Queue::getInfo()
{

	if (m_count == 0)
	{

		std::cout << "Очередь пуста!" << std::endl;
		std::cout << std::endl;

	}

	else
	{

		std::cout << "Задач в очереди: " << m_count << std::endl;

		std::cout << "Задача " << m_queue.m_taskTime << std::endl;
		std::cout << "Тип задачи: " << m_queue.m_taskPriority << std::endl;
		std::cout << "Длительность задачи: " << m_queue.m_taskDuration << std::endl;
		std::cout << std::endl;


	}

}

// END OF METHODS
