#include <exception>
#include <iostream>
using namespace std;

class Errors : public std::exception
{

protected:

	int m_code;

public:

	Errors(const char*, int);
	~Errors();

	void getInfo();

};

Errors::Errors(const char* message, int code) : exception{ message }, m_code{ code }
{}

Errors::~Errors()
{}

void Errors::getInfo()
{

	if (m_code == 1)
	{
		cout << "Число должно быть в диапазоне от 0 до 3" << endl;
	}

	if (m_code == 2)
	{
		cout << "Невозможно подсчитать сумму элементов, так как нет положительных элементов" << endl;

	}
}