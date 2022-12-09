#pragma once

#include "Task.h"

class Distributor
{

private:

	Task m_task;
	int m_count;

public:

	Distributor();
	Distributor(Task);
	~Distributor();

	int getPriority(){ return m_task.m_taskPriority; };
	int getTime(){ return m_task.m_taskTime; };
	Task push(){ m_count--;  return m_task; };
	bool isFree(){ return m_count == 0; };
	void getInfo();

};



// START OF DESTRUCTORS AND CONSTRUCTORS

Distributor::Distributor():m_count{0}
{}



Distributor::Distributor(Task task):m_task{task}, m_count{1}
{}



Distributor::~Distributor()
{}

// END OF DESTRUCTORS AND CONSTRUCTORS



void Distributor::getInfo()
{
	
	if (m_count == 0)
	{

		std::cout << "Распределитель пуст!" << std::endl;
		std::cout << std::endl;

	}

	else
	{

		std::cout << "В распределителе находится задача " << m_task.m_taskTime << std::endl;
		std::cout << "Тип задачи: " << m_task.m_taskPriority << std::endl;
		std::cout << "Длительность задачи: " << m_task.m_taskDuration << std::endl;
		std::cout << std::endl;

	}

}