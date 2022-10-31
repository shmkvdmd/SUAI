#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Jel_Vagon.h"

class Sid_Vagon:public Jel_Vagon
{
private:
    int count;
public:
    Sid_Vagon(int pricebottom,int count,string type,int capacity);
    ~Sid_Vagon();
    void sit_info();
    void makeMoney(int);
};

Sid_Vagon::Sid_Vagon(int priceBottom = 4000, int Count = 50, string type = "Сидячий", int capacity = 50) : Jel_Vagon(type,capacity,0,priceBottom)
{
    count = Count;
}
Sid_Vagon::~Sid_Vagon()
{}

void Sid_Vagon::sit_info()
{
    cout << "....Сидячий вагон....\n";
    cout << "Количество пассажиров: " << count << endl;
    cout << "цена " << m_priceBottom << endl;
}

void Sid_Vagon::makeMoney(int years)
{
    int res;
    res = (years * count * m_priceBottom);
    cout << "Срок(лет): " << years << endl;
    cout << "прибыль составит: " << res << endl;
}