#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Jel_Vagon.h"

class Plac_Vagon:public Jel_Vagon
{
private:
    int busy_u;
    int busy_d;
public:
    Plac_Vagon(int priceTop, int priceBottom, int busy_u, int busy_d, string type, int capacity);
    ~Plac_Vagon();
    void econom_info();
    void makeMoney(const int&);
};

Plac_Vagon::Plac_Vagon(int priceTop = 1500, int priceBottom = 2000, int Busy_u = 15, int Busy_d = 15, string type = "Плацкарт", int capacity = 50) : Jel_Vagon(type, capacity, priceTop, priceBottom)
{
    busy_u = Busy_u;
    busy_d = Busy_d;
}
Plac_Vagon::~Plac_Vagon()
{}

void Plac_Vagon::econom_info()
{
    cout << "....Эконом....\n";
    cout << "Количество пассажиров на верхних местах: ";
    cout << busy_d << endl;
    cout << "Количество пассажиров на нижних местах: ";
    cout << busy_u << endl;
}

void Plac_Vagon::makeMoney(const int& years)
{
    int res;
    res = ((busy_d * m_priceBottom) + (busy_u * price_u)) * years;
    cout << "Срок(лет): " << years << endl;
    cout << "прибыль составит: " << res << endl;
}