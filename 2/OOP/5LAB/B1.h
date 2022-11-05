#pragma once
#include <iostream>
using namespace std;

class B1
{
protected:
	int member;
public:
	B1(int);
	~B1();
	void show();
};

void B1::show()
{
	cout << "Значение объекта B1: " << member << endl;
}

B1::B1(int value = 321) : member{ value }
{
	cout << "Сработал конструктор B1" << endl;
	show();
}
B1::~B1()
{
	cout << "Деструктор В1" << endl;

}