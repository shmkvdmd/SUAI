#include <iostream>
#include <cmath>
using namespace std;

class Array
{
protected:
	int* m_arr;
	int m_length;
public:
	Array(int length);
	~Array();
	int getLength()
	{
		return m_length;
	}
	void setElem(const int& value, const int& index)
	{
		m_arr[index] = value;
	}
	int getElem(const int& index)
	{
		return m_arr[index];
	}
	void showArr();
	int getmax();
	int getsum();
	void reshapearr(int, int);
};

Array::Array(int length)
{
	m_length = length;
	m_arr = new int[m_length];
}

Array::~Array()
{
	delete[] m_arr;
}

void Array::showArr()
{
	for (int i = 0; i < m_length; i++)
	{
		cout << m_arr[i] << " ";
	}
	cout << endl;
}

int Array::getmax()
{
	int maxValue = m_arr[0];
	for (int i = 1; i < m_length; i++)
	{
		if (m_arr[i] > maxValue)
		{
			maxValue = m_arr[i];
		}
	}
	return maxValue;
}

int Array::getsum()
{
	int sum = 0;
	int count = 0;
	for (int i = 0; i < m_length; i++)
	{
		if (m_arr[i] > 0)
		{
			count = i;
		}
	}
	for (int i = 0; i < count; i++)
	{
		sum += m_arr[i];
	}
	return sum;
}

void Array::reshapearr(int a, int b)
{
	int* tmp = new int[100];
	int j = 0;
	int k = 0;
	cout << "Удалить все элементы, модуль которых находится в интервале от " << a << " до " << b << endl;
	try
	{
		if ((a == 0) && (b == 0))
		{
			throw range_error("Неверный интервал");
		}
	}
	catch (std::range_error)
	{
		cout << "Неверные границы. Преобразование не выполнено.\n";
	}
	for (int i = 0; i < m_length; i++)
	{
		if (!(a <= abs(m_arr[i]) && abs(m_arr[i]) <= b))
		{
			if (i != k) m_arr[k] = m_arr[i];
			++k;
		}
	}

	for (int i = k; i < m_length; i++) m_arr[i] = 0;

	for (int i = 0; i < m_length; i++) cout << m_arr[i] << ' ';
	cout << endl;
}