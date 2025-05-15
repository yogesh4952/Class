#include <stdio.h>
#include <math.h>
#define ERROR 0.000001

double f(double x)
{
    return x * x - 4 * x - 10;
}

double df(double x)
{
    return 2 * x - 4;
}

double NR(double x0)
{
    double x1 = x0 - (f(x0) / df(x0));

    double err = fabs(x1 - x0);

    double ans = __INT_MAX__;
    while (err > ERROR)
    {
        x0 = x1;
        x1 = x1 - (f(x1) / df(x1));
        err = fabs(x1 - x0);
        ans = x1;
    }

    return ans;
}

int main()
{
    double ans = NR(-2);
    printf("%.6lf\n", ans);
    return 0;
}