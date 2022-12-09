#pragma once

#include "Task.h"

class Processor
{

private:

	Task m_task;
	int m_priority;
	int m_count;

public:

	Processor(int, int);
	~Processor();

	void push(Task task);
	void push(Task *task);
	void tick();
	int getPrio(){ return m_priority; };
	int getTime(){ return m_task.m_taskTime; };
	bool isFree(){ return m_count == 0; };
	void getInfo();
	
};



// START OF DESTRUCTORS AND CONSTRUCTORS

Processor::Processor(int priority = 0, int count = 0)
	: m_priority{priority}, m_count{count}
{}



Processor::~Processor()
{}

// END OF DESTRUCTORS AND CONSTRUCTORS


// START OF METHODS

void Processor::push(Task task)
{

	m_task.m_taskDuration = task.m_taskDuration;
	m_task.m_taskPriority = task.m_taskPriority;
	m_task.m_taskTime = task.m_taskTime;
	
	m_count++;

}



void Processor::push(Task *task)
{

	m_task.m_taskDuration = task -> m_taskDuration;
	m_task.m_taskPriority = task -> m_taskPriority;
	m_task.m_taskTime = task -> m_taskTime;

	m_count++;

}



void Processor::tick()
{

	m_task.m_taskDuration--;

	if (m_task.m_taskDuration == 0)
	{

		std::cout << "Задача " << m_task.m_taskTime << " выполнена!" << std::endl;
		std::cout << std::endl;

		m_count--;

	}

}



void Processor::getInfo()
{

	std::cout << "Состояние процессора " << m_priority << ":" << std::endl;

	if (m_count == 0)
	{

		std::cout << "Процессор свободен!" << std::endl;
		std::cout << std::endl;

	}

	else
	{

		std::cout << "В процессоре находится задача " << m_task.m_taskTime << std::endl;
		std::cout << "Тип задачи: " << m_task.m_taskPriority << std::endl;
		std::cout << "Оставшееся время выполнения: " << m_task.m_taskDuration << std::endl;
		std::cout << std::endl;

	}

}

// END OF METHODS