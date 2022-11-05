#pragma once
#include "D1.h"
#include <iostream>
using namespace std;

class D2 : virtual public D1
{
protected:
	int member;
public:
	D2(int, int, int, int);
	~D2();
	void show();
};

void D2::show()
{
	cout << "Значение объекта D2: " << member << endl;
}

D2::D2(int ivalue = 214, int valueD1 = -22, int valueB2 = -33, int valueB1 = -111) : member{ ivalue }, D1{ valueD1,valueB1,valueB2 }
{
	cout << "Сработал конструктор D2" << endl;
	show();
}
D2::~D2()
{
	cout << "Сработал деструктор D2" << endl;
}