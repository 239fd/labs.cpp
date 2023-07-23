#include <iostream>

using namespace std;

double CalculatingYn(long int n) {
    if (n <= 1) {
        return 1 / 1.5;
    }
    else if (n % 2 == 0) {
        return 1 / (n + CalculatingYn(n - 2));
    }
    else if (n % 2 != 0) {
        n = n - 1;
        return 1 / (n + CalculatingYn(n - 2));
    }
}   

double CalculatingYn2(long int n) {
    double res = 1.5;

    for (int i = 0; i <= n; i=i+2)
    {
        res = 1.0 / (i + res);
    }

    return(res);

}

int main()
{
    long int n;

    cout << "Enter n: ";
    cin >> n;
    if (n < 2) {
        cout << "It's impossible to calculate.";
        return 0;
    }


    cout << "func y(n) = " << CalculatingYn2(n) << endl;
    cout << "rec y(n) = " << CalculatingYn(n) << endl;


    return 0;
}

    //else if (n % 2 == 0) {
    //    for (int i = 1; i <= n; i = i + 2)
    //    {
    //        res = 1.0 / (i + res);
    //    }
    //
    //}
    //else if (n % 2 != 0) {
    //    n = n - 1;
    //    for (int i = 1; i <= n; i = i + 2)
    //    {
    //        res = 1.0 / (i + res);
    //    }
    //}