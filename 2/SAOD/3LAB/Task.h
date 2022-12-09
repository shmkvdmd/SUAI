#pragma once

class Task
{

private:

public:

	int m_taskPriority;
	int m_taskDuration;
	int m_taskTime;
	Task *m_ptrNext;

	Task(int, int, int, Task *);
	Task(const Task &);
	~Task();

};



// START OF DESTRUCTORS AND CONSTRUCTORS

Task::Task(int taskPriority = 0, int taskDuration = 1, int taskTime = 1, Task *ptrNext = nullptr)
	: m_taskPriority{ taskPriority }, m_taskDuration{ taskDuration },
	m_taskTime{ taskTime }, m_ptrNext{ ptrNext }
{}



Task::Task(const Task &task):m_taskPriority{task.m_taskPriority}, m_taskDuration{task.m_taskDuration},
	m_taskTime{task.m_taskTime}, m_ptrNext{nullptr}
{}



Task::~Task()
{}

// END OF DESTRUCTORS AND CONSTRUCTORS