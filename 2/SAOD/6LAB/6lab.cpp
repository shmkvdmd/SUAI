#include <iostream>
#include <iomanip>
using namespace std;
//21 вар

struct node // структура для представления узлов дерева
{
	int key;
	unsigned int height;
	node* left;
	node* right;
	int heightree;
	node() { height = 1; }
	node(int k) { key = k; left = right = 0; height = 1; }
};

void del(node*& p) //удаление дерева
{
	if (p != NULL) {
		del(p->left);
		del(p->right);
		delete p;
		p = NULL;
	}
}

void counthtree(node* p)//высота дерева
{
	if (p) {
		if (p->right) {
			p->right->heightree = p->heightree + 1;
			counthtree(p->right);
		}
		if (p->left) {
			p->left->heightree = p->heightree + 1;
			counthtree(p->left);
		}
	}
}
unsigned  int height(node* p)//высота узла
{
	return p ? p->height : 0;
}

int bfactor(node* p)//разница высот между узлами
{
	return height(p->right) - height(p->left);
}

void fixheight(node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

node* rotateright(node* p) // правый поворот вокруг p
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* rotateleft(node* q) // левый поворот вокруг q
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

node* balance(node* p) // балансировка узла p
{
	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}

void insert(node*& p, int k) // вставка ключа k в дерево с корнем p
{
	if (p == NULL)
	{
		node* head = new node;
		head->key = k;
		head->right = NULL;
		head->left = NULL;
		p = head;
		return;
	}
	if (k == p->key) {
		cout << "Такой элемент уже есть" << endl;
		return;
	}
	if (k < p->key)
		insert(p->left, k);
	else
		insert(p->right, k);

	p = balance(p);
}

node* findmin(node* p) // поиск узла с минимальным ключом в дереве p  (самый малый элемент это левая ветка левого поддерева)
{
	return p->left ? findmin(p->left) : p;
}

node* removemin(node* p) // удаление узла с минимальным ключом из дерева p
{
	if (p->left == 0)
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

node* remove(node* p, int k) // удаление ключа k из дерева p
{
	if (!p) {
		return 0;
	}
	p->left = remove(p->left, k);
	if (k == p->key)
	{
		node* q = p->left;
		node* r = p->right;
		delete p;
		if (!r) return q;
		node* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		cout << "Элемент удален\n";
		return balance(min);
	}
	p->right = remove(p->right, k);
	return balance(p);
}

void find(node* p, int k, int& counter, bool& d) //поиск элементов
{
	counter++;
	if (p == NULL)
		return;
	if (k == p->key)
	{
		d = true;
		return;
	}
	if (k < p->key)
		find(p->left, k, counter, d);
	else
	{
		find(p->right, k, counter, d);
	}
}

void output(node* h, int i, bool flag) //вывод элементоа
{
	if (h == NULL)
	{
		return;
	}
	if (flag)
		i += 5;
	output(h->left, i, flag);
	cout << setw(65 - i) << h->key << endl;
	output(h->right, i, flag);
}

void task(node* p, node*& hmax, node*& hmin) //поиск элементов с минимальной и максимальной глубиной
{
	if (p != NULL)
	{
		if (p->left == NULL && p->right == NULL)
		{
			if (hmax) {
				if (p->heightree > hmax->heightree)
					hmax = p;
			}
			else {
				hmax = p;
			}
			if (hmin) {
				if (p->heightree < hmin->heightree)
					hmin = p;
			}
			else {
				hmin = p;
			}
		}
		task(p->left, hmax, hmin);
		task(p->right, hmax, hmin);
	}

}
void inorder(node* p) //симметричный обход
{
	if (p != NULL)
	{
		cout << p->key << "\t";
		inorder(p->left);
		inorder(p->right);
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	node* head = new node(0);
	head = NULL;
	bool flag = true;
	node* hmax = NULL;
	node* hmin = NULL;

	while (flag) {
		bool findflag = false;
		int counter = 0;
		int v;
		cout << endl;
		cout << "1.Добавление элемента\n"
			<< "2.Удаление элемента\n"
			<< "3.Показать дерево\n"
			<< "4.Поиск элемента\n"
			<< "5.Задание\n"
			<< "6.Выход\n";
		cin >> v;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		switch (v)
		{
		case 1:

			cout << "Введите добавляемое число \n";
			int numadd;
			cin >> numadd;
			insert(head, numadd);
			break;

		case 2:
			cout << "Введите удаляемое число\n";
			int numdel;
			cin >> numdel;
			head = remove(head, numdel);
			break;

		case 3:

			if (head)
				output(head, 0, true);
			else
				cout << "Дерево пустое " << endl;
			break;

		case 4:
			cout << "Введите число для поиска:\n";
			int numfind;
			cin >> numfind;
			findflag = false;
			find(head, numfind, counter, findflag);
			if (findflag) {
				cout << "Найдено\n";
				cout << "Количество шагов: " << counter << endl;
			}
			else
				cout << "Этого элемента нет в дереве\n";
			break;

		case 5:
		{
			if (head)
			{
				cout << "\n";
				cout << "Прямой обход дерева:\n" << endl;
				inorder(head);
				cout << "\n";
				cout << "\n";
			}
		}
			break;
		case 6:
			del(head);
			flag = false;
			break;
		default:
			cout << "Введите заново!\n";
			break;
		}
	}
	return 0;
}