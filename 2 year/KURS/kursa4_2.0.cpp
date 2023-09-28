#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <windows.h>
using namespace std;

int input_validation(int a,int b)
{
	int x;
	while (true)
	{
		while (!(cin >> x))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Неверный ввод. Повторите." << endl;
		}
		if ((x < a) || (x > b))
		{
			cout << "Неверный ввод. Повторите." << endl;
		}
		else
		{
			break;
		}
	}
	return x;

}

struct TRAIN
{
	int number;
	string destination, time;
};

struct comp
{
	bool operator() (const TRAIN& a, const TRAIN& b) const
	{
		return a.time < b.time;
	}
};

vector <TRAIN> AddElem(vector <TRAIN>& vec_struct)
{
	vector <TRAIN> m;
	TRAIN t1;
	string addDest, addTime;
	int addNumb, hour = 0, minute = 0;
	cout << "Введите пункт назначения: "; cin >> addDest; t1.destination = addDest;
	cout << "Введите номер рейса(100-999): "; addNumb = input_validation(100, 999);
	t1.number = addNumb;
	cout << "Ввод времени рейса\nВведите часы(00-23): "; hour = input_validation(0, 23);
	cout << "Введите минуты(00-59): "; minute = input_validation(0, 59);
	string h = to_string(hour); 
	string mi = to_string(minute);
	if (h.length() < 2)
	{
		h = "0" + h;
	}
	if (mi.length() < 2)
	{
		mi = "0" + mi;
	}


	addTime = h + ":" + mi;
	t1.time = addTime;
	vec_struct.push_back(t1);
	return vec_struct;
}

vector <TRAIN> DelElem(vector <TRAIN>& vec_struct)
{
	int choice = 88;
	auto iter = vec_struct.cbegin();
	int count = 0;
	for (int i = 0; i < vec_struct.size(); i++)
	{
		count++;
	}
	cout << "Введите номер пункта назначения, который нужно удалить. Введите 0, чтобы удалить все данные: ";
	choice = input_validation(0, count);
	if (choice == 0)
	{
		vec_struct.clear();
	}
	else
	{
		vec_struct.erase(iter + choice - 1);
	}
	return vec_struct;
}

void ShowTable(vector <TRAIN>& vec_struct)
{
	for (int i = 0; i < vec_struct.size(); i++)
	{
		cout << i << " | " <<  vec_struct[i].destination << " | " << vec_struct[i].number << " | " << vec_struct[i].time << "\n";
	}
}

vector <TRAIN> FindElem(vector <TRAIN>& vec_struct)
{
	string findDest;
	int count = 0;
	cout << "Введите название пункта назначения: "; cin >> findDest;
	for (int i = 0; i < vec_struct.size(); i++)
	{
		if (findDest == vec_struct[i].destination)
		{ 
			count++;
			cout << vec_struct[i].destination << " | " << vec_struct[i].number << " | " << vec_struct[i].time << "\n";
		}
	}
	if (count == 0)
		cout << "Рейсы не найдены\n";
	return vec_struct;
}
vector <TRAIN> LoadTable(vector <TRAIN>& vec_struct)
{
	TRAIN t;
	ofstream write;
	write.open("data.txt", ios_base::out | ios_base::trunc);
	for (int i = 0; i < vec_struct.size(); ++i)
	{
		write << vec_struct[i].destination << " " << vec_struct[i].number << " " << vec_struct[i].time << "\n";
	}
	write.close();
	return vec_struct;
}


vector <TRAIN> ReadTable(vector <TRAIN>& vec_struct)
{
	TRAIN t;
	ifstream read;
	read.open("data.txt", ios_base::in);
	while (read >> t.destination && read >> t.number && read >> t.time)
	{
		vec_struct.push_back(t);
	}
	read.close();
	cout << "Данные получены\n";
	return vec_struct;
}


vector <TRAIN> sorting(vector <TRAIN>& vec_struct)
{
	sort(vec_struct.begin(), vec_struct.end(),comp());
	return vec_struct;
}

int main()
{
	SetConsoleCP(1251);                
	SetConsoleOutputCP(1251);
	vector <string> destination = {};
	vector <int> number = {};
	vector <string> time = {};
	vector <TRAIN> vec_struct;
	TRAIN struct1;

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
			"7 - сортировка по времени" << endl <<
			"0 - Выход\nВыберите действие: ";
		menu = input_validation(0,7);
		switch (menu)
		{
		case 1:
		{
			AddElem(vec_struct);
			break;
		}
		case 2:
		{
			DelElem(vec_struct);
			break;
		}
		case 3:
		{
			FindElem(vec_struct);
			break;
		}
		case 4:
		{
			ShowTable(vec_struct);
			break;
		}
		case 5:
		{
			LoadTable(vec_struct);
			break;
		}
		case 6:
		{
			ReadTable(vec_struct);
			break;
		}
		case 7:
		{
			sorting(vec_struct);
			break;
		}
		}
	}
	return 0;
}