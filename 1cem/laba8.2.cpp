#include <math.h>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int n;
double check()
{
    bool fk = true;
    int n = 0;
    string a = "\0";
    string b = "\0";


    while (fk == true) {

        cin >> b;
        a = b;
        if (a[0] == '0' && a[1] != '.') {
            a[0] = a[1] = '.';
        }
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == '.' || a[i] == ',') {
                a[i] = '0';
                n++;

            }
        }if (a[0] == '-' && isdigit(a[1]) && a[1] != '0') {
            a[0] = a[1] = a[2] = '0';
            n++;
        }
        for (int s = 0; s < a.length(); s++) {
            if (isdigit(a[s]) && n < 2 && a[0] != '.' && a[0] != ',') {
                fk = false;
            }
            else {
                cout << "Error, try again" << endl;
                fk = true;
                n = 0;
                break;
            }
        }




    }
    return stod(b);

}

double a1()
{
    double n;
    do {

        n = check();
        if (n - (int)n == 0 && !(n <= 0))
        {
            break;
        }
        else {
            cout << "Try again" << endl;
        }
    } while (true);
    return n;
}

int factorial(int k)
{
    if (k == 0 || k == 1)
    {
        return 1;
    }
    int f = 1;
    for (int i = 2; i <= k; i++)
    {
        f *= i;
    }
    return f;
}


 
{   
    double s = 0;
    for (int k = 0; k <= n; k++)
    {
        s += (k * k + 1) * pow(0.5 * x, k) / factorial(k);
    }
    return s;
}


double Y(double x)
{
    double y = (x * x / 4 + x / 2 + 1) * exp(0.5 * x);
    return y;
}

double S_Y(double x)
{
    return abs(Y(x) - S(x));
}

void Out_Rez(double f(double), double a, double b, double h) {

    for (double x = a; x <= b; x += h) {

        cout << "x = " << x << endl;
        cout << "Result = " << f(x) << endl;

    }

}


int main()
{
    int m;
    double a, b, h;
    cout << "Enter a: ";
    a = check();
    cout << "Enter b: ";
    b = check();
    cout << "Enter h: ";
    h = check();
    cout << "Enter n: ";
    n = a1();
    cout << "What do you want to check?" << endl << "1: S(x)" << endl << "2: Y(x)" << endl << "3: |S(x) - Y(x)|" << endl;
    while (true)
    {
        m = a1();
        if (m == 1 || m == 2 || m == 3)
        {
            break;
        }
        cout << "Try again" << endl;
    }
    if (m == 1)
    {
        cout << "S(x) " << endl;
        Out_Rez(S, a, b, h);
    }
    else if (m == 2)
    {
        cout << "Y(x) " << endl;
        Out_Rez(Y, a, b, h);
    }
    else if (m == 3)
    {
        cout << "|S(x) - Y(x)" << endl;
        Out_Rez(S_Y, a, b, h);
    }
}
