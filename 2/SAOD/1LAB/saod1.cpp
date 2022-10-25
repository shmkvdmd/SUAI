#include <iostream>
using namespace std;

int count_chet(int* arr_1, int x)
{
	int count = 0;
	for (int i = 0; i < x; i++)
	{
		if ((arr_1[i] % 2) != 0)
		{
			count++;
		}
	}
	cout << "Кол-во нечетных элементов = " << count << endl;
	return count;
}
void chet_div(int* arr_2, int y)
{
	cout << "[" << y << "] = " << arr_2[y] << endl;
}


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размер массива ";
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % n - ((n / 2) - 1);
		cout << "[" << i << "] = " << arr[i] << endl;
	}
	bool tr = true;
	int opt;
	while (tr)
	{
		cout << "\nВведите 1, если хотите подсчитать кол-во нечетных элементов. \n";
		cout << "Введите 2, если хотите уменьшить четные элементы массива в два раза. \n";
		cout << "Введите 3, если хотите выйти. \n";
		cout << "Ввод: ";
		cin >> opt;
		switch (opt)
		{
		case (1):
			count_chet(arr, n);
			break;
		case (2):
			cout << "Четные элементы уменьшенные в два раза: \n";
			for (int i = 0; i < n; i++)
			{
				if ((arr[i] % 2) == 0)
				{
					arr[i] = arr[i] / 2;
					chet_div(arr, i);
				}
			}
			break;
		case (3):
			tr = false;
			break;
		}
	}
	delete[]arr;
	return 0;
}
