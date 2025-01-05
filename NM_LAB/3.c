#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * exp(x) - cos(x);
}

double g(double x)
{
    return x * exp(x) + exp(x) + sin(x);
}

#define e 0.000001

int main()
{
    double x0, x1, f1, df0, f0;
    int i = 0;

    printf("Enter the initial guess: ");
    scanf("%lf", &x0);

    do
    {
        f0 = f(x0);
        df0 = g(x0);
        x1 = x0 - (f0 / df0);
        f1 = f(x1);
        i++;

        printf("Iteration %d : x = %lf, f(x) = %lf\n", i, x1, f1);

        x0 = x1;

    } while (fabs(f1) > e);

    printf("The real root is: %lf", x1);
}