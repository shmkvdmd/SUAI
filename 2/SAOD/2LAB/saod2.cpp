#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<iomanip>
#include<stdio.h.>
#include<fstream>
#include <Windows.h>
#include<conio.h>
using namespace std;
const int MWORD = 10;
struct Link
{
	int word;  //слово
	Link* next;        //указатель на следующее звено
	Link* prev;        //указатель на предыдущее звено
};
///////////////////////////////////////////////////////////////
class LinkList
{
private:
	Link* first;
	Link* last;
public:
	LinkList()             //конструктор
	{
		first = NULL;
		last = NULL;
	}
	//---------------------------------------------------
	~LinkList()            //деструктор
	{
		while (first != last)
		{
			Link* temp = first;
			first = first->prev;
			delete temp;
		}
		delete last;
	}
	//---------------------------------------------------
	void pushfront(int str)        //добавление данных в список
	{
		Link* newlink = new Link;
		newlink->word = str;

		if (last)
		{
			newlink->next = last;
			last->prev = newlink;
		}

		else
			first = newlink;

		newlink->prev = first;
		first->next = newlink;
		last = newlink;
	}
	//---------------------------------------------------
	void pushback(int str)        //добавление данных в список
	{
		Link* newlink = new Link;
		newlink->word = str;

		if (first)
		{
			newlink->prev = first;
			first->next = newlink;
		}

		else
			last = newlink;

		newlink->next = last;
		last->prev = newlink;
		first = newlink;
	}
	//---------------------------------------------
	void showList()             //показать список
	{
		int count = 0;
		Link* temp = first;
		if (first)
			do
			{
				cout << temp->word << " ";
				temp = temp->prev;
			} while (temp != first);
	}
	//---------------------------------------------
	void showList_front()             //показать список с начала
	{
		Link* temp = last;
		if (first)
			do
			{
				cout << temp->word << " ";
				temp = temp->next;
			} while (temp != last);
	}
	//--------------------------------------------
	void deleteLink(Link* temp)   //удаление звена из списка
	{
		if (first)                   //если в списке есть данные
		{
			if (temp->next == temp)    //если в списке единственный элемент
			{
				first = NULL;
				last = NULL;
			}
			else
			{
				if (temp == last)     //если эдемент на удаление последний
					last = last->next;

				if (temp == first)     //если элемент на удаление первый
					first = first->prev;

				(temp->next)->prev = temp->prev;
				(temp->prev)->next = temp->next;

				delete temp;
			}
		}
	}
	//--------------------------------------------------------
	Link* find_data(int dt)           //найти данные в списке
	{
		Link* temp = first;
		if (first)
			do
			{
				if (dt = temp->word)
					return temp;

				temp = temp->prev;
			} while (temp != first);

			temp = NULL;
			return temp;
	}
	//--------------------------------------------------
	int howmany_links()             //посчитать звенья в списке
	{
		if (first)
		{
			Link* temp = first;
			int i = 0;
			do
			{
				temp = temp->prev;
				i++;
			} while (temp != first);

			return i;
		}
		else
			return 0;

	}
	LinkList operator = (LinkList& l)       //перегрузка оператора =
	{
		if (l.first)
		{
			Link* temp = l.first;
			do
			{
				pushfront(temp->word);
				temp = temp->prev;
			} while (temp != l.first);
		}

		return *this;
	}
	int* showList_m()             //показать список
	{
		LinkList li;
		int* arr = new int[li.howmany_links()];
		int count = 0;
		Link* temp = first;
		int i = 0;
		if (first)
			do
			{
				arr[i++] = temp->word;
				temp = temp->prev;
			} while (temp != first);
			return arr;
	}
	int* showList_s()             //показать список с начала
	{
		LinkList li;
		int i = 0;
		int* arr = new int[li.howmany_links()];
		Link* temp = last;
		if (first)
			do
			{
				arr[i++] = temp->word;
				temp = temp->next;
			} while (temp != last);
			return arr;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_CTYPE, "rus");

	LinkList li, li2;
	int** mass = NULL;
	int mass_size = 0;
	char menu;

	while (true)
	{
		cout << "\nВыберите действие:"
			<< "\n1 - добавить элемент"
			<< "\n2 - вывод на экран"
			<< "\n3 - удалить элемент"
			<< "\n0 - выход"
			<< "\nВаш выбор: ";
		cin >> menu;
		switch (menu)
		{
		case '1':
		{
			int data;
			cout << "\nВведите данные:\n";
			cin >> data;
			li.pushfront(data);
			li2.pushfront(data);
			break;
		}
		case '2':
		{

			int* arr = li.showList_m();
			int* arr2 = li.showList_s();
			if (li.howmany_links() != 0)    //если список создан
			{

				li.showList();      //показать список
				cout << "\n";
				li.showList_front();
				cout << "\n";
				for (int i = 0; i < li.howmany_links(); i++)
				{
					cout << arr[i] - arr2[i] << " ";
				}
			}
			else
				cout << "\nСписок пуст" << endl;
			break;
		}
		case '3':
		{
			int data;
			if (li.howmany_links() != 0)
			{
				cout << "\nВведите данные которые хотите удалить" << endl;
				cin >> data;
				Link* d = li.find_data(data);
				if (d)
					li.deleteLink(d);
				else
					cout << "\nДанных нет в списке" << endl;
			}
			else
				cout << "\nСписок пуст" << endl;
			break;
		}
		case '0':
		{
			for (int i = 0; i < mass_size; i++)
				delete[]mass;
			return 0;
		}
		default:
			cout << "\nНеизвестное действие\n";
		}
	}

	return 0;
}