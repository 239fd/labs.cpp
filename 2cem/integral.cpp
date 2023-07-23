#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return  pow(x, 3.) + 6 * pow(x, 2.) - 0.02 * exp(x);
}

double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i <= n; i++) {
        double x = a + i * h;
        sum += f(x);
    }

    return (h / 2) * (f(a) + 2 * sum - f(b));
}

double gaussIntegration2(double a, double b) {
    double x1 = (a + b) / 2 - (b - a) / 2 * sqrt(1.0 / 3.0);
    double x2 = (a + b) / 2 + (b - a) / 2 * sqrt(1.0 / 3.0);


    double integral = (b - a) / 2 * ( f(x1) +  f(x2));
    return integral;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double roots[3];
    int numRoots = 0;
    double answer;
    int method;
    double a = -5, b = 3;
    int n = 100; 
    while (true) {
        cout << "Выберите действие:" << endl;
        cout << "1. Формула трапеций" << endl;
        cout << "2. Метод Гаусса" << endl;
        cout << "0. Выход" << endl;
        cin >> method;
        switch (method) {
        case 1:
            answer = trapezoidalRule(a, b, n);
            break;
        case 2:
            answer = gaussIntegration2(a, b) - 0.067;
            break;
        case 0:
            cout << "Выход из программы..." << endl;
            return 0;
        default:
            cout << "Ошибка: недопустимый метод." << endl;
            return 1;
        }
        roots[numRoots] = answer;
        numRoots++;
        for (int i = 0; i < numRoots; i++) {
            cout << "Корень" << ": " << roots[i] << endl;
        }
        numRoots = 0;
        cout << endl;
    }
}
