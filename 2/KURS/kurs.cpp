#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
struct Train
{
	char nazn[20];
	int number;
	int hour;
	int minute;
}; 
struct List
{
	Train data;
	List* next;
};

void inputData(Train& r)
{
	cout << "Введите имя: "; cin >> r.nazn;
	cout << "Введите номер: "; cin >> r.number;
	cout << "Введите часы: "; cin >> r.hour;
	cout << "Введите минуты: "; cin >> r.minute;
} 
void inputData_d(Train& r)
{
	cout << "Введите имя: "; cin >> r.nazn;
	cout << "Введите номер: "; cin >> r.number;
}
void AddElem(List** begin, List** cur, Train elem)
{
	List* p = new List;
	p->data = elem;
	//проверка, является ли список пустым
	if (*begin == NULL)
	{
		p->next = NULL;
		*begin = p;
	}
	else
	{
		p->next = (*cur)->next;// или p->next=NULL;
		(*cur)->next = p;
	}
	*cur = p;
}
void OutLine(Train d)
{
	cout << setw(10) << d.nazn << setw(10) << d.number << setw(7) << d.hour << ":" << d.minute << endl;
}

void ShowList(List* begin)
{
	List* p = begin;
	while (p != NULL)
	{
		OutLine(p->data);
		p = p->next;
	}
}
void DelElem(List** begin, List* ptrCur)
{
	List* p;
	if (ptrCur == *begin) {//удаляем первый элемент
		*begin = (*begin)->next;
	}
	else
	{ 
			p = *begin;
		while (p->next != ptrCur)
			p = p->next;
		// удаление элемента
		p->next = ptrCur->next;
	}
	delete ptrCur;
}
List* FindElem(List* begin, Train elem)
{
	List* p = begin;
	while (p != NULL)
	{
		if (!strcmp(p->data.nazn, elem.nazn) && (p->data.number == elem.number))
			break;
		p = p->next;
	}
	return p;
}
void TaskFinder(List* begin, string destination)
{
	List* p = begin;
	bool f = false;
	while (p != NULL)
	{
		if (p->data.nazn == destination)
		{
			f = true;
			OutLine(p->data);
		}
		p = p->next;
	}
	if (!f) cout << "Данные не найдены" << endl;
}

void inputFile(List* begin)
{
	List* p = begin;
	ifstream fin;
	char file[15];
	fin.open(file);
	do {
		fin >> p->data.nazn >> p->data.number >> p->data.hour >> p->data.minute;
		p = p->next;
	} while (fin.good());
	fin.close();
	cout << "Данные из файла получены\n";
	
}

int main()
{
	setlocale(LC_ALL, "ru");
	List* head = NULL;
	List* cur = NULL;
	Train r;
	int n = -1;
	while (n != 0)
	{
		cout << endl <<
			"1 - Добавление" << endl <<
			"2 - Удаление" << endl <<
			"3 - Поиск " << endl <<
			"4 - Вывод на экран" << endl <<
			"5 - Сохранить в файл" << endl <<
			"6 - Загрузить данные из файла" << endl <<
			"0 - Выход\nВыберите действие: ";
		cin >> n;
		while (cin.fail() || (n < 0) || (n > 6)) {
			cin.clear();
			cin.sync();
			cout << "Ошибка ввода, выберите действие: "; cin >> n;
		}
		switch (n)
		{
		case 1: 
		{
			inputData(r);
			AddElem(&head, &cur, r);
			break;
		}
		case 2:
		{
			{
				if (!head) { cout << "Нет данных!" << endl; break; }
				List* ptr;
				inputData_d(r);
				ptr = FindElem(head, r);
				if (ptr == NULL)cout << "Запись не найдена!" << endl;
				else { DelElem(&head, ptr); cout << "Запись удалена!" << endl; }; }
		}
		case 3:
		{
			string destination;
			if (!head) { cout << "Нет данных!" << endl; break; }
			cout << "Введите пункт назначениея: "; cin >> destination;
			cout << setw(10) << "Название" << setw(10) << "Номер" << setw(10) << "Время" << endl;
			TaskFinder(head,destination);
			break;
		}
		case 4:
		{
			cout << setw(10) << "Название" << setw(10) << "Номер" << setw(10) << "Время" << endl;
			if (head)
				ShowList(head);
			else cout << "Нет данных!" << endl;
			break;
		}
		case 5:
		{
			ofstream bd_save("data.txt");
			if (!bd_save.is_open())
			{
				cout << "Ошибка открытия файла\n";
			}
			else 
			{
				bd_save << "Работа с бд" << endl;
				bd_save.close();
			}
			break;
		}
		case 6:
		{
			inputFile(head);
			break;
		}
		}
	}
}