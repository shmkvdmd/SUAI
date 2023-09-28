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
	void zerodelete();
	void calc();
	void change();
	bool predict(int elem) { return abs(elem) >= 10; };

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

void Data::zerodelete()
{
	vector <int>::iterator newData = std::remove(m_data.begin(), m_data.end(), 0);
	m_data.erase(newData, m_data.end());

}

void Data::calc()
{

	std::for_each(m_data.begin(), m_data.end(), [](int& elem) { elem = elem * 2; });

}

void Data::change()
{

	int count{};

	for (int i = 0; i < m_data.size() - 1; i++)
	{

		if (predict(m_data.at(i)) == true)
		{

			m_data.at(i) = 0;
			count++;

		}

	}

	if (count == 0)
	{

		cout << "Элементов больше 10 не было найдено!" << endl;

	}

	else
	{
		cout << "Конечный массив:" << endl;
		showData();
		cout << endl;

	}


}