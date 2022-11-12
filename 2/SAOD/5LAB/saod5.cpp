#include <iostream>
using namespace std;

uint16_t numcomp = 0;
uint16_t numreshuffle = 0;

int getRandomNumber(int min, int max)
{
	return min + (rand() % (max - min + 1));
}

int inputNum()
{
	int num = 0;
	cin >> num;
	while (cin.fail() || (num <= 0)) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail(), '/n');
		cout << "Неверно!" << endl;
		cout << "Введите заново:" << endl;
		cin >> num;
		return num;
	}
	return num;
}

void Fill(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int n = getRandomNumber(1, 99);
		arr[i] = n;
	}
	cout << "Массив заполнен" << endl;
}

void Find(int size, int* arr)
{
	cout << "Как вы хотите искать?(1-по номеру элемента/2-по значению)" << endl;
	int ch = inputNum();

	if ((ch != 1) && (ch != 2))
	{
		cout << "Неверно" << endl;
		return;
	}

	if (ch == 2)
	{
		cout << "Введите значение:" << endl;
		int f = inputNum();
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == f)
			{
				cout << i << ":  " << arr[i] << endl;
			}
		}
	}
	else if (ch == 1) {
		cout << "Введите номер:" << endl;
		int n = inputNum();
		if ((n < 0) || (n > size))
		{
			cout << "Неверно" << endl;
			return;
		}
		else { cout << n << ":  " << arr[n] << endl; }

	}

}
void quickSort(int* arr, int low, int high)
{
	int i = low;
	int j = high;
	int pivot = arr[(i + j) / 2];
	int temp;

	while (i <= j)
	{
		numcomp++;
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
			numreshuffle++;
		}
	}
	if (j > low)
		quickSort(arr, low, j);
	if (i < high)
		quickSort(arr, i, high);
}

void del(int*& arr, int& size)
{
	if (size != 1) {
		size--;
		int* newArray = new int[size];

		for (int i = 0; i < size; i++)
		{
			newArray[i] = arr[i];
		}

		delete[] arr;
		arr = newArray;
		cout << "Элемент удален" << endl;
	}
	else { cout << "В массиве не может быть 0 элементов" << endl; }
}

void count(int*& arr, int& size)
{
	quickSort(arr, 0, size - 1);
	int count = 0;
	cout << endl;
	cout << "Количество повторяющихся элементов:" << endl;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			count++;
		}
		else {
			cout << arr[i] << ":" << count + 1 << endl;
			count = 0;
		};
	}
}

void add(int*& arr, int& size)
{
	int v = 0;
	cout << "Введите значения элемента:" << endl;
	cin >> v;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail(), '/n');
		cout << "Неверно!" << endl;
		cout << "Введите заново:" << endl;
		cin >> v;
	}

	int* newArray = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}

	newArray[size] = v;
	size++;
	delete[] arr;
	arr = newArray;
	cout << "Элемент добавлен" << endl;
}
int main()
{
	setlocale(LC_ALL, "Ru");
	int v = 0;
	cout << "Введите количество элементов в массиве:" << endl;
	int size = inputNum();
	int* arr = new int[size];
	cout << endl;
	cout << "Меню:" << endl;
	cout << "1.Заполнить массив" << endl;
	cout << "2.Добавить элемент" << endl;
	cout << "3.Удалить элемент" << endl;
	cout << "4.Вывод массива" << endl;
	cout << "5.Поиск элемента" << endl;
	cout << "6.Сортировка" << endl;
	cout << "7.Вывод количества повторяющихся элементов" << endl;
	cout << endl;
	while (true)
	{
		cin >> v;
		switch (v)
		{
		case 1:
		{
			Fill(arr, size);
			break;
		}
		case 2:
		{
			add(arr, size);
			break;
		}
		case 3:
		{
			del(arr, size);
			break;
		}
		case 4:
		{
			cout << "Массив" << endl;
			for (int i = 0; i < size; i++)
			{
				cout << i << ":  " << "\t" << arr[i] << endl;
			}
			break;
		}
		case 5:
		{
			Find(size, arr);
			break;
		}
		case 6:
		{
			quickSort(arr, 0, size - 1);
			cout << "Кол-во операций сравнения: " << numcomp << "\n";
			cout << "Кол-во операций перестановки: " << numreshuffle << "\n";
			break;
		}
		case 7:
		{
			count(arr, size);
			break;
		}
		default:
		{
			cout << "Значение должно быть от 1 до 8!" << endl;
		}
		}
	}
		return 0;

}