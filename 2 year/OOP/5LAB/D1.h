#pragma once
#include "B1.h"
#include "B2.h"
#include <iostream>
using namespace std;

class D1 : private B1, public B2
{
protected:
	int member;
public:
	D1(int, int, int);
	~D1();
	void show();
};

void D1::show()
{
	cout << "Значение объекта D1: " << member << endl;
}

D1::D1(int ivalue = 50, int valueB1 = -11, int valueB2 = -2) : member{ivalue}, B1{valueB1}, B2{valueB2}
{
	cout << "Сработал конструктор D1" << endl;
	show();
}

D1::~D1()
{
	cout << "Сработал деструктор D1" << endl;
}