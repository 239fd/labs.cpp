#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    // Здесь определите вашу функцию f(x)
    return pow(sin(x), 2.) - 3 * cos(x);
}

double calculateDerivative(double x) {
    return sin(2 * x) + 3 * sin(x);
}

// Метод Ньютона (MN)
double newtonMethod(double (*f)(double), double x0, double epsilon, int maxIterations) {
    double x = x0;
    double prevX;
    int iterations = 0;
    double step = 0.1;
    do {
        prevX = x;
        x = prevX - f(prevX) / calculateDerivative(prevX);
        iterations++;
    } while (abs(x - prevX) > epsilon && iterations < maxIterations);

    return x;
}

// Метод секущих (MS)
double secantMethod(double (*f)(double), double x0, double x1, double epsilon, int maxIterations) {
    double x = x1;
    double prevX = x0;
    int iterations = 0;
    do {
        double temp = x;
        x = x - f(x) * (x - prevX) / (f(x) - f(prevX));
        prevX = temp;
        iterations++;
    } while (abs(x - prevX) > epsilon && iterations < maxIterations);

    return x;
}

// Метод простой итерации (MI)
double mi(double a, double b, double eps)
{   // Метод хорд
    double w, x = (a + b) / 2;
    do
    {
        w = x;
        x = (b * f(a) - a * f(b)) / (f(a) - f(b));
        if (f(a) * f(x) < 0) b = x;
        else a = x;
    } while (fabs(x - w) > eps);
    return x;
}

// Метод Вегстейна (MV)
double vegsteinMethod(double (*f)(double), double x0, double x1, double epsilon, int maxIterations) {
    double x = x1;
    double prevX = x0;
    int iterations = 0;
    do {
        double temp = x;
        x = x - f(x) * (x - prevX) / (f(x) - f(prevX));
        prevX = temp;
        iterations++;
    } while (abs(x - prevX) > epsilon && iterations < maxIterations);

    return x;
}

// Метод парабол (MP)
double parabolicMethod(double (*f)(double), double x0, double x2, double eps)
{
    double x1 = (x0 + x2) / 2, f0 = f(x0), f1 = f(x1), f2 = f(x2);
    double z0, z1, xm, zm1, zm2, a, b, c, w;
    do
    {
        z0 = x0 - x2;
        z1 = x1 - x2;
        c = f2;
        a = ((f0 - f2) / z0 - (f1 - f2) / z1) / (z0 - z1);
        b = (f0 - f2) / z0 - a * z0;
        w = sqrt(b * b - 4 * a * c);
        zm1 = (-b + w) / (2 * a);
        zm2 = (-b - w) / (2 * a);
        xm = (fabs(zm1) < fabs(zm2)) ? x2 + zm1 : x2 + zm2;
        if (fabs(xm - x1) < eps)
            break;
        if (xm < x1)
        {
            x2 = x1;
            f2 = f1;
        }
        else
        {
            x0 = x1;
            f0 = f1;
        }
        x1 = xm;
        f1 = f(xm);
    } while (true);
    return xm;
}



// Метод деления пополам
double md(double a, double b, double eps) {
    double x;
    do
    {
        x = (a + b) / 2;
        if (f(a) * f(x) < 0) b = x;
        else a = x;
    } while (fabs(b - a) > 2 * eps);
    return (a + b) / 2;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double a; // Левый конец интервала
    double b; // Правый конец интервала
    cout << "Введите a:" << endl;
    cin >> a;
    cout << "Введите b:" << endl;
    cin >> b;
    double h = 0.001;
    double epsilon = 1e-6; // Точность
    int maxIterations = 100;
    int method;
    int n = 0;
    // Найденные корни будут храниться в массиве
    double roots[100]; // Предполагаем, что будет не более 100 корней
    int numRoots = 0;
    double step = 0.1; // Шаг для проверки значений функции
    while (true) {
        cout << "Выберите действие:" << endl;
        cout << "1. MD" << endl;
        cout << "2. MI" << endl;
        cout << "3. MN" << endl;
        cout << "4. MS" << endl;
        cout << "5. MV" << endl;
        cout << "6. MP" << endl;
        cout << "0. Выход" << endl;
        cin >> method;
        // Проверяем значения функции на интервале и находим корни
        double x = a;
        while (x < b) {
            if (f(x) * f(x + step) < 0) {
                // Найден потенциальный корень
                double root;
                switch (method) {
                case 1: {
                    for (x = a; x <= b; x += h)
                        if (f(x) * f(x + h) < 0) {
                            n++;
                            cout << "Корень " << n << ": " << md(x, x + h, epsilon) << endl;
                        }
                    cout << endl;
                    continue;
                }
                case 2: {
                    for (x = a; x <= b; x += h)
                        if (f(x) * f(x + h) < 0) {
                            n++;
                            cout << "Корень " << n << ": " << mi(x, x + h, epsilon) << endl;
                        }
                    cout << endl;
                    continue;
                }
                case 3:
                    root = newtonMethod(f, x, epsilon, maxIterations);
                    break;
                case 4:
                    root = secantMethod(f, x, x + step, epsilon, maxIterations);
                    break;
                case 5:
                    root = vegsteinMethod(f, x, x + step, epsilon, maxIterations);
                    break;
                case 6:
                    root = parabolicMethod(f, x, x + step, epsilon);;
                    break;
                case 0:
                    cout << "Выход из программы..." << endl;
                    return 0;
                default:
                    cout << "Ошибка: недопустимый метод." << endl;
                    return 1;
                }
                roots[numRoots] = root;
                numRoots++;
            }
            x += step;
        }
        // Выводим найденные корни
        if (numRoots != 0) {
            cout << "Найденные корни:" << endl;
            for (int i = 0; i < numRoots; i++) {
                cout << "Корень " << i + 1 << ": " << roots[i] << endl;
            }
            numRoots = 0;
            cout << endl;
        }

    }
}