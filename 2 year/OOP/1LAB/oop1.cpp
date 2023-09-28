#include<iostream>
using namespace std;

class Count
{
private:
double right;
double left;

public:
void setcount(double, double);
bool rangecheck(double);
void output();
};

void Count::setcount(double right, double left)
{
    this->right = right;
    this->left = left;
}
bool Count::rangecheck(double asd)
{

    if (right > asd && left <= asd)
        return true;
    else
        return false;
}
void Count::output()
{
    cout << "Вы ввели числа " << left << " и " << right;

}



int main()
{
    system("color F1");
    setlocale(LC_ALL, "ru");
    Count num1;
    num1.setcount(10, 1);
    num1.output();
    if (num1.rangecheck(2))
    {
        cout << "\nВходит в диапозон";
    }
    else
    {
        cout << "\nНе входит в диапозон";
    }

    if (num1.rangecheck(15))
    {
        cout << "\nВходитвдиапозон";
    }
    else
    {
        cout << "\nНе входит в диапозон";
    }
    return 0;
}
