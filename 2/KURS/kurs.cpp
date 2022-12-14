#include <iostream>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#define SYMB_LEN_DOUBLE 11

using namespace std;


int input_validation() // проверка на ошибку ввода
{
	int a;
	bool ok;
	do {
		ok = true;

		cin >> a;
		if (!cin)             //проверка на ошибку при присваивании данных к переменной
		{
			ok = false;
			cin.clear();                     // очистка потока от флагов
			cin.ignore(1000, '\n');          // очистка потока
			cout << "Переменная должна быть числом." << endl;
		}
		else {
			if (cin.get() != '\n') //проверка на наличие символов после введённого значения
			{
				cin.ignore(1000, '\n');
				ok = false;
				cout << "После переменной не должно стоять пробелов или других символов." << endl;
			}
		}

		if (!ok) cout << "Введите значение повторно." << endl;
	} while (!ok);
	return a;
}




char* get_string(int* len) {
	*len = 0;
	int capacity = 1;
	char* s = (char*)malloc(sizeof(char));
	char c = getchar();
	while (c != '\n') {
		s[(*len)++] = c;
		if (*len >= capacity) {
			capacity *= 2;
			s = (char*)realloc(s, capacity * sizeof(char));
		}
		c = getchar();
	}
	s[*len] = '\0';
	return s;
}
double read_value(
	const char* promt = "",
	bool check_dot = true,
	bool check_minus = true,
	bool check_space = true
) {

	// строка введённая пользователем
	char* char_str;
	int len;

	// очищенная строка (без пробелов)
	char* clear_char_str;
	int len_clear;

	// счётсчик для динамического массива
	int capacity;

	// словарь
	char symb[SYMB_LEN_DOUBLE] = "1234567890";

	int i, j;

	// флаг состояния
	bool ok = false;

	// флаги ошибок
	bool error_dot = false;
	bool error_minus = false;

	// флаг на существование точки
	bool dot = false;

	bool minus = false;

	while (true) {
		// возвращаем все флаги в исходное состояние
		ok = false;
		dot = false;
		minus = false;

		error_dot = false;
		error_minus = false;

		// читаем строку
		cout << promt;
		char_str = get_string(&len);

		capacity = 1;
		clear_char_str = (char*)malloc(sizeof(char));

		// очистка строки от пробелов
		if (check_space) {
			len_clear = 0;
			for (i = 0; i < len; i++) {
				if (char_str[i] != ' ') {
					// замента запятой на точку
					if (char_str[i] == ',')
						clear_char_str[len_clear++] = '.';
					else
						clear_char_str[len_clear++] = char_str[i];

					capacity *= 2;
					clear_char_str = (char*)realloc(clear_char_str, capacity * sizeof(char));
				}
			}
		}
		else {
			len_clear = len;
			clear_char_str = char_str;
		}


		// проверка на знак минуса
		if (char_str[0] == '-' && check_minus) {
			minus = true;
		}

		// проходимся по каждому символу строки
		for (i = ((minus) ? 1 : 0); i < len_clear; i++) {
			switch (clear_char_str[i]) {
				// проверка на точку
			case('.'):
				if (check_dot)
					if (dot) {
						ok = false;
						error_dot = true;
					}
					else {
						ok = true;
						dot = true;
					}
				else {
					ok = false;
					error_dot = true;
				}

				break;

				// проверка на знак минуса
			case('-'):
				ok = false;
				error_minus = true;
				break;

				// проверка на остальные символы
			default:
				ok = false;
				// проходимся по каждому символу словаря
				for (j = 0; j < SYMB_LEN_DOUBLE; j++) {

					// стравниваем символ со словарём
					if (clear_char_str[i] == symb[j]) {
						// если нашли символ в словаре,
						// то останавливаем цикл со словарём
						ok = true;
						break;
					}
				}

				break;
			}

			// если мы не нашли символ, пишем ошибку
			if (!ok) {
				cout << " [ Ошибка ввода ]: ";

				// ошибки связанные с точками
				if (error_dot && !check_dot) {
					cout << "Число не должно содержать точки.";
				}
				else if (error_dot) {
					cout << "Слишком много точек.";
				}

				// ошибки связанные со знаком минус
				if (error_minus && !check_minus) {
					cout << "Число не может быть отрицательным.";
				}
				else if (error_minus) {
					cout << "Число не может содержать несколько знаков минус.";
				}

				// остальные ошибки
				if (!error_dot && !error_minus) {
					cout << "Число не может содержать в себе посторонних символов.";
				}

				cout << endl;
				break;
			}
		}

		// если небыло ошибок, то останавливаем бесконечный цикл
		if (ok)
			break;

	}

	// переводим и возвращаем значение
	return atof(clear_char_str);
}
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
	List* next = NULL;
};

