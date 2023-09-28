#pragma once
#include "D1.h"
#include <iostream>
using namespace std;

class D3 : private D1
{
protected:
	int member;
public:
	D3(int, int, int, int);
	~D3();
	void show();
};

void D3::show()
{
	cout << "Значение объекта D3: " << member << endl;
}

D3::D3(int ivalue = 541, int valueD1 = -22, int valueB2 = -33, int valueB1 = -111) : member{ ivalue }, D1{ valueD1,valueB1,valueB2 }
{
	cout << "Сработал конструктор D3" << endl;
	show();
}
D3::~D3()
{
	cout << "Сработал деструктор D3" << endl;
}