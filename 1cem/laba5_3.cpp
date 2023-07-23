#include <iostream>
#include <iomanip>

using namespace std;


bool algorithm(double x, double y) {
    return (x > y);
}


int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    double** a;
    cout << "Введите n: ";
    cin >> n;
    if (n < 0) {

        cout << "Не может быть отрицательным";
        return 0;

    }

    if (n < 2) {
        cout << "Ошибка";
        return 0;
    }
    int** b;

    
    b = new int* [n];
    for (int i = 0; i < n; i++) {
        b[i] = new int[n];
    }

    
    a = new double* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new double[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "mtrx[" << i << "]" << "[" << j << "]: ";
            cin >> a[i][j];
        }
    } 
    cout << "Матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }

    cout << "--------------------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (algorithm(a[i][j], a[j][j])) {
                b[i][j] = 1;
            }
            else
            {
                b[i][j] = 0;
            }

            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}