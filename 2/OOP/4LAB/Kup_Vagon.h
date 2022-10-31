#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Jel_Vagon.h"

class Kup_Vagon :public Jel_Vagon
{
private:
    int busy_u;
    int busy_d;
public:
    Kup_Vagon(int priceTop, int priceBottom, int busy_u, int busy_d, string type, int capacity);
    ~Kup_Vagon();
    void kup_info();
    void makeMoney(const int&);
};

Kup_Vagon::Kup_Vagon(int priceTop = 3000, int priceBottom = 4000, int Busy_u = 15, int Busy_d = 15, string type = "Купе", int capacity = 50) : Jel_Vagon(type, capacity, priceTop, priceBottom)
{
    busy_u = Busy_u;
    busy_d = Busy_d;
}

Kup_Vagon::~Kup_Vagon()
{}

void Kup_Vagon::kup_info()
{
    cout << "....Купе....\n";
    cout << "Количество пассажиров на верхних местах: ";
    cout << busy_d << endl;
    cout << "Количество пассажиров на нижних местах: ";
    cout << busy_u << endl;
}

void Kup_Vagon::makeMoney(const int& years)
{
    int res;
    res = ((busy_d * m_priceBottom) + (busy_u * price_u)) * years;
    cout << "Срок(лет): " << years << endl;
    cout << "прибыль составит: " << res << endl;
}