#pragma once
#include <iostream>
using namespace std;

class B2
{
protected:
	int member;
public:
	B2(int);
	~B2();
	void show();
};

void B2::show()
{
	cout << "Значение объекта B2: " << member << endl;
}

B2::B2(int value = 132) : member{value}
{
	cout << "Сработал конструктор B2" << endl;
	show();
}
B2::~B2()
{
	cout << "Деструктор В2" << endl;

}