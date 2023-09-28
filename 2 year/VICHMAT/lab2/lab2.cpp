#include <iostream>
#include <vector>
using namespace std;

//функция, вычисляющая обратную матрицу
const double stroka = 4;
const double stolbec = 4;
void invers(vector<vector<double>>& matrix, vector<vector<double>>& ematrix)
{
	double temp;
	for (int k = 0; k < stolbec; k++)
	{
		temp = matrix[k][k];
		for (int j = 0; j < stolbec; j++)
		{
			matrix[k][j] /= temp;
			ematrix[k][j] /= temp;
		}

		for (int i = k + 1; i < stolbec; i++)
		{
			temp = matrix[i][k];
			for (int j = 0; j < stolbec; j++)
			{
				matrix[i][j] -= matrix[k][j] * temp;
				ematrix[i][j] -= ematrix[k][j] * temp;
			}
		}
	}

	for (int k = stolbec - 1; k > 0; k--)
	{
		for (int i = k - 1; i >= 0; i--)
		{
			temp = matrix[i][k];

			for (int j = 0; j < stolbec; j++)
			{
				matrix[i][j] -= matrix[k][j] * temp;
				ematrix[i][j] -= ematrix[k][j] * temp;
			}
		}
	}
}

// функция, перемножающая матрицу A на вектор B
void multi(vector<vector<double>>& matrix, vector<double>& matrixb, vector<double>& xmatrix)
{
	for (int i = 0; i < stolbec; i++)
		for (int j = 0; j < stolbec; j++)
			xmatrix[i] += (matrix[i][j] * matrixb[j]);
}

int main()
{
	setlocale(LC_ALL, "ru");
	double value;
	vector<vector <double>> matrix(stroka, vector<double>(stolbec));
	vector<vector <double>> ematrix(stroka, vector<double>(stolbec));
	vector <double> matrixb(4);
	vector <double> check(4);
	vector <double> xmatrix(4);
	xmatrix = { 0 };
	for (int i = 0; i < stroka; i++)
	{
		for (int j = 0; j < stolbec; j++)
		{
			cout << "Введите элемент для " << i + 1 << " строки и " << j + 1 << " столбца: ";
			cin >> value;
			matrix[i][j] = value;
		}
	}

	cout << "Матрица А = \n";
	for (int i = 0; i < stroka; i++)
	{
		cout << "| ";
		for (int j = 0; j < stolbec; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << " | \n";
	}
	for (int i = 0; i < stroka; i++)
	{

		cout << "Введите элемент для " << 1 << " строки и " << i + 1 << " столбца: ";
		cin >> value;
		matrixb[i] = value;

	}
	cout << "Матрица B = \n";
	for (int i = 0; i < stroka; i++)
	{
		cout << "| ";
		cout << matrixb[i];
		cout << " |" << endl;
	}

	ematrix = {
				  { 1, 0, 0, 0 },
				  { 0, 1, 0, 0 },
				  { 0, 0, 1, 0 },
				  { 0, 0, 0, 1 }
	}; // единичная матрица
	xmatrix = { 0,0,0,0 };
	invers(matrix, ematrix); // находим обратную матрицу A^-1
	multi(ematrix, matrixb, xmatrix); // перемножаем обратную матрицу A^-1 на вектор B
	for (int i = 0; i < stroka; i++)
		cout << "X[" << i << "] = " << xmatrix[i] << endl;
	cout << "\nПроверка подстановкой(сначала найденный ответ, потом матрица B)\n";
	invers(ematrix, matrix);
	for (int i = 0; i < stroka; i++)
	{
		double answer = 0;
		for (int j = 0; j < stolbec; j++)
		{
			answer += matrix[i][j] * xmatrix[j];
		}
		cout << answer << " | " << matrixb[i] << endl;
	}
	system("pause");
	return 0;
}