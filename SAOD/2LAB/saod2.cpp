#include <iostream>
#include <iomanip>
using namespace std;
struct list
{
    int field; // поле данных
    struct list* ptr; // указатель на следующий элемент
};

struct list* init(int a) // а- значение первого узла
{
    struct list* lst;
    // выделение памяти под корень списка
    lst = (struct list*)malloc(sizeof(struct list));
    lst->field = a;
    lst->ptr = lst; // указатель на сам корневой узел
    return(lst);
}
struct list* addelem(list* lst, int number)
{
    struct list* temp, * p;
    temp = (struct list*)malloc(sizeof(list));
    p = lst->ptr; // сохранение указателя на следующий элемент
    lst->ptr = temp; // предыдущий узел указывает на создаваемый
    temp->field = number; // сохранение поля данных добавляемого узла
    temp->ptr = p; // созданный узел указывает на следующий элемент
    return(temp);
}

struct list* deletelem(list* lst)
{
    struct list* temp;
    temp = lst;
    while (temp->ptr != lst) // просматриваем список начиная с корня
    { // пока не найдем узел, предшествующий lst
        temp = temp->ptr;
    }
    temp->ptr = lst->ptr; // переставляем указатель
    free(lst); // освобождаем память удаляемого узла
    return(temp);
}


void listprint(list* lst)
{
    struct list* p;
    p = lst;
    do {
        printf("%d ", p->field); // вывод значения узла p
        p = p->ptr; // переход к следующему узлу
    } while (p != lst); // условие окончания обхода
}

void listprintr(list* lst)
{
    struct list* p;
    p = lst;
    int count = 0;
    list* temp = lst;
    while (temp) {
        count++;
        temp = temp->ptr;
    }
    while (p != lst)
    {
        p = p->ptr; // переход к концу списка
    }
    for (int i = 0; i != count - 1; i++)
    {
        cout << p->field << " ";
        p = p->ptr;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    list* head, * cur, * cur2;
    int num, n, n2, opt, position, number, size;
    n = 0;
    int* arr = new int[n];
    int* arr2 = new int[n];
    head = init(n);
    cur = head;
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
        cur = addelem(cur, arr[i]);
    }
    bool tr = true;
    while (tr)
    {
        cout << "\nВведите 1, если хотите добавить элемент. \n";
        cout << "Введите 2, если хотите удалить элемент. \n";
        cout << "Введите 3, чтобы вывести результат. \n";
        cout << "Ввод: ";
        cin >> opt;
        switch (opt)
        {
        case(1):
            n++;
            cur = addelem(cur, n);
            listprint(head);
            break;
        case(2):
            n--;
            head = init(n);
            cur = head;
            for (int i = 0; i < n; i++) {
                arr[i] = i + 1;
                cur = addelem(cur, arr[i]);
            }
            listprint(head);
            if (n < 0)
            {
                cout << "Нет элементов";
                tr = false;
            }
            break;
        case(3):
            listprint(head);
            printf("\n");
            listprintr(head);
            printf("\n");
            for (int i = 0; i < n; i++) {
                arr[i] = i + 1;
            }
            for (int i = n; i != 0; i--) {
                arr2[i] = i;
            }
            for (int i = 0; i < n; i++) {
                n2 = arr[i] - arr2[n - i];
                cout << n2 << " ";
            }
            break;
        }
    }
    return 0;
}