#include <iostream>
#include <cmath>

double function(double x)
{
    return pow(x, 3) + 6 * x * x - 0.02 * exp(x) - 14;
}

double parabolicMethod(double a, double b, double epsilon)
{
    double x1, x2, x3;
    double f1, f2, f3;
    double f;  // Переменная f объявлена перед циклом

    do
    {
        x1 = a;
        x2 = (a + b) / 2;
        x3 = b;

        f1 = function(x1);
        f2 = function(x2);
        f3 = function(x3);

        double numerator = f2 * (x1 * x1 - x3 * x3) + f1 * (x3 * x3 - x2 * x2) + f3 * (x2 * x2 - x1 * x1);
        double denominator = 2 * (f2 * (x1 - x3) + f1 * (x3 - x2) + f3 * (x2 - x1));

        double x = numerator / denominator;
        f = function(x);  // Значение функции f обновляется на каждой итерации

        if (f * f1 < 0)
            b = x;
        else
            a = x;

    } while (fabs(f) > epsilon);

    return (a + b) / 2;
}

int main()
{
    double a = -6.0;
    double b = 2.0;
    double epsilon = 0.0001;

    double root = parabolicMethod(a, b, epsilon);

    std::cout << "Root: " << root << std::endl;

    return 0;
}
