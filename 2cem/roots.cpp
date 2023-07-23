#include <iostream>
#include <cmath>

double function(double x)
{
    return pow(x, 3) + 6 * x * x - 0.02 * exp(x) - 14;
}

double derivative(double x)
{
    return 3 * pow(x, 2) + 12 * x - 0.02 * exp(x);
}

void findRootss(double a, double b, double epsilon)
{
    double z1, z2, x1, x2, x3, f1, f2, f3, x0, h1;
    x0 = -6;
    h1 = 0.0001;
    
    x1 = x0 + h1;
    x2 = x0;
    x3 = x0 - h1;

    f1 = function(x1);
    f2 = function(x2);
    f3 = function(x3);
    
    double q, r, p, q1, tz, xm;

    for (int i = 0; i < 100; i++) {

        z1 = x1 - x3;

        x2 = x2 - x3;

        q = (((f1 - f3) * (x2 - x3) * (x2 - x3)) - ((f2 - f3) * (x1 - x2) * (x1 - x2))) / ((x1 - x3) * (x2 - x3) * (x2 - x1));

        p = ((f1 - f3) * (x2 - x3) - (f2 - f3) * (x1 - x3)) / ((x1 - x3) * (x2 - x3) * (x1 - x2));

        r = f3;

        q1 = q * q - 4 * p * r;

        z1 = (-q + pow(q1, 0.5)) / (2 * p);
        z2 = (-q - pow(q1, 0.5)) / (2 * p);

        tz = z1;

        x1 = x2;

        x2 = x3;

        f1 = f2;

        f2 = f3;

        x3 = x3 + tz;

        f3 = function(x3);

        std::cout << x3;

    }
 
}

void findRootsss(double a, double b, double epsilon)
{
        const int maxIterations = 100;
        int rootCount = 0;

        std::cout << "Roots: " << std::endl;

        double fa = function(a);
        double fb = function(b);

        if (fabs(fa) < epsilon)
        {
            std::cout << a << std::endl;
            rootCount++;
        }

        if (fabs(fb) < epsilon)
        {
            std::cout << b << std::endl;
            rootCount++;
        }

        if (fa * fb > 0)
        {
            std::cout << "No roots found on the given interval." << std::endl;
            return;
        }

        for (int i = 0; i < maxIterations; ++i)
        {
            double c = (a * fb - b * fa) / (fb - fa);
            double fc = function(c);

            if (fabs(fc) < epsilon)
            {
                std::cout << c << std::endl;
                rootCount++;
            }

            if (fa * fc < 0)
            {
                b = c;
                fb = fc;
            }
            else
            {
                a = c;
                fa = fc;
            }

            if (fabs(b - a) < epsilon)
            {
                break;
            }
        }

        if (rootCount == 0)
        {
            std::cout << "No roots found within the specified epsilon." << std::endl;
        }
    
}

void findRoots(double a, double b, double epsilon)
{
    const int maxIterations = 100;
    bool signChange = false;

    std::cout << "Roots: " << std::endl;

    for (double x = a; x <= b; x += epsilon)
    {
        double f = function(x);

        if (f * function(x + epsilon) < 0)
        {
            signChange = true;
            double left = x;
            double right = x + epsilon;

            for (int i = 0; i < maxIterations; ++i)
            {
                double mid = (left + right) / 2;
                double fmid = function(mid);

                if (fabs(fmid) < epsilon)
                {
                    std::cout << mid << std::endl;
                    break;
                }
                else if (fmid * f < 0)
                {
                    right = mid;
                }
                else
                {
                    left = mid;
                }
            }
        }
        else if (signChange)
        {
            signChange = false;
        }
    }
}

void Interval(double& a, double& b, double h) {
    while (function(a) * function(a + h) > 0) {
        a += h;
    }
    b = a + h;
}

void findRootz(double a, double b, double h, double e) {
    double y0 = function(a);
    double y1 = function(b);
    while (b - a > e) {
        double x = (a + b) / 2;
        double y2 = function(x);
        if (y0 * y2 > 0) {
            a = x;
            y0 = y2;
        }
        else {
            b = x;
            y1 = y2;
        }
    }
    std::cout << (a + b) / 2 << std::endl;
}


int main()
{
    std::cout << "func: y = pow(x, 3) + 6 * x * x - 0.02 * exp(x) - 14 " << std::endl;
    int choice = 0;
    int t = 1;
    int l = 0;
    double a, b, epsilon,h;
    double x0, h1;
    while (t == 1) {

        std::cout << "1.MP" << std::endl;
        std::cout << "2.MD" << std::endl;
        std::cout << "3.Exit" << std::endl;
        std::cout << "Choice the method: ";
        std::cin >> choice; 

        switch (choice) {

        case 1:
            a = -6;
            b = 2;
            epsilon = 0.001;
            findRoots(a, b, epsilon);

            break;

        case 2:
            a = -6;
            b = 2;
            h = 0.001;
            epsilon = 0.0001;

            while (l != 3) {
                Interval(a, b, 0.000101);
                findRootz(a, b, h, epsilon);
                a += 0.1;
                l++;
            }

            break;

        default:
            t = 2;
            break;
        }

    }
   
}
