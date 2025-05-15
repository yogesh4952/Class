#include <stdio.h>
#include <math.h>
#define ERROR 0.00001

double f(double x)
{
    return x * x - 4 * x - 10;
}

double realRoot(double x0, double x1)
{
    double err = fabs(x0 - x1);
    double ans = __INT_MAX__;

    while (err > ERROR)
    {
        double mid = (x1 + x0) / 2;
        double f1 = f(x0);
        double f2 = f(mid);
        if ((f1 * f2) > 0)
        {
            x0 = mid;
            x1 = x1;
        }
        else if ((f1 * f2) < 0)
        {
            x0 = x0;
            x1 = mid;
        }
        else
        {
            return mid;
        }
        err = fabs(x0 - x1);
        ans = mid;
    }

    return ans;
}

int main()
{
    double ans = realRoot(-2, -1);
    printf("%.5lf\n", ans);
    return 0;
}