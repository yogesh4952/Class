#include <stdio.h>
#include <math.h>

double f(double x)
{
    return exp(x);
}

double trapeZoidal(double a, double b, double n)
{
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 1; i < n; i++)
    { // Corrected: i < n to include i = 1 to n-1
        double x = a + h * i;
        sum += 2 * f(x);
    }
    sum = f(a) + f(b) + sum;
    double ans = sum * (h / 2);
    return ans;
}

int main()
{
    printf("%.5lf\n", f(3.8));
    double ans = trapeZoidal(1.6, 3.8, 22);
    printf("%.5lf\n", ans);
    return 0;
}