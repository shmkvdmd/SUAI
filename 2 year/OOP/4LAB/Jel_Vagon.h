#include <iostream>
#include <string>
using namespace std;
#pragma once
class Jel_Vagon
{
protected:
    int capacity;
    string type;
    int price_u;
    int m_priceBottom;
public:
    Jel_Vagon(string type,int capacity,int price_u,int priceBot);
    ~Jel_Vagon();
    void show_info();
};

Jel_Vagon::Jel_Vagon(string Type = "N", int Capacity = 50, int Price_u = 3000, int priceBottom = 4000) 
{
    capacity = Capacity;
    type = Type;
    price_u = Price_u;
    m_priceBottom = priceBottom;
}
Jel_Vagon::~Jel_Vagon()
{}
void Jel_Vagon::show_info()
{
    cout << "Информация о вагоне:" << endl;
    cout << endl;
    cout << "Тип вагона: " << type << endl;
    cout << "Вместимость вагона: " << capacity << endl;
    cout << "Цена верхних мест: " << price_u << "руб." << endl;
    cout << "Цена нижних мест: " << m_priceBottom << "руб." << endl;
}
