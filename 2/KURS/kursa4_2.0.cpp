#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>
using namespace std;

void AddElem(vector <string>& destination, vector <int>& number, vector <string>& time)
{
	string addDest, addTime;
	int addNumb;
	cout << "Введите пункт назначения: "; cin >> addDest; destination.push_back(addDest);
	cout << "Введите номер рейса: "; cin >> addNumb; number.push_back(addNumb);
	cout << "Введите время рейса: "; cin >> addTime; time.push_back(addTime);
}

void DelElem(vector <string>& destination, vector <int>& number, vector <string>& time)
{
	int choice;
	auto iter = number.cbegin();
	auto iter2 = destination.cbegin();
	auto iter3 = time.cbegin();
	cout << "Введите номер пункта назначения, который нужно удалить. Введите 666, чтобы удалить все данные: "; cin >> choice;
	if (choice == 666)
	{
		destination.clear();
		number.clear();
		time.clear();
	}
	else
	{
		number.erase(iter + choice - 1);
		destination.erase(iter2 + choice - 1);
		time.erase(iter3 + choice - 1);
	}
}

void ShowTable(vector <string>& destination, vector <int>& number, vector <string>& time)
{

	size_t dest = destination.size();
	if (dest == 0)
	{
		cout << "Нет данных\n";
	}
	else
	{
		cout << setw(25) << "Название рейса" << setw(19) << "Номер рейса" << setw(19) << "Время рейса" << "\n";
		for (size_t i = 0; i < dest; i++)
		{
			cout << setw(20) << destination[i] << setw(20) << number[i] << setw(20) << time[i] << "\n";
		}
	}
}

void FindElem(vector <string>& destination, vector <int>& number, vector <string>& time)
{
	string findDest;
	int count = 0;
	cout << "Введите название пункта назначения: "; cin >> findDest;
	for (int i = 0; i < destination.size(); ++i)
	{
		if (findDest == destination.at(i))
		{
			count++;
			cout << setw(20) << destination[i] << setw(20) << number[i] << setw(20) << time[i] << "\n";
		}
	}
	if (count == 0)
		cout << "Рейсы не найдены\n";
}
void LoadTable(vector <string>& destination, vector <int>& number, vector <string>& time)
{
	ofstream write;
	write.open("data.txt", ios_base::out | ios_base::trunc);
	for (int i = 0; i < destination.size(); ++i)
	{
		write << destination[i] << " " << number[i] << " " << time[i] << "\n";
	}
	write.close();
}

void ReadTable(vector <string>& destination, vector <int>& number, vector <string>& time)
{
	int n;
	string d, t;
	ifstream read;
	read.open("data.txt", ios_base::in);
	while (read >> d >> n >> t)
	{
		destination.push_back(d);
		number.push_back(n);
		time.push_back(t);
	}
	read.close();
	cout << "Данные получены\n";
}

int main()
{
	setlocale(LC_ALL, "RU");
	vector <string> destination = {};
	vector <int> number = {};
	vector <string> time = {};
	int menu = -111;
	while (menu != 0)
	{
		cout << endl <<
			"1 - Добавление" << endl <<
			"2 - Удаление" << endl <<
			"3 - Поиск " << endl <<
			"4 - Вывод на экран" << endl <<
			"5 - Сохранить в файл" << endl <<
			"6 - Загрузить данные из файла" << endl <<
			"0 - Выход\nВыберите действие: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			AddElem(destination, number, time);
			break;
		}
		case 2:
		{
			DelElem(destination, number, time);
			break;
		}
		case 3:
		{
			FindElem(destination, number, time);
			break;
		}
		case 4:
		{
			ShowTable(destination, number, time);
			break;
		}
		case 5:
		{
			LoadTable(destination, number, time);
			break;
		}
		case 6:
		{
			ReadTable(destination, number, time);
			break;
		}
		}
	}
	return 0;
}