void inputData(Train& r)
{

	cout << "Введите имя: "; cin >> r.nazn;
	cout << "Введите номер (100-999): ";
	r.number = read_value("", true, true, true);
	cout << endl;
	while ((!cin.good()) || (r.number < 100 || r.number > 999)) {
		cin.clear();
		cout << "Ошибка ввода, введите номер (100-999): "; r.number = read_value("", true, true, true);  cout << endl;
	}
	cout << "Введите часы(00-24): ";
	r.hour = read_value("", true, true, true);
	while ((!cin.good()) || (r.hour < 0 || r.hour > 24))
	{
		cin.clear();
		cout << "Введите часы(00-24): "; r.hour = read_value("", true, true, true); cout << endl;
	}
	cout << "Введите минуты(00-60): ";
	r.minute = read_value("", true, true, true);
	while ((!cin.good()) || (r.minute < 0 || r.minute > 60))
	{
		cin.clear();
		cout << "Введите минуты(00-60): "; r.minute = read_value("", true, true, true); cout << endl;
	}
}
void inputData_d(Train& r)
{
	cout << "Введите имя: "; cin >> r.nazn;
	cout << "Введите номер(100-999): "; r.number = read_value("", true, true, true);
	cout << endl;
	while ((!cin.good()) || (r.number < 100 || r.number > 999)) {
		cin.clear();
		cout << "Ошибка ввода, введите номер (100-999): "; r.number = read_value("", true, true, true);  cout << endl;
	}
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
		p->next = (*cur)->next;
		(*cur)->next = p;
	}
	*cur = p;
}
void OutLine(Train d)
{
	cout << setw(20) << d.nazn << setw(10) << d.number << setw(7) << d.hour << ":" << d.minute << endl;
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

List* inputFile(List* head, List* cur)
{
	Train r;
	List* p = new List;
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open())
		cout << "Файл не может быть открыт!\n";
	while (fin) {
		fin >> r.nazn >> r.number >> r.hour >> r.minute;
		AddElem(&head, &cur, r);
	};
	fin.close();
	cout << "Данные из файла получены\n";
	return head;
}
List* savefile(List* head, List* cur)
{
	Train r;
	List* p = new List;
	ofstream fin;
	fin.open("data.txt", ios_base::app);
	if (!fin.is_open())
		cout << "Файл не может быть открыт!\n";
	inputData(r);
	fin << endl << r.nazn << " " << r.number << " " << r.hour << " " << r.minute;
	fin.close();
	return head;
}
//очистка памяти
void Free(List** begin)
{
	if (*begin == 0) return;
	List* p = *begin;
	List* t;
	while (p)
	{
		t = p;
		p = p->next;
		delete t;
	}
	*begin = NULL;
}


int main()
{
	setlocale(LC_ALL, "ru");
	List* head = NULL;
	List* cur = NULL;
	Train r;
	int n = -1;
	Free(&head);
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
		n = input_validation();
		if ((n < 0) || (n > 6)) {
			n = NULL;
			cin.clear();
			cin.sync();
			cout << "Введите значение повторно. ";
			n = input_validation();
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
			break;
		}
		case 3:
		{
			string destination;
			if (!head) { cout << "Нет данных!" << endl; break; }
			cout << "Введите пункт назначения: "; cin >> destination;
			cout << setw(20) << "Название" << setw(10) << "Номер" << setw(10) << "Время" << endl;
			TaskFinder(head, destination);
			break;
		}
		case 4:
		{
			cout << setw(20) << "Название" << setw(10) << "Номер" << setw(10) << "Время" << endl;
			if (head)
				ShowList(head);
			else cout << "Нет данных!" << endl;
			break;
		}
		case 5:
		{
			head = savefile(head, cur);
			break;
		}
		case 6:
		{
			Free(&head);
			head = inputFile(head, cur);
			break;
		}
		}
	}
	Free(&head);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
	return 0;
	//system("pause");
}