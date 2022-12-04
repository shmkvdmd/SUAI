#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>

class Data
{

private:

	std::vector<int> m_data;

public:

	Data(std::vector<int>);
	~Data();

	void showData();
	int getSum();
	void calc();
	void change();
	bool predict(int elem) { return elem >= 20; };

};

class Sum
{

public:

	int sum{ 0 };

	void operator() (int term)
	{

		sum += term;

	}

};

Data::Data(std::vector<int> input) : m_data{ input }
{}

Data::~Data()
{}

void Data::showData()
{

	auto print = [](const int& n) { std::cout << " " << std::setw(3) << n; };

	std::for_each(m_data.cbegin(), m_data.cend(), print);

}

int Data::getSum()
{

	Sum sum = std::for_each(m_data.cbegin(), m_data.cend(), Sum());

	return sum.sum;

}

void Data::calc()
{

	std::for_each(m_data.begin(), m_data.end(), [](int& elem) { elem = 2 * elem + 5; });

	showData();

}

void Data::change()
{

	int count{};

	for (int i = 0; i < m_data.size() - 1; i++)
	{

		if (predict(m_data.at(i)) == true)
		{

			m_data.at(i) = 10;
			count++;

		}

	}

	if (count == 0)
	{

		std::cout << "Элементов больше или равных 20 не было найдено!" << std::endl;

	}

	else
	{
		std::cout << "Конечный массив:" << std::endl;
		showData();
		std::cout << std::endl;

	}


}