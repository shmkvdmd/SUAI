#include <iostream>
using namespace std;

#define size_Task 3

struct stack
{
	float elem[size_Task];
	int top;	
};

void init(struct stack *stk)
{
	stk->top = 0;	
}

void push(struct stack* stk, float f) //добавление элемента
{
	if (stk->top < size_Task)
	{
		stk->elem[stk->top] = f;
		stk->top++;
	}
	else
		cout << "Стек полон, количество элементов: " << stk->top << endl;
}
float pop(struct stack* stk) //удаление элемента
{
	float elem;
	if ((stk->top) > 0)
	{
		stk->top--;
		elem = stk->elem[stk->top];
		return elem;
	}
	else
	{
		cout << "Стек пуст!\n";
		return 0;
	}
}

float stkTop(struct stack* stk) //верхнее значение стека
{
	if ((stk->top) > 0)
	{
		return stk->elem[stk->top - 1];
	}
	else
	{
		cout << "Стек пуст!\n";
		return 0;
	}
}

int getcount(struct stack *stk) //кол-во элементов
{
	return stk->top;
}

int isempty(struct stack* stk) //проверка на пустоту
{
	if (stk->top == 0) return 1;
	else return 0;
}

void stkPrint(struct stack* stk) //вывод стека
{
	int i;
	i = stk->top;
	if (isempty(stk) == 1) return;
	do
	{
		i--;
		cout << "\n" << stk->elem[i];
	} while (i > 0);
}

int main()
{
	setlocale(LC_ALL, "RU");
	struct stack* stk;
	int i, n;
	float elem;
	stk = (struct stack*)malloc(sizeof(struct stack));
	init(stk);
	cout << "Введите количество элементов в стеке: ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "Введите элемент: " << i << " ";
		cin >> elem;
		push(stk, elem);
	}
	cout << "В стеке элементов " << getcount(stk) << endl;
	stkPrint(stk);
	cout << "\nВерхний элемент: " << stkTop(stk) << endl;
	do
	{
		cout << "Извлекаем элемент " << pop(stk);
		cout << " в стеке осталось элементов " << getcount(stk) << endl;
	} while (isempty(stk) == 0);
	return 0;

}