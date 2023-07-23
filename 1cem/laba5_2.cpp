#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	cout << "Введите n: "; cin >> n;

	if (n < 0) {

		cout << "Не может быть отрицательным";
		
		return 0;

	}

	if (n < 3) {


		cout << "Количество строк должно быть больше 3";
		return 0;
	}

	cout << "Введите m: "; cin >> m;
	

	if (m < 3) {


		cout << "Количество столбцов должно быть больше 3";
		return 0;
	}

	if (m < 0) {

		cout << "Не может быть отрицательным";
		return 0;

	}

	int** matr = new int* [n];

	for (int i = 0; i < n; i++) {
		matr[i] = new int[m];
	}

	int ch;
	cout << "1 - Руками, 2 - Рандом: ";
	cin >> ch;

	if (ch == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << "matr[" << i << "][" << j << "] = ";
				cin >> matr[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < m; i++)
		{
			matr[i] = new int[n];
			for (int j = 0; j < n; j++)
			{
				matr[i][j] = rand() % 40-20;
				
			}
			cout << "\n";
		}
	}
	cout << "Матрица:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(5) << matr[i][j];
		}
		cout << endl;
	}
	int count = 0;
	if (n > m) {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (j > 0 && j < m)
				{
					if (matr[i][j - 1]<matr[i][j] && matr[i][j + 1]>matr[i][j]) {
						count++;
					}
					
				}
			}
		}
	}
	else {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (j > 0 && j < m)
				{
					if (matr[i][j - 1]<matr[i][j] && matr[i][j + 1]>matr[i][j]) {
						count++;
					}

				}
			}
		}
	}

	cout << "Количество элементов равно = " << count;
	cout << endl;


	return 0;
}